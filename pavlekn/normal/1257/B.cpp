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
        int x, y;
        cin >> x >> y;
        if (x <= 3 && y > 3 || x <= 1 && y > x)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}