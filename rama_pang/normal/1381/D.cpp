#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, a, b;
  cin >> n >> a >> b;
  a--, b--;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  function<int(int, int)> FindLen = [&](int u, int p) {
    if (u == b) return 0;
    int res = 1e9;
    for (auto v : adj[u]) if (v != p) {
      res = min(res, FindLen(v, u) + 1);
    }
    return res;
  };
  vector<multiset<int>> dp(n); // maximum depth
  const auto DfsDp = [&](const auto &self, int u, int p) -> void {
    dp[u].emplace(0);
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u);
      dp[u].emplace(*prev(end(dp[v])) + 1);
    }
  };
  vector<int> pivot(n);
  const auto DfsReroot = [&](const auto &self, int u, int p) -> void {
    if (adj[u].size() < 3) {
      pivot[u] = 0;
    } else {
      pivot[u] = *prev(prev(prev(end(dp[u]))));
    }
    for (auto v : adj[u]) if (v != p) {
      dp[u].erase(dp[u].find(*prev(end(dp[v])) + 1));
      dp[v].emplace(*prev(end(dp[u])) + 1);
      self(self, v, u);
      dp[v].erase(dp[v].find(*prev(end(dp[u])) + 1));
      dp[u].emplace(*prev(end(dp[v])) + 1);
    }
  };
  int len = FindLen(a, -1);
  DfsDp(DfsDp, 0, -1);
  DfsReroot(DfsReroot, 0, -1);
  int root = -1;
  for (int i = 0; i < n; i++) {
    if (pivot[i] >= len) {
      root = i;
    }
  }
  if (root == -1) {
    cout << "NO\n";
    return;
  }
  vector<int> depth(n);
  vector<vector<int>> lift(n, vector<int>(20, -1));
  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    depth[u] = (p == -1 ? 0 : (depth[p] + 1));
    lift[u][0] = p;
    for (int j = 1; j < 20; j++) {
      if (lift[u][j - 1] != -1) {
        lift[u][j] = lift[lift[u][j - 1]][j - 1];
      }
    }
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u);
    }
  };
  const auto KthAncestor = [&](int u, int k) {
    for (int i = 0; i < 20; i++) {
      if (k & (1 << i)) {
        u = lift[u][i];
        if (u == -1) {
          break;
        }
      }
    }
    return u;
  };
  const auto Lca = [&](int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    v = KthAncestor(v, depth[v] - depth[u]);
    for (int i = 19; i >= 0; i--) {
      if (lift[u][i] != lift[v][i]) {
        u = lift[u][i];
        v = lift[v][i];
      }
    }
    return u == v ? u : lift[u][0];
  };
  vector<int> mxdepth(n, -1);
  const auto DfsDeep = [&](const auto &self, int u, int p) -> void {
    mxdepth[u] = u;
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u);
      if (depth[mxdepth[v]] > depth[mxdepth[u]]) {
        mxdepth[u] = mxdepth[v];
      }
    }
  };
  Dfs(Dfs, root, -1);
  DfsDeep(DfsDeep, root, -1);
  for (int rep = 0; rep < 2 * n; rep++) {
    swap(a, b);
    int w = Lca(a, b);
    if (w == a || w == b) {
      cout << "YES\n";
      return;
    }
    int to = mxdepth[a];
    int dist = depth[to] - depth[a];
    b = KthAncestor(b, dist);
    a = to;
    if (b == -1) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    Main();
  }  
  return 0;
}