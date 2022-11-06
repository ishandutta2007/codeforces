#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1E9 + 7;
const int MAXN = 100000;
int dp[MAXN + 1][2];

int main()
{
    int n, m;
    cin >> n >> m;
    dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        dp[i][0] = (dp[i - 1][1] + dp[i - 2][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 2][0]) % MOD;
    }
    int ans = dp[n][0];
    ans = (ans + dp[n][1]) % MOD;
    ans = (ans + dp[m][0]) % MOD;
    ans = (ans + dp[m][1]) % MOD;
    ans = (ans + MOD - 2) % MOD;
    cout << ans << endl;
    return 0;
}