#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;

int a[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, u, v;
        cin >> n >> u >> v;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int fl = true;
        int ans = -1;
        for (int i = 1; i < n; ++i)
        {
            if (abs(a[i] - a[i - 1]) >= 2)
            {
                ans = 0;
            }
            if (abs(a[i] - a[i - 1]) == 1)
            {
                fl = false;
            }
        }
        if (ans == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (fl)
        {
            cout << min(u, v) + v << endl;
        }
        else
        {
            cout << min(u, v) << endl;
        }
    }
    return 0;
}