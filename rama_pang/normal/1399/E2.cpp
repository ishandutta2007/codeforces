#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long S;
    cin >> S;
    vector<vector<array<int, 3>>> adj(n);
    for (int i = 0; i + 1 < n; i++) {
      int u, v, w, c;
      cin >> u >> v >> w >> c;
      u--, v--;
      adj[u].push_back({v, w, c});
      adj[v].push_back({u, w, c});
    }
    vector<int> leaf(n);
    for (int i = 1; i < n; i++) {
      if (adj[i].size() == 1) {
        leaf[i] = 1;
      }
    }
    vector<vector<long long>> cost(3);
    function<void(int, int, long long)> Dfs = [&](int u, int p, long long d) {
      if (u != 0 && adj[u].size() == 1) {
        S -= d;
      }
      for (auto v : adj[u]) if (v[0] != p) {
        Dfs(v[0], u, d + v[1]);
        int w = v[1];
        while (w > 0) {
          int neww = w / 2;
          cost[v[2]].emplace_back(1ll * leaf[v[0]] * (w - neww));
          w = neww;
        }
        leaf[u] += leaf[v[0]];
      }
    };
    Dfs(0, -1, 0);
    S *= -1;
    int ans = 1e9;
    if (S <= 0) {
      cout << 0 << "\n";
      continue;
    }
    sort(begin(cost[1]), end(cost[1]));
    sort(begin(cost[2]), end(cost[2]));
    reverse(begin(cost[1]), end(cost[1]));
    reverse(begin(cost[2]), end(cost[2]));
    for (int i = 1; i < (int) cost[1].size(); i++) {
      cost[1][i] += cost[1][i - 1];
      cost[1][i] = min(cost[1][i], (long long) 1e18);
    }
    for (int i = 1; i < (int) cost[2].size(); i++) {
      cost[2][i] += cost[2][i - 1];
      cost[2][i] = min(cost[2][i], (long long) 1e18);
    }
    for (int i = 0; i < (int) cost[1].size(); i++) {
      if (S <= cost[1][i]) {
        ans = min(ans, i + 1);
      }
    }
    for (int i = 0; i < (int) cost[2].size(); i++) {
      if (S <= cost[2][i]) {
        ans = min(ans, 2 * (i + 1));
      }
    }
    for (int i = 0; i < (int) cost[1].size(); i++) {
      if (cost[2].empty() || cost[1][i] + cost[2].back() < S) {
        continue;
      }
      int lo = 0, hi = int(cost[2].size()) - 1;
      while (lo < hi) {
        int md = (lo + hi) / 2;
        if (S <= cost[1][i] + cost[2][md]) {
          hi = md;
        } else {
          lo = md + 1;
        }
      }
      ans = min(ans, i + 1 + 2 * (lo + 1));
    }

    for (int i = 0; i < (int) cost[2].size(); i++) {
      if (cost[1].empty() || cost[2][i] + cost[1].back() < S) {
        continue;
      }
      int lo = 0, hi = int(cost[1].size()) - 1;
      while (lo < hi) {
        int md = (lo + hi) / 2;
        if (S <= cost[2][i] + cost[1][md]) {
          hi = md;
        } else {
          lo = md + 1;
        }
      }
      ans = min(ans, 2 * (i + 1) + lo + 1);
    }
    
    cout << ans << "\n";
  }
  return 0;
}