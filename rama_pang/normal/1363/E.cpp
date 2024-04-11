#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  
  vector<long long> dp(n, 0);
  vector<int> cnt0(n, 0);
  vector<int> cnt1(n, 0);
  vector<int> need0(n, 0);
  vector<int> need1(n, 0);

  function<void(int, int)> dfs = [&](int u, int p) {  
    if (b[u] != c[u]) {
      if (b[u] == 0) {
        cnt0[u]++;
      } else {
        cnt1[u]++;
      }
      if (c[u] == 0) {
        need0[u]++;
      } else {
        need1[u]++;
      }
    }
    dp[u] = 0;
    for (auto v : adj[u]) if (v != p) {
      a[v] = min(a[v], a[u]);
      dfs(v, u);
      cnt0[u] += cnt0[v];
      cnt1[u] += cnt1[v];
      need0[u] += need0[v];
      need1[u] += need1[v];
      dp[u] += dp[v];
    }
    int z = min(cnt0[u], need0[u]);
    int o = min(cnt1[u], need1[u]);
    int canmatch = z + o;
    cnt0[u] -= z;
    need0[u] -= z;
    cnt1[u] -= o;
    need1[u] -= o;
    dp[u] += 1ll * canmatch * a[u];
  };

  dfs(0, -1);
  if (need0[0] > 0 || need1[0] > 0 || cnt0[0] > 0 || cnt1[0] > 1) {
    cout << -1 << "\n";
  } else {
    cout << dp[0] << "\n";
  }
  return 0;
}