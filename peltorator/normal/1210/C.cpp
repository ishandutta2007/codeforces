#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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

const int N = 100005;
const int LG = 19;

ll bincnt[LG][N];
int binup[LG][N];
ll x[N];
int pr[N];
int lvl[N];

vector<int> g[N];

void dfs(int v, int p)
{
    pr[v] = p;
    for (int u : g[v])
        if (u != p)
        {
            lvl[u] = lvl[v] + 1;
            dfs(u, v);
        }
}

const ll MOD = 1e9 + 7;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 1; i < n; i++)
    {
        int xx, y;
        cin >> xx >> y;
        xx--;
        y--;
        g[xx].push_back(y);
        g[y].push_back(xx);
    }
    lvl[0] = 0;
    dfs(0, 0);
    for (int i = 0; i < n; i++)
    {
        binup[0][i] = pr[i];
        bincnt[0][i] = gcd(x[pr[i]], x[i]);
    }
    for (int st = 0; st + 1 < LG; st++)
        for (int v = 0; v < n; v++)
        {
            binup[st + 1][v] = binup[st][binup[st][v]];
            bincnt[st + 1][v] = gcd(bincnt[st][v], bincnt[st][binup[st][v]]);
        }
    ll ans = 0;
    for (int v = 0; v < n; v++)
    {
        int u = v;
        ll cur = x[v];
        while (true)
        {
            int z = u;
            for (int s = LG - 1; s >= 0; s--)
                if (gcd(cur, bincnt[s][z]) == cur)
                {
                    z = binup[s][z];
                }
            ans += (ll)(lvl[u] - lvl[z] + 1) * cur;
            ans %= MOD;
            if (z == 0)
                break;
            u = pr[z];
            cur = gcd(cur, x[u]);
        }
    }
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