#include <bits/stdc++.h>

using namespace std;

struct DSU {
  int numComp;
  vector<int> root;
  vector<int> sz;
  vector<vector<pair<int, int>>> adj;

  DSU(int n = 0) : numComp(n), root(n + 1, 0), sz(n + 1, 1), adj(n + 1, vector<pair<int, int>>()) {}

  int getRoot(int u) {
    return root[u] ? root[u] = getRoot(root[u]) : u;
  }

  bool unite(int u, int v) {
    u = getRoot(u); v = getRoot(v);
    if (u == v) return 0;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    root[v] = u;
    for (auto val : adj[v]) {
      adj[u].push_back(val);
    }
    numComp--;
    return 1;
  }
};

const int N = 300010;

int n, m, x;
long long a[N];
set<pair<long long, int>> cities_by_a;
int cur[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> x;
  for (int i = 1; i <= n; i++) cin >> a[i];
  DSU dsu(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    dsu.adj[u].push_back({v, i});
    dsu.adj[v].push_back({u, i});
  }
  if (accumulate(a + 1, a + n + 1, 0ll) < 1ll * (n - 1) * x) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cities_by_a.insert({a[i], i});
  }
  vector<int> res;
  while (!cities_by_a.empty()) {
    auto it = prev(cities_by_a.end());
    auto u = it->second;
    cities_by_a.erase(it);
    int &id = cur[u];
    while (id < dsu.adj[u].size()) {
      auto [v, edge_id] = dsu.adj[u][id];
      v = dsu.getRoot(v);
      if (dsu.unite(u, v)) {
        cities_by_a.erase({a[v], v});
        res.push_back(edge_id);
        int w = dsu.getRoot(u);
        a[w] = a[u] + a[v] - x;
        cities_by_a.insert({a[w], w});
        break;
      }
      id++;
    }
  }
  cout << "YES\n";
  for (auto u : res) cout << u << '\n';
  return 0;
}