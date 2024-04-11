#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> dsu(n, -1);
  vector<vector<pair<int, int>>> adj(n);
  function<int(int)> Find = [&](int x) {
    return dsu[x] < 0 ? x : dsu[x] = Find(dsu[x]);
  };
  set<int> distinct;
  vector<array<int, 3>> edge;
  string ans(m, '0');
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    if (Find(u) == Find(v)) {
      edge.push_back({u, v, i});
      distinct.emplace(u);
      distinct.emplace(v);
      ans[i] = '1';
    } else {
      dsu[Find(u)] = Find(v);
      adj[u].emplace_back(v, i);
      adj[v].emplace_back(u, i);
    }
  }

  if (edge.size() == 3 && distinct.size() == 3) {
    int ed = -1;
    const auto Dfs = [&](const auto &self, int u, int p, int t) {
      if (u == t) return true;
      for (auto [v, id] : adj[u]) {
        if (v != p && self(self, v, u, t)) {
          ed = id;
          return true;
        }
      }
      return false;
    };
    auto [u, v, id] = edge[0];
    Dfs(Dfs, u, -1, v);
    assert(ed != -1);
    ans[id] = '0';
    ans[ed] = '1';
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}