#include <bits/stdc++.h>

using namespace std;

const int K = 500;
const int MAXN = 1e5 + 5;

int cnt[MAXN];

vector<int> up;
vector<pair<int, int>> e[MAXN];

int ind = 0;

int used[MAXN];

vector<vector<int>> g(MAXN);

vector<int> cmp;

int num[MAXN][K];

void dfs(int u)
{
    cmp.push_back(u);
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v);
        }
    }
}

int cc = 0;

void dfs2(int u)
{
    num[u][up.size() - 1] = cc;
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs2(v);
        }
    }
}

unordered_map<long long, int> ans;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        ++cnt[c];
        e[c].push_back({u, v});
        e[c].push_back({v, u});
    }
    for (int i = 0; i <= m; ++i)
    {
        if (cnt[i] > K)
        {
            up.push_back(i);
            for (auto el : e[i])
            {
                g[el.first].push_back(el.second);
            }
            ind = i;
            for (auto el : e[i])
            {
                if (!used[el.first])
                {
                    dfs2(el.first);
                    ++cc;
                }
            }
            for (auto el : e[i])
            {
                used[el.first] = false;
                g[el.first] = {};
            }
        }
        else
        {
            for (auto el : e[i])
            {
                g[el.first].push_back(el.second);
            }
            ind = i;
            for (auto el : e[i])
            {
                if (!used[el.first])
                {
                    dfs(el.first);
                    for (auto u : cmp)
                    {
                        for (auto v : cmp)
                        {
                            ++ans[((long long)u << 32) | v];
                        }
                    }
                    cmp = {};
                }
            }
            for (auto el : e[i])
            {
                used[el.first] = false;
                g[el.first] = {};
            }
        }
    }
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int res = ans[((long long)u << 32) | v];
        for (int i = 0; i < up.size(); ++i)
        {
            if (num[u][i] == num[v][i])
            {
                ++res;
            }
        }
        cout << res << "\n";
    }
    return 0;
}