#ifdef ONPC
    # define _GLIBCXX_DEBUG
#endif
#ifdef ONPC
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    ll ans = 0;
    ll cur = 0;
    for (ll i : a)
    {
        ll cnt = min(i / 2LL, cur);
        ans += cnt;
        cur -= cnt;
        i -= 2LL * cnt;
        ans += i / 3LL;
        cur += i % 3;
    }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
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