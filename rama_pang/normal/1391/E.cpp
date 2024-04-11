#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    vector<int> vis(n);
    vector<int> depth(n);
    vector<int> parent(n);
    vector<vector<int>> ls(n);
    function<void(int)> Dfs = [&](int u) {
      vis[u] = 1;
      ls[depth[u]].emplace_back(u);
      for (auto v : adj[u]) {
        if (!vis[v]) {
          depth[v] = depth[u] + 1;
          parent[v] = u;
          Dfs(v);
        }
      }
    };
    parent[0] = -1;
    Dfs(0);
    vector<int> path;
    for (int i = 0; i < n; i++) {
      if (n <= 2 * (depth[i] + 1)) {
        int u = i;
        while (u != -1) {
          path.emplace_back(u);
          u = parent[u];
        }
        break;
      }
    }
    if (!path.empty()) {
      cout << "PATH\n";
      cout << path.size() << "\n";
      for (auto i : path) {
        cout << i + 1 << " ";
      }
      cout << "\n";
      continue;
    }
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++) {
      while (ls[i].size() > 1) {
        int u = ls[i].back();
        ls[i].pop_back();
        int v = ls[i].back();
        ls[i].pop_back();
        pairs.emplace_back(u, v);
      }
    }
    assert(n <= 4 * pairs.size());
    cout << "PAIRING\n";
    cout << pairs.size() << "\n";
    for (auto i : pairs) {
      cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
  }
  return 0;
}