#include<bits/stdc++.h>

using namespace std;

#define int long long
#pragma GCC optimize("-O3")

const int MAXN = 2e5 + 7;

vector<set<int>> g(MAXN);
vector<set<int>> g2(MAXN);

int deg[MAXN];
int a[MAXN];

int used[MAXN];

int w[MAXN];

int mx = 0;

void dfs(int u, int cur)
{
    mx = max(mx, cur + a[u]);
    w[u] = true;
    for (auto v : g2[u])
    {
        if (used[v] && !w[v])
        {
            dfs(v, cur + a[u]);
        }
    }
}

int us[MAXN];

vector<int> roots;

void dfs1(int u)
{
    us[u] = true;
    for (auto v : g2[u])
    {
        if (us[v])
        {
            continue;
        }
        if (!used[v])
        {
            dfs1(v);
        }
        else
        {
            roots.push_back(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int sm = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sm += a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].insert(v);
        g2[u].insert(v);
        g[v].insert(u);
        g2[v].insert(u);
        ++deg[u]; ++deg[v];

    }
    int s;
    cin >> s;
    --s;
    for (int ii = 0; ii < n; ++ii)
    {
        int i = ii;
        if (deg[i] == 1 && i != s)
        {
            while (deg[i] == 1 && i != s)
            {
                --deg[i];
                sm -= a[i];
                used[i] = true;
                int j = *(g[i].begin());
                g[i].erase(g[i].begin());
                g[j].erase(g[j].find(i));
                --deg[j];
                i = j;
            }
        }
    }
    dfs1(s);
    for (auto el : roots)
    {
        dfs(el, 0);
    }
    cout << sm + mx << endl;
    return 0;
}