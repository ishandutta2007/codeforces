#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5007;

vector<vector<int>> g(MAXN);

int used[MAXN];

vector<int> ts;

void dfs(int u)
{
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v);
        }
    }
    ts.push_back(u);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        edges.push_back({u, v});
    }
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    reverse(ts.begin(), ts.end());
    vector<int> num(n);
    for (int i = 0; i < n; ++i)
    {
        num[ts[i]] = i;
    }
    int fl = true;
    for (int u = 0; u < n; ++u)
    {
        for (auto v : g[u])
        {
            if (num[u] > num[v])
            {
                fl = false;
            }
        }
    }
    if (fl)
    {
        cout << 1 << endl;
        for (int i = 0; i < m; ++i)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }
    cout << 2 << endl;
    for (auto el : edges)
    {
        if (num[el.first] < num[el.second])
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 2 << " ";
        }
    }
    cout << endl;
    return 0;
}