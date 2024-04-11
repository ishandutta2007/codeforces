#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
//#define string basic_string<unsigned char>
#define char unsigned char

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int N = 153234, B = 806;
const int S = 2 * N / B + 1;
const ll MOD = 998244353;

ll tree[N];

ll summ(int r)
{
    ll result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
    {
        result += tree[r];
        if (result >= MOD)
            result -= MOD;
    }
    return result;
}

void inc(int i, ll delta)
{
    delta %= MOD;
    if (delta < 0)
        delta += MOD;
    for (; i < N; i |= (i + 1))
    {
        tree[i] += delta;
        if (tree[i] >= MOD)
            tree[i] -= MOD;
    }
}


int w[B][N];
int siz[N];
int pr[N];
ll sum[N];
int revind[N];
int beg[N], ending[N];
vector<int> g[N];
int timer = 0;

int dfs(int v, int p)
{
    pr[v] = p;
    beg[v] = timer++;
    siz[v] = 1;
    for (int u : g[v])
        if (u != p)
            siz[v] += dfs(u, v);
    ending[v] = timer;
    return siz[v];
}

void zhfs(int v, int p, int i, int bg)
{
    w[i][v] = bg;
    for (int u : g[v])
        if (u != p)
            zhfs(u, v, i, bg);
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

int solve()
{
    int n;
    int q;
    cin >> n >> q;
    ll revn = binpow(n, MOD - 2);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    int curind = 0;
    for (int i = 0; i < n; i++)
        if (sz(g[i]) > S)
        {
            if (curind >= B)
                while (true);
            revind[curind] = i;
            for (int u : g[i])
                zhfs(u, i, curind, u);
            curind++;
        }
    ll cursum = 0;
    while (q--)
    {
        int t;
        cin >> t;
        int v;
        cin >> v;
        v--;
        if (t == 1)
        {
            ll d;
            cin >> d;
            cursum += d * (ll)n;
            cursum %= MOD;
            if (sz(g[v]) <= S)
            {
                for (int u : g[v])
                {
                    if (u != pr[v])
                    {
                        ll cursiz = siz[u];
                        inc(beg[u], -cursiz * d);
                        inc(ending[u], cursiz * d);
                    }
                    else
                    {
                        ll cursiz = n - siz[v];
                        inc(0, -cursiz * d);
                        inc(beg[v], cursiz * d);
                        inc(ending[v], -cursiz * d);
                    }
                }
            }
            else
            {
                sum[v] += d;
                sum[v] %= MOD;
            }
        }
        else
        {
            ll ans = (cursum + summ(beg[v])) % MOD;
            for (int i = 0; i < curind; i++)
            {
                int u = revind[i];
                if (u == v)
                    continue;
                ans -= (ll)(pr[u] == w[i][v] ? n - siz[u] : siz[w[i][v]]) * sum[u];
                ans %= MOD;
            }
            cout << ((ans % MOD) + MOD) * revn % MOD << '\n';
        }
    }
    return 1;
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