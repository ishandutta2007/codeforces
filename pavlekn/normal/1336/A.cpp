#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

vector<vector<int>> g(MAXN);

int used[MAXN];
int dist[MAXN];
int sz[MAXN];

void dfs(int u)
{
    used[u] = true;
    sz[u] = 1;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dist[v] = dist[u] + 1;
            dfs(v);
            sz[u] += sz[v];
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i)
    {
        s.insert({dist[i] - sz[i] + 1, i});
    }
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        ans += (s.rbegin()->first);
        s.erase(s.find(*(s.rbegin())));
    }
    cout << ans << endl;
    return 0;
}