#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

struct DSU {
  int numComp;
  vector<int> root;
  vector<int> sz;
  vector<set<int>> ls;

  DSU(int n = 0) : numComp(n), root(n + 1, 0), sz(n + 1, 1) {
    ls.resize(n + 1);
    for (int i = 1; i <= n; i++) ls[i].insert(i);
  }

  int getRoot(int u) {
    return root[u] ? root[u] = getRoot(root[u]) : u;
  }

  bool unite(int u, int v) {
    u = getRoot(u); v = getRoot(v);
    if (u == v) return 0;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    root[v] = u;
    for (auto val : ls[v]) ls[u].insert(val);
    ls[v].clear();

    numComp--;
    return 1;
  }
};

int n, m;
vector<pair<int, int>> adj[N];

struct Edge {
  int u, v, w;
};

Edge edges[N];


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    edges[i] = {u, v, w};
  }
  sort(edges + 1, edges + m + 1, [](const Edge &u, const Edge &v) {
    return u.w < v.w;
  });
  int min_deg = 0;
  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
    if (!min_deg || adj[min_deg].size() > adj[i].size()) {
      min_deg = i;
    }
  }
  
  DSU dsu(n);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if (min_deg == i) continue;
    if (cur < adj[min_deg].size() && adj[min_deg][cur].first == i) {
      cur++;
    } else {
      dsu.unite(min_deg, i);
    }
  }
  vector<int> ls;
  for (int i = 1; i <= n; i++) {
    if (dsu.getRoot(i) == i) {
      ls.push_back(i);
    }
  }
  for (int i = 0; i < ls.size(); i++) {
    for (int j = i + 1; j < ls.size(); j++) {
      int u = dsu.getRoot(ls[i]);
      int v = dsu.getRoot(ls[j]);
      if (u == v) continue;
      if (1ll * dsu.sz[u] * dsu.sz[v] > m) {
        dsu.unite(u, v);
        continue;
      }
      bool f = 0;
      for (int x : dsu.ls[u]) {
        int cur = 0;
        for (int y : dsu.ls[v]) {
          while (cur < adj[x].size() && adj[x][cur].first < y) cur++;
          if (cur == adj[x].size() || adj[x][cur].first != y) {
            f = 1;
            break;
          }
        }
        if (f) break;
      }
      if (f) {
        dsu.unite(u, v);
      }
    }
  }
  int need = n - dsu.numComp;
  int sum_xor = 0;
  int same_comp = -1;
  if (need + m == 1ll * n * (n - 1) / 2) {
    for (int i = 1; i <= m; i++) {
      sum_xor ^= edges[i].w;
    }
    for (int i = 1; i <= m; i++) {
      if (dsu.getRoot(edges[i].u) == dsu.getRoot(edges[i].v)) {
        if (same_comp == -1) {
          same_comp = edges[i].w;
          break;
        }
      }
    }
  }
  long long res = 0;
  vector<int> chosen_edges;
  for (int i = 1; i <= m; i++) {
    if (dsu.getRoot(edges[i].u) != dsu.getRoot(edges[i].v)) {
      res += edges[i].w;
      dsu.unite(edges[i].u, edges[i].v);
      chosen_edges.push_back(i);
    }
  }
  if (sum_xor == 0) {
    cout << res << endl;
  } else {
    DSU d(n);
    for (auto u : chosen_edges) {
      d.unite(edges[u].u, edges[u].v);
    }
    int min_cost = sum_xor;
    for (int i = 1; i <= m; i++) {
      if (d.getRoot(edges[i].u) != d.getRoot(edges[i].v)) {
        min_cost = min(min_cost, edges[i].w);
        break;
      }
    }
    res += min_cost;
    cout << res << endl;
  }
  return 0;
}