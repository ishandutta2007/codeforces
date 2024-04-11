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

const int N = 300005;

const ll MOD = 998244353;

void add(ll &a, ll b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
}

void mult(ll &a, ll b)
{
    a = a * b % MOD;
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

void div(ll &a, ll b)
{
    a = a * binpow(b, MOD - 2) % MOD;
}

vector<int> g[N];
int used[N], pr[N];
ll dp1[N], dp2[N];

void dfs(int v)
{
    if (!sz(g[v]))
    {
        dp1[v] = dp2[v] = 1;
        return;
    }
    ll A = 1, B = 1, C = 0;
    for (int u : g[v])
    {
        dfs(u);
        A = A * (dp1[u] + dp2[u]) % MOD;
        B = B * dp2[u] % MOD;
        C = (C + dp1[u] * inv(dp2[u])) % MOD;
    }
    dp2[v] = A - B * C;
    dp2[v] %= MOD;
    dp2[v] += MOD;
    dp2[v] %= MOD;
    dp1[v] = A - B;
    dp1[v] %= MOD;
    dp1[v] += MOD;
    dp1[v] %= MOD;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 0; i < n; i++)
        used[i] = 0, g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
        pr[i] = p;
    }
    dfs(0);
    cout << dp2[0] << endl;
    return 1;
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