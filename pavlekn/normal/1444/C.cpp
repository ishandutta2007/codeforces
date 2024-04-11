#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;

vector<vector<int>> g(MAXN);
vector<vector<int>> h(MAXN);

int col[MAXN];
int col2[MAXN];
int used[MAXN];
int used2[MAXN];
int us[MAXN];
int cmp[MAXN];

int cc = 0;

int fl = true;
int fl2 = true;

void dfs(int u, int cl)
{
    cmp[u] = cc;
    used[u] = true;
    col[u] = cl;
    for (auto v : h[u])
    {
        if (!used[v])
        {
            dfs(v, 1 - cl);
        }
        else if (col[u] == col[v])
        {
            fl = false;
        }
    }
}

void check(int u, int cl)
{
    used2[u] = true;
    col2[u] = cl;
    for (auto v : g[u])
    {
        if (!used2[v])
        {
            check(v, 1 - cl);
        }
        else if (col2[u] == col2[v])
        {
            fl2 = false;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n);
    vector<vector<int>> a(k);
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
        --c[i];
        a[c[i]].push_back(i);
    }
    map<pair<int, int>, vector<pair<int, int>>> num;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (c[u] == c[v])
        {
            h[u].push_back(v);
            h[v].push_back(u);
        }
        else
        {
            num[{min(c[u], c[v]), max(c[v], c[u])}].push_back({u, v});
        }
    }
    vector<int> flag(k, true);
    int ans = 0;
    int cnt = k;
    for (int i = 0; i < k; ++i)
    {
        fl = true;
        for (auto u : a[i])
        {
            if (!used[u])
            {
                dfs(u, 0);
                ++cc;
            }
        }
        if (!fl)
        {
            flag[i] = false;
            --cnt;
        }
    }
    ans = cnt * (cnt - 1) / 2;
    for (auto el : num)
    {
        auto p = el.first;
        if (!flag[p.first] || !flag[p.second])
        {
            continue;
        }
        int x = p.first;
        int y = p.second;
        vector<int> s;
        for (auto e : el.second)
        {
            int u = e.first;
            int v = e.second;
            us[cmp[u]] = false;
            g[2 * cmp[u]] = {};
            g[2 * cmp[u] + 1] = {};
            us[cmp[v]] = false;
            g[2 * cmp[v]] = {};
            g[2 * cmp[v] + 1] = {};
            s.push_back(2 * cmp[u]);
            s.push_back(2 * cmp[u] + 1);
            s.push_back(2 * cmp[v]);
            s.push_back(2 * cmp[v] + 1);
        }
        for (auto e : el.second)
        {
            int u = e.first;
            int v = e.second;
            if (!us[cmp[u]])
            {
                used2[2 * cmp[u]] = false;
                used2[2 * cmp[u] + 1] = false;
                us[cmp[u]] = true;
                g[2 * cmp[u]].push_back(2 * cmp[u] + 1);
                g[2 * cmp[u] + 1].push_back(2 * cmp[u]);
            }
            if (!us[cmp[v]])
            {
                used2[2 * cmp[v]] = false;
                used2[2 * cmp[v] + 1] = false;
                us[cmp[v]] = true;
                g[2 * cmp[v]].push_back(2 * cmp[v] + 1);
                g[2 * cmp[v] + 1].push_back(2 * cmp[v]);
            }
            g[2 * cmp[u] + col[u]].push_back(2 * cmp[v] + col[v]);
            g[2 * cmp[v] + col[v]].push_back(2 * cmp[u] + col[u]);
        }
        fl2 = true;
        for (auto u : s)
        {
            if (!used2[u])
            {
                check(u, 0);
            }
        }
        if (!fl2)
        {
            --ans;
        }
    }
    cout << ans << endl;
    return 0;
}