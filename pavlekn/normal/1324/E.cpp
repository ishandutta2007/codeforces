#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 7;

int dp[MAXN][MAXN];

const int INF = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < h; ++i)
    {
        dp[0][i] = -INF;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < h; ++j)
        {
            dp[i + 1][j] = -INF;
        }
        for (int j = 0; j < h; ++j)
        {
            dp[i + 1][(j + a[i]) % h] = max(dp[i + 1][(j + a[i]) % h], dp[i][j]);
            dp[i + 1][(j + a[i] + h - 1) % h] = max(dp[i + 1][(j + a[i] + h - 1) % h], dp[i][j]);
        }
        for (int j = l; j <= r; ++j)
        {
            dp[i + 1][j]++;
        }
    }
    int ans = 0;
    for (int j = 0; j < h; ++j)
    {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << endl;
    return 0;
}