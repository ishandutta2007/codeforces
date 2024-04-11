#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9 + 77;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, m, k;
        cin >> n >> m >> k;
        k = min(k, m - 1);
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> b;
        int ans = 0;
        for (int i = 0; i <= k; ++i)
        {
            int cur = INF;
            for (int j = 0; j <= (m - 1 - k); ++j)
            {
                cur = min(cur, max(a[i + j], a[n - m + i + j]));
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}