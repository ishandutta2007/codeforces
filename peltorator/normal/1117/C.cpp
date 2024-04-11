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

map<char, int> dx, dy;

int solve()
{
    ll x;
    if (!(cin >> x))
        return 1;
    ll y;
    cin >> y;
    ll xx, yy;
    cin >> xx >> yy;
    int n;
    cin >> n;
    string s;
    cin >> s;
    dx['U'] = dx['D'] = dy['L'] = dy['R'] = 0;
    dy['U'] = dx['R'] = 1;
    dy['D'] = dx['L'] = -1;
    vector<int> cx(n + 1, 0), cy(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cx[i + 1] = cx[i] + dx[s[i]];
        cy[i + 1] = cy[i] + dy[s[i]];
    }
    ll l = 0, r = 2e15;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2LL;
        ll c = mid / n;
        ll k = mid % n;
        ll gox = c * cx[n] + cx[k];
        ll goy = c * cy[n] + cy[k];
        if (abs(x + gox - xx) + abs(y + goy - yy) <= mid)
            r = mid;
        else
            l = mid;
    }
    if (r > 1e15)
        cout << -1 << endl;
    else
        cout << r << endl;
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