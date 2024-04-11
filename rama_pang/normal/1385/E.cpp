#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), radj(n);
    vector<pair<int, int>> edge;
    vector<pair<int, int>> fixed;
    for (int i = 0; i < m; i++) {
      int u, v, t;
      cin >> t >> u >> v;
      u--, v--;
      if (t == 1) {
        adj[u].emplace_back(v);
        radj[v].emplace_back(u);
        fixed.emplace_back(u, v);
      } else {
        edge.emplace_back(u, v);
      }
    }
    vector<int> topo;
    vector<int> vis(n);
    function<void(int)> Dfs = [&](int u) {
      vis[u] = 1;
      for (auto v : adj[u]) if (!vis[v]) Dfs(v);
      topo.emplace_back(u);
    };
    function<void(int)> DfsR = [&](int u) {
      vis[u] = 1;
      for (auto v : radj[u]) if (!vis[v]) DfsR(v);
    };
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        Dfs(i);
      }
    }
    reverse(begin(topo), end(topo));
    vis.assign(n, 0);
    int scc = 0;
    for (auto i : topo) {
      if (!vis[i]) {
        scc++;
        DfsR(i);
      }
    }
    if (scc != n) {
      cout << "NO\n";
      continue;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      pos[topo[i]] = i;
    }
    cout << "YES\n";
    for (auto i : fixed) {
      cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
    for (auto i : edge) {
      if (pos[i.first] > pos[i.second]) {
        swap(i.first, i.second);
      }
      cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
  }  
  return 0;
}