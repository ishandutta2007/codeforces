#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int n, m;
    cin >> n >> m;
    vector<int> y(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> y[i];
    }
    y[n] = 1e9;
    sort(y.begin(), y.end());
    int x1, x2, y1;
    vector<int> a(n + 1);
    for (int i = 0; i < m; ++i)
    {
        cin >> x1 >> x2 >> y1;
        if (x1 == 1)
        {
            int l = -1;
            int r = n + 1;
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                if (y[m] <= x2)
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            if (l >= 0)
            {
                ++a[l];
            }
        }
    }
    vector<int> pr(n + 1);
    pr[n] = a[n];
    for (int i = n - 1; i >= 0; --i)
    {
        pr[i] = pr[i + 1] + a[i];
    }
    int ans = 1e9;
    for (int i = 0; i <= n; ++i)
    {
        ans = min(ans, i + pr[i]);
    }
    cout << ans << endl;
    return 0;
}