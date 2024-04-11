#ifdef ONPC
    # define _GLIBCXX_DEBUG
#endif
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
    #define deb(a) cerr << "      " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

#define sz(a) (a).size()

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    reverse(a.begin(), a.end());
    ll ans = 0;
    ll cur = 1e18;
    for (ll i : a)
    {
        if (cur <= 0)
            break;
        cur = min(cur, i);
        ans += cur;
        cur--;
    }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1e9;
    //cin >> T;
    while (T--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}