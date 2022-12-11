#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18 + 11;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, k;
        cin >> n >> k;
        --k;
        vector<int> a(n);
        int mx = -INF;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        int m = -INF;
        for (int i = 0; i < n; ++i)
        {
            a[i] = mx - a[i];
            m = max(m, a[i]);
        }
        if (k % 2ll)
        {
            for (auto el : a)
            {
                cout << (m - el) << " ";
            }
            cout << endl;
        }
        else
        {
            for (auto el : a)
            {
                cout << (el) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}