#include <bits/stdc++.h>

using namespace std;

#define int long long

#pragma GCC optimize("Ofast")

const int MAXN = 2007;

int dp[MAXN][MAXN];
int last[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int len = 1; len <= n; ++len)
    {
        for (int i = 0; i + len <= n; ++i)
        {
            if (len == 1)
            {
                dp[i][i + len] = 1;
                last[i][i + len] = a[i];
            }
            else
            {
                dp[i][i + len] = len;
                for (int j = i + 1; j < i + len; ++j)
                {
                    dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j][i + len]);
                    if (dp[i][j] == 1 && dp[j][i + len] == 1 && last[i][j] == last[j][i + len])
                    {
                        dp[i][i + len] = 1;
                        last[i][i + len] = last[i][j] + 1;
                    }
                }
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}