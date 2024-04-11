#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int u, v;
        cin >> u >> v;
        int a = 0;
        int b = 0;
        string ans = "YES";
        if (u > v)
        {
            ans = "NO";
        }
        for (int i = 0; i < 30; ++i)
        {
            if (u & (1 << i))
            {
                ++a;
            }
            if (v & (1 << i))
            {
                ++b;
            }
            if (b > a)
            {
                ans = "NO";
            }
        }
        cout << ans << endl;
    }
    return 0;
}