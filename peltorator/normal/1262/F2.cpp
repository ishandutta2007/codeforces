#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

ll sum(ll a, ll b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

ll mult(ll a, ll b)
{
    return a * b % MOD;
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a)
{
    return binpow(a, MOD - 2);
}

ll divid(ll a, ll b)
{
    return a * binpow(b, MOD - 2) % MOD;
}

const int N = 212345;

ll fct[N], revfct[N];

ll c(ll n, ll k)
{
    return fct[n] * revfct[k] % MOD * revfct[n - k] % MOD;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    ll k;
    cin >> k;
    int m = 0;
    vector<int> h(n);
    for (int &i : h)
        cin >> i;
    if (k == 1)
    {
        cout << "0\n";
        return 0;
    }
    h.push_back(h[0]);
    for (int i = 0; i < n; i++)
        if (h[i] != h[i + 1])
            m++;
    fct[0] = revfct[0] = 1;
    for (ll i = 1; i < N; i++)
        fct[i] = i * fct[i - 1] % MOD, revfct[i] = inv(fct[i]);
    ll ans = binpow(k, m);
    for (int l = 0; l <= m / 2; l++)
        ans = (ans - c(m, 2 * l) * c(2 * l, l) % MOD * binpow(k - 2, m - 2 * l)) % MOD, ans = (ans + MOD) % MOD;
    ans = ans * inv(2) % MOD;
    ans = ans * binpow(k, n - m) % MOD;
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    // cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}