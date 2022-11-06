#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        c1 -= a;
        c2 -= b;
        c3 -= c;
        d -= min(d, max(0, c1));
        e -= min(e, max(0, c2));
        if (c1 >= 0 && c2 >= 0 && c3 >= 0 && d + e <= c3)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}