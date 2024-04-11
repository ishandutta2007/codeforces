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

const int T = 9;

ll cnt[T];
ll ans;
ll w;

void rec(ll ind, ll cur)
{
    if (ind == 0)
    {
        ans = max(ans, cur);
        return;
    }
    ll k = min(cnt[ind], (w - cur) / ind);
    for (ll i = 0; i <= min(k, 10LL); i++)
        if (cur + (k - i) * ind <= w)
            rec(ind - 1, cur + (k - i) * ind);
}

int solve()
{
    if (!(cin >> w))
        return 1;
    for (ll i = 1; i <= 8; i++)
    {
        cin >> cnt[i];
    }
    ans = 0;
    rec(8, 0);
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