#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z;
    int a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if ((a < x) || ((a + b) < (x + y)) || ((a + b + c) < (x + y + z)))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}