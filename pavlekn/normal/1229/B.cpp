#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 25;
const int MAXL = 20;

const int mod = 1e9 + 7;

int p[MAXN][MAXL];
int gc[MAXN][MAXL];

vector<vector<int>> g(MAXN);

int used[MAXN];
int x[MAXN];

void dfs(int u)
{
    gc[u][0] = x[u];
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            p[v][0] = u;
            dfs(v);
        }
    }
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    p[0][0] = MAXN - 1;
    p[MAXN - 1][0] = MAXN - 1;
    gc[MAXN - 1][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (int i = 1; i < MAXL; ++i)
    {
        p[MAXN - 1][i] = MAXN - 1;
        gc[MAXN - 1][i] = 1;
        for (int u = 0; u < n; ++u)
        {
            p[u][i] = p[p[u][i - 1]][i - 1];
            gc[u][i] = gcd(gc[u][i - 1], gc[p[u][i - 1]][i - 1]);
        }
    }
    int ans = 0;
    for (int ii = 0; ii < n; ++ii)
    {
        int u = ii;
        int cr = x[u];
        int st = ii;
        while (u != MAXN - 1)
        {
            int cnt = 0;
            for (int i = MAXL - 1; i >= 0; --i)
            {
                if (p[u][i] != MAXN - 1 && gcd(cr, gc[u][i]) == cr)
                {
                    u = p[u][i];
                    cnt += (1 << i);
                }
            }
            if (u == 0 && gcd(x[u], cr) == cr)
            {
                u = MAXN - 1;
                ++cnt;
            }
            ans += (cnt * cr);
            cr = gcd(cr, x[u]);
        }
        ans %= mod;
    }
    cout << ans % mod << endl;
    return 0;
}