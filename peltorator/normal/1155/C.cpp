#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

ll gcd(ll a, ll b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    vector<ll> x(n), p(m);
    for (ll &i : x)
        cin >> i;
    for (ll &i : p)
        cin >> i;
    ll cur_gcd = x[1] - x[0];
    for (int i = 2; i < n; i++)
        cur_gcd = gcd(cur_gcd, x[i] - x[i - 1]);
    int t = 0;
    while (t < m && cur_gcd % p[t])
        t++;
    if (t == m)
        cout << "NO\n";
    else
        cout << "YES\n" << x[0] << ' ' << t + 1 << endl;
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