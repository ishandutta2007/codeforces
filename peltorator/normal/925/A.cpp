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

#define sz(a) (int)((a).size())

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

int solve()
{
    ios::sync_with_stdio(0);
    ll n;
    if (!(cin >> n))
    {
        return 1;
    }
    ll m;
    cin >> m;
    int x, y;
    cin >> x >> y;
    ll v;
    cin >> v;
    vector<ll> a(x), b(y);
    for (int i = 0; i < x; i++)
        cin >> a[i];
    for (int i = 0; i < y; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int q;
    cin >> q;
    while (q--)
    {
        ll x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        if (x == xx)
        {
            cout << abs(y - yy) << '\n';
            continue;
        }
        int l = -1, r = a.size();
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (a[mid] >= y)
                r = mid;
            else
                l = mid;
        }
        int it = r;
        ll ans = 1e18;
        if (it != a.size())
            ans = min(ans, abs(x - xx) + abs(a[it] - y) + abs(a[it] - yy));
        if (it > 0)
        {
            it--;
            ans = min(ans, abs(x - xx) + abs(a[it] - y) + abs(a[it] - yy));
        }
        l = -1;
        r = b.size();
         while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (b[mid] >= y)
                r = mid;
            else
                l = mid;
        }
        it = r;
        if (it != b.size())
            ans = min(ans, (abs(x - xx) + v - 1) / v + abs(b[it] - y) + abs(b[it] - yy));
        if (it > 0)
        {
            it--;
            ans = min(ans, (abs(x - xx) + v - 1) / v + abs(b[it] - y) + abs(b[it] - yy));
        }
        cout << ans << endl;
    }
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}