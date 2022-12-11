#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

vector<int> deg(MAXN);
vector<vector<pair<int, int>>> g(MAXN);

int used[MAXN];

vector<int> cur;

void dfs(int u)
{
    used[u] = true;
    for (auto p : g[u])
    {
        int v = p.first;
        if (!used[v])
        {
            dfs(v);
        }
    }
    if (deg[u] == 1)
    {
        cur.push_back(u);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        ++deg[u];
        ++deg[v];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 0; i < n; ++i)
    {
        if (deg[i] == 2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    vector<vector<int>> ans;
    for (int u = 0; u < n; ++u)
    {
        for (auto p : g[u])
        {
            int v = p.first;
            int w = p.second;
            if (u > v)
            {
                continue;
            }
            for (int i = 0; i < n; ++i)
            {
                used[i] = false;
            }
            used[u] = true;
            used[v] = true;
            cur = {};
            dfs(u);
            int a = cur[0];
            int b = a;
            if (cur.size() > 1)
            {
                b = cur[cur.size() - 1];
            }
            cur = {};
            dfs(v);
            int c = cur[0];
            int d = c;
            if (cur.size() > 1)
            {
                d = cur[cur.size() - 1];
            }
            if (a == b && c == d)
            {
                ans.push_back({a, c, w});
                continue;
            }
            if (a == b)
            {
                ans.push_back({a, c, w / 2});
                ans.push_back({a, d, w / 2});
                ans.push_back({c, d, -w / 2});
                continue;
            }
            if (c == d)
            {
                ans.push_back({a, c, w / 2});
                ans.push_back({b, c, w / 2});
                ans.push_back({a, b, -w / 2});
                continue;
            }
            ans.push_back({a, c, w / 2});
            ans.push_back({b, d, w / 2});
            ans.push_back({a, b, -w / 2});
            ans.push_back({c, d, -w / 2});
            continue;
        }
    }
    cout << ans.size() << endl;
    for (auto el : ans)
    {
        cout << el[0] + 1 << " " << el[1] + 1 << " " << el[2] << endl;
    }
    return 0;
}