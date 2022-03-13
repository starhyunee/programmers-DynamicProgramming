#include <string>
#include <vector>
#include<algorithm>

using namespace std;

/* 프로그래머스 고득점 kit - 정수 삼각형 */
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();

    vector<vector<int>>dp(size);
    for (int i = 0; i < size; i++) {
        dp.back().push_back(triangle.back()[i]);
    }
    for (int i = size - 1; i >= 1; i--) {
        for (int j = 0; j < size - 1; j++) {
            dp[i - 1].push_back(max(dp[i][j], dp[i][j + 1]) + triangle[i - 1][j]);
        }
    }
    answer = dp[0][0];

    return answer;
}


/* 프로그래머스 고득점 kit - 등굣길 */
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (dp[i][0] == -1)
            break;
        dp[i][0] = 1;
    }
    for (int j = 0; j < m; j++) {
        if (dp[0][j] == -1)
            break;
        dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] == -1)
                continue;
            if (dp[i - 1][j] != -1)
                dp[i][j] += dp[i - 1][j];
            if (dp[i][j - 1] != -1)
                dp[i][j] += dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }
    return dp[n - 1][m - 1];
}