#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long

const int INF = 1e18;

int used[300005];
vector<vector<pair<int, int>>> g1;

int cc;

int clea[300005];

void dfs(int u, int ind)
{
    used[u] = true;
    for (auto p : g1[u])
    {
        int v = p.first;
        int ind = p.second;
        if (!used[v])
        {
            dfs(v, ind);
        }
    }
    if (cc > 0 && u != 0 && !clea[ind])
    {
        clea[ind] = true;
        --cc;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int n, m, k;
    cin >> n >> m >> k;
    k = m - k;
    int u, v, w;
    vector<vector<pair<pair<int, int>, int>>> g(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({{w, v}, i});
        g[v].push_back({{w, u}, i});
    }
    vector<int> dist(n, INF);
    dist[0] = 0;
    set<pair<int, int>> s;
    s.insert({0, 0});
    vector<pair<pair<int, int>, int>> p1(n - 1);
    while (!s.empty())
    {
        v = s.begin()->second;
        s.erase(s.begin());
        for (auto p : g[v])
        {
            w = p.first.first;
            u = p.first.second;
            if (dist[u] > dist[v] + w)
            {
                s.erase({dist[u], u});
                dist[u] = dist[v] + w;
                p1[u - 1ll] = {{v, u}, p.second};
                s.insert({dist[u], u});
            }
        }
    }
    g1.resize(n);
    for (int i = 0; i < 300004; ++i)
    {
        clea[i] = true;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        g1[p1[i].first.first].push_back({p1[i].first.second, p1[i].second});
        g1[p1[i].first.second].push_back({p1[i].first.first, p1[i].second});
        clea[p1[i].second] = false;
    }
    int e = min((n - 1), m - k);
    k -= m - (n - 1);
    cc = k;
    dfs(0, -1);
    cout << e << endl;
    for (int i = 0; i < 300004; ++i)
    {
        if (!clea[i])
        {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}