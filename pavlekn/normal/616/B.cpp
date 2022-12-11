#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

#define int long long

int a[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int mn = 1e18;
        for (int j = 0; j < m; ++j)
        {
            mn = min(mn, a[i][j]);
        }
        ans = max(ans, mn);
    }
    cout << ans << endl;
    return 0;
}