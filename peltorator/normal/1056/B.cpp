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
    ll n;
    if (!(cin >> n))
        return 1;
    ll m;
    cin >> m;
    if (n < 2000)
    {
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                if ((i * i + j * j) % m == 0)
                    ans++;
        cout << ans << endl;
        return 0;
    }
    ll ans = 0;
    for (ll i = 1; i <= m; i++)
            for (ll j = 1; j <= m; j++)
                if ((i * i + j * j) % m == 0)
                    ans++;
    ll t = n / m, q = t * m;
    ans *= t * t;
    for (ll i = q + 1; i <= n; i++)
        for (ll j = q + 1; j <= n; j++)
            if ((i * i + j * j) % m == 0)
                ans++;
    for (ll i = q + 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            if ((i * i + j * j) % m == 0)
                ans += 2LL * t;
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