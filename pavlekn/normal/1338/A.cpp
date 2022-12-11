#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int mx = a[0];
        int d = 0;
        for (int i = 1; i < n; ++i)
        {
            if (mx - a[i] > d)
            {
                d = mx - a[i];
            }
            mx = max(mx, a[i]);
        }
        int cnt = 0;
        int cur = 0;
        while (cur < d)
        {
            cur += (1ll << cnt);
            ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}