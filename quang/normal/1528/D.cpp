#include <bits/stdc++.h>

using namespace std;

const int N = 610;

int n, m;
vector<pair<int, int>> adj[N];
int used[N];
int dp[N];
queue<int> ls[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  for (int i = 0; i < n; i++) {
    sort(adj[i].begin(), adj[i].end(), [](pair<int, int> u, pair<int, int> v) {
      return u.second < v.second;
    });
  }
  // for (int i = 0; i < n; i++) {
  //   for (auto [v, w] : adj[i]) {
  //     cout << v << ' ' << w << endl;
  //   }
  //   cout << endl;
  // }
  for (int i = 0; i < n; i++) {
    // cout << "# " << i << endl;
    fill(used, used + n, 0);
    fill(dp, dp + n, 1.01e9);
    for (int j = 0; j < n; j++) {
      while (!ls[j].empty()) {
        ls[j].pop();
      }
    }
    int min_val = adj[i][0].second;
    // cout << "min_val " << min_val << endl;
    for (auto [v, w] : adj[i]) {
      if (w - min_val <= n) {
        ls[w - min_val].push(v);
        dp[v] = min(dp[v], w);
        // cout << "push " << w - min_val << ' ' << v << endl;
      }
    }
    for (int j = 0; j < n; j++) {
      while (!ls[j].empty()) {
        int u = ls[j].front();
        ls[j].pop();
        // cout << u << ' ' << dp[u] << endl;
        if (used[u]) continue;
        assert((dp[u] - min_val) == j);
        used[u] = 1;
        if (dp[(u + 1) % n] > dp[u] + 1) {
          dp[(u + 1) % n] = dp[u] + 1;
          ls[j + 1].push((u + 1) % n);
        }
        for (auto [v, w] : adj[u]) {
          int now = dp[u] + w;
          int vv = (dp[u] + v) % n;
          if (now - min_val <= n && dp[vv] > dp[u] + w) {
            dp[vv] = dp[u] + w;
            ls[now - min_val].push(vv);
          }
        }
      }
    }
    dp[i] = 0;
    for (int j = 0; j < n; j++) {
      cout << dp[j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}