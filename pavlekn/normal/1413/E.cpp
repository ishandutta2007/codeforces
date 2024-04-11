#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e6 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b * c)
        {
            cout << -1 << endl;
            continue;
        }
        int l = 0;
        int r = INF;
        while (r - l > 1)
        {
            int med = (l + r) / 2;
            if (d * med >= c)
            {
                r = med;
                continue;
            }
            if (d * med * b < a)
            {
                l = med;
            }
            else
            {
                r = med;
            }
        }
        int ans = (l * (l + 1) / 2ll) * d * b - (l + 1) * a;
        cout << -ans << endl;
    }
    return 0;
}