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

typedef unsigned long long ll;
typedef long double ld;

const ll INF = 1e18;

vector<ll> a, b;

ll Sqrt(ll x)
{
    ll l = 0, r = 1e9 + 7;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2LL;
        if (mid * mid <= x)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int solve()
{
    ios::sync_with_stdio(0);
    int q;
    if (!(cin >> q))
    {
        return 1;
    }
    for (ll x = 2; x <= 1000000; x++)
    {
        ll cur = x * x * x;
        ll y = x;
        while (cur < INF)
        {
            a.push_back(cur);
            ll w = cur * y;
            if (w / y != cur)
                break;
            cur = w;
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        if ((!i || a[i] != a[i - 1]) && Sqrt(a[i]) * Sqrt(a[i]) != a[i])
            b.push_back(a[i]);
    a = b;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        auto it1 = lower_bound(a.begin(), a.end(), l);
        auto it2 = lower_bound(a.begin(), a.end(), r + 1);
        ll ans = it2 - it1 + (ll)Sqrt(r) - (ll)Sqrt(l - 1);
        cout << ans << '\n';
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