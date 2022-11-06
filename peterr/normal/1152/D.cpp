#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1000;
int dp[MAXN+1][MAXN+1][2];

int main()
{
    int n;
    cin >> n;
    dp[1][0][1] = 1;
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;
    dp[1][1][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][i][1] = (1 + dp[i-1][i-1][0]) % MOD;
        dp[i][i][0] = dp[i-1][i-1][1];
        for (int j = i - 1; j > 0; j--)
        {
            dp[i][j][0] = (dp[i][j+1][1] + dp[i-1][j-1][1]) % MOD;
            dp[i][j][1] = (1 + dp[i][j+1][0] + dp[i-1][j-1][1]) % MOD;
        }
        dp[i][0][0] = dp[i][1][1];
        dp[i][0][1] = 1 + dp[i][1][0];
    }
    cout << max(dp[n][0][0], dp[n][0][1]);
    return 0;
}