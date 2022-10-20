#include <bits/stdc++.h>

using namespace std;

class DSU {
 public:
  explicit DSU(int n) : num_comp_(n), root_(n, -1), sz_(n, 1) {}

  int num_comp() const { return num_comp_; }
  int sz(int u) { return sz_[GetRoot(u)]; }

  int GetRoot(int u) { return ~root_[u] ? root_[u] = GetRoot(root_[u]) : u; }

  bool Unite(int u, int v) {
    u = GetRoot(u);
    v = GetRoot(v);
    if (u == v) return false;
    sz_[v] += sz_[u];
    root_[u] = v;
    num_comp_--;
    return true;
  }

 private:
  int num_comp_;  // number of connected components
  vector<int> sz_;
  vector<int> root_;
};

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n, vector<int>());
  vector<int> deg(n);

  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (dsu.Unite(x, y)) {
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }

  int q;
  cin >> q;

  function<bool(int, int, int, vector<int>&)> Dfs = [&](int u, int dest, int p, vector<int> &now) {
    now.push_back(u);
    if (u == dest) return true;
    for (auto v : adj[u]) {
      if (v == p) continue;
      if (Dfs(v, dest, u, now)) return true;
    } 
    now.pop_back();
    return false;
  };

  vector<vector<int>> ls;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u] ^= 1, deg[v] ^= 1;
    vector<int> now;
    Dfs(u, v, -1, now);
    ls.push_back(now);
  }

  int f = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i] % 2) {
      f = 1;
      break;
    }
  }
  if (!f) {
    cout << "YES\n";
    for (auto val : ls) {
      cout << val.size() << '\n';
      for (auto u : val) cout << u + 1 << ' ';
      cout << '\n';
    }
    return 0;
  }
  cout << "NO\n";
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += (deg[i] % 2);
  }
  assert(cnt % 2 == 0);
  cout << cnt / 2 << '\n';
  return 0;
}