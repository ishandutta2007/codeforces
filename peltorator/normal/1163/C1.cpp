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
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    map<pair<ll, ll>, ll > q;
    set<pair<pair<ll, ll>, ll> > qq;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            ll A = y[i] - y[j];
            ll B = x[j] - x[i];
            ll C = -A * x[i] - B * y[i];
            ll d = gcd(gcd(A, B), C);
            A /= d;
            B /= d;
            C /= d;
            if (A < 0 || (A == 0 && B < 0))
                A = -A, B = -B, C = -C;
            qq.insert({{A, B}, C});
        }
    for (auto it : qq)
    {
        ll A = it.first.first, B = it.first.second;
        ll d = gcd(A, B);
        A /= d;
        B /= d;
        if (A < 0 || (A == 0 && B < 0))
            A = -A, B = -B;
        q[{A, B}]++;
    }
    ll ans = sz(qq);
    ans = ans * (ans - 1) / 2LL;
    for (auto it : q)
        ans -= it.second * (it.second - 1) / 2LL;
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
}