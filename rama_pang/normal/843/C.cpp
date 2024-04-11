#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<set<int>> adj(N);
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace(v);
    adj[v].emplace(u);
  }

  // centroid doesn't change
  // make each vertex adjacent to centroid into star graph

  vector<int> sz(N);
  const auto Dfs1 = [&](const auto &self, int u, int p) -> void {
    sz[u] = 1;
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u);
      sz[u] += sz[v];
    }
  };
  Dfs1(Dfs1, 0, -1);

  vector<int> centroid(N);

  const auto Dfs2 = [&](const auto &self, int u, int p) -> void {
    int mx = 0;
    for (auto v : adj[u]) {
      mx = max(mx, sz[v]);
    }
    if (mx * 2 <= N) {
      centroid[u] = 1;
    }
    for (auto v : adj[u]) if (v != p) {
      sz[u] -= sz[v];
      sz[v] += sz[u];
      self(self, v, u);
      sz[v] -= sz[u];
      sz[u] += sz[v];
    }
  };
  Dfs2(Dfs2, 0, -1);

  vector<int> ls;
  vector<int> depth(N);
  vector<int> parent(N);
  const auto Dfs3 = [&](const auto &self, int u, int p) -> void {
    ls.emplace_back(u);
    parent[u] = p;
    depth[u] = depth[p] + 1;
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u);
    }
  };

  vector<array<int, 3>> ans;
  const auto Operation = [&](int x, int y, int z) {
    adj[x].erase(y);
    adj[y].erase(x);
    adj[x].emplace(z);
    adj[z].emplace(x);
    ans.push_back({x, y, z});
  };

  for (int c = 0; c < N; c++) if (centroid[c]) {
    auto cand = adj[c];
    for (auto u_ : cand) if (!centroid[u_]) {
      int u = u_;

      // Make into line graph
      ls.clear();
      Dfs3(Dfs3, u, c);
      sort(begin(ls), end(ls), [&](int i, int j) { return depth[i] > depth[j]; });
      Operation(c, u, ls[0]);
      for (int i = 1; i < int(ls.size()); i++) {
        int last = ls[i - 1];
        int cur = ls[i];
        Operation(last, parent[last], cur);
      }
      u = ls[0];

      ls.clear();
      Dfs3(Dfs3, u, c);
      sort(begin(ls), end(ls), [&](int i, int j) { return depth[i] < depth[j]; });
      for (int i = 1; i < int(ls.size()); i++) {
        assert(parent[ls[i]] == ls[i - 1]);
      }

      // Make into star graph
      int x = ls.back();
      for (int i = int(ls.size()) - 2; i >= 0; i--) {
        Operation(parent[ls[i]], ls[i], x);
      }
      u = x;

      ls.clear();
      depth[c] = 0;
      Dfs3(Dfs3, u, c);
      for (auto i : ls) {
        if (i == u) {
          assert(depth[i] == 1);
        } else {
          assert(depth[i] == 2);
        }
      }
    }
  }

  cout << ans.size() << '\n';
  for (auto [x, y, z] : ans) {
    cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
  }
  return 0;
}