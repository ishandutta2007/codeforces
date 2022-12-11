#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int dp[MAXN];
int t[MAXN];
int x[MAXN];
int y[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int r, n;
    cin >> r >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
        --x[i + 1];
        --y[i + 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = -MAXN;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j >= 0 && i - j <= (4 * r); --j)
        {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j] && dp[j] >= 0)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}