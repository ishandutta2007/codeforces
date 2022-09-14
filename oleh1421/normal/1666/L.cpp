#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> comp(n + 1, -1);
    auto dfs = [&adj, &comp](auto self, int v, int p, int c) -> int
    {
        if (comp[v] != c && comp[v] != -1) return v;
        comp[v] = c;
        for (int u : adj[v])
        {
            if (u == p) continue;
            if (comp[u] == -1)
            {
                int r = self(self, u, v, c);
                if (r != -1) return r;
            }
            if (comp[u] != c) return u;
        }
        return -1;
    };
    for (int i = 0; i < adj[s].size(); ++i)
    {
        comp[s] = i;
        int r = dfs(dfs, adj[s][i], s, i);
        if (r != -1)
        {
            //found
            vector<int> path;
            vector<bool> used(n + 1);
            used[s] = true;
            auto findPath = [&adj, &path, &used](auto self, int v, int p, int e) -> void
            {
                used[v] = true;
                if (v == e)
                {
                    path.push_back(e);
                    return;
                }
                for (int u : adj[v])
                {
                    if (u != p && !used[u])
                    {
                        self(self, u, v, e);
                        if (!path.empty())
                        {
                            path.push_back(v);
                            return;
                        }
                    }
                }
            };
            findPath(findPath, adj[s][comp[r]], s, r);
            //if (path.empty()) continue;
            cout << "Possible\n";
            reverse(path.begin(), path.end());
            cout << path.size() + 1 << '\n' << s << ' ';
            for (int i : path) cout << i << ' ';
            cout << '\n';
            used = vector<bool>(n + 1);
            used[s] = true;
            path.clear();
            findPath(findPath, adj[s][i], s, r);
            reverse(path.begin(), path.end());
            cout << path.size() + 1 << '\n' << s << ' ';
            for (int i : path) cout << i << ' ';
            return 0;
        }
    }
    cout << "Impossible";
    return 0;
}