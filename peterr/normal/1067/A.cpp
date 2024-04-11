#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1E5;
const int MAXA = 200;
int arr[MAXN];
int dp[MAXN][MAXA + 1][2];
int pre[MAXN][MAXA + 1][2];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (arr[0] == -1)
    {
        for (int i = 1; i <= MAXA; i++)
        {
            dp[0][i][0] = 1;
        }
    }
    else
    {
        dp[0][arr[0]][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= MAXA; j++)
        {
            pre[i - 1][j][0] = (dp[i - 1][j][0] + pre[i - 1][j - 1][0]) % MOD;
            pre[i - 1][j][1] = (dp[i - 1][j][1] + pre[i - 1][j - 1][1]) % MOD;
        }
        for (int j = 1; j <= MAXA; j++)
        {
            if (arr[i] == -1 || arr[i] == j)
            {
                dp[i][j][0] = (dp[i][j][0] + pre[i - 1][j - 1][0]) % MOD;
                dp[i][j][0] = (dp[i][j][0] + pre[i - 1][j - 1][1]) % MOD;
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0]) % MOD;
                dp[i][j][1] = (dp[i][j][1] + pre[i - 1][MAXA][1]) % MOD;
                dp[i][j][1] = (dp[i][j][1] - pre[i - 1][j - 1][1] + MOD) % MOD;
                /*
                for (int k = 1; k < j; k++)
                {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][0]) % MOD;
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][1]) % MOD;
                }
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0]) % MOD;
                for (int k = j; k <= MAXA; k++)
                {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][1]) % MOD;
                }
                */
            }
            /*
            cout << i << " " << j << " " << 0 << " " << dp[i][j][0] << endl;
            cout << i << " " << j << " " << 1 << " " << dp[i][j][1] << endl;
            */
        }
    }
    int ans = 0;
    for (int i = 1; i <= MAXA; i++)
        ans = (ans + dp[n - 1][i][1]) % MOD;
    cout << ans << endl;
    return 0;
}