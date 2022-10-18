#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

int solve()
{
    ld a, b, c;
    if (!(cin >> a))
        return 1;
    cin >> b >> c;
    ld x, y, X, Y;
    cin >> x >> y >> X >> Y;
    ld ans = abs(x - X) + abs(y - Y);
    if (a && b)
    {
        ld y0 = (-a * x - c) / b;
        ld yy = (-a * X - c) / b;
        ld x0 = (-b * y - c) / a;
        ld xx = (-b * Y - c) / a;
        ans = min(ans, abs(y - y0) + sqrt((y0 - yy) * (y0 - yy) + (X - x) * (X - x)) + abs(Y - yy));
        ans = min(ans, abs(y - y0) + sqrt((y0 - Y) * (y0 - Y) + (x - xx) * (x - xx)) + abs(X - xx));
        ans = min(ans, abs(x - x0) + sqrt((x0 - xx) * (x0 - xx) + (Y - y) * (Y - y)) + abs(X - xx));
        ans = min(ans, abs(x - x0) + sqrt((x0 - X) * (x0 - X) + (y - yy) * (y - yy)) + abs(Y - yy));
    }
    cout << fixed << setprecision(30);
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}