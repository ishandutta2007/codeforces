#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  pair<int, int> biggest = {-1, -1};
  for (int i = 0; i < n; i++) {
    biggest = max(biggest, {a[i], i});
  }
  // Compute dp[v], assume parent direction has super large, what is minimum cost for this subtree?
  vector<pair<lint, lint>> dp(n);
  const auto GetOpt = [&](pair<lint, lint> a, pair<lint, lint> b) {
    if (a.first != b.first) {
      return min(a, b);
    }
    if (a.second < b.second) {
      return b;
    } else {
      return a;
    }
  };
  lint ans = 1e18;
  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    lint sumDP = 0;
    dp[u] = {a[u], a[u]};
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u);
      sumDP += dp[v].first;      
    }
    dp[u] = {sumDP + a[u], a[u]};
    for (auto v : adj[u]) if (v != p) {
      sumDP -= dp[v].first;
      dp[u] = GetOpt(dp[u], pair(sumDP + dp[v].first + max(0ll, a[u] - dp[v].second), max(a[u], dp[v].second)));
      sumDP += dp[v].first;
    }
    if (p == -1) {
      vector<lint> diffs = {a[u]};
      for (auto v : adj[u]) {
        diffs.emplace_back(max(0ll, a[u] - dp[v].second));
      }
      sort(begin(diffs), end(diffs));
      ans = diffs[0] + diffs[1] + sumDP;
    }
  };
  Dfs(Dfs, biggest.second, -1);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}