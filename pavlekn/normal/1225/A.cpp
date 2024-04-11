#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    if (x == y)
    {
        cout << x << '0' << " " << y << '1' << endl;
    }
    else if (x + 1 == y)
    {
        cout << x << " " << y << endl;
    }
    else if (x == 9 && y == 1)
    {
        cout << "99" << " " << "100" << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}