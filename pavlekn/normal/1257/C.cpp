#include <bits/stdc++.h>

using namespace std;

#define int long long

#pragma GCC optimize("-O3")

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
        map<int, int> pos;
        int ans = n + 1;
        for (int i = 0; i < n; ++i)
        {
            if (pos[a[i]])
            {
                ans = min(ans, i + 2 - pos[a[i]]);
            }
            pos[a[i]] = i + 1;
        }
        if (ans > n)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}