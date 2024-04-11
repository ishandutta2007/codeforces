#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

int32_t main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    vector<int> a(n);
    int ans = 0;
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i % m == j)
            {
                a[i] = b[i] - k;
            }
            else
            {
                a[i] = b[i];
            }
        }
        vector<int> pr(n + 1);
        pr[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            pr[i] = pr[i - 1] + a[i - 1];
        }
        int mn = INF;
        for (int i = 1; i <= n; ++i)
        {
            if ((i - 1) % m == j)
            {
                mn = min(mn, pr[i - 1]);
            }
            ans = max(ans, pr[i] - mn);
        }
    }
    cout << ans << endl;
    return 0;
}