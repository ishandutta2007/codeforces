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
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i + 1 < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }
    vector<int> leaf(n);
    for (int i = 1; i < n; i++) {
      if (adj[i].size() == 1) {
        leaf[i] = 1;
      }
    }
    vector<long long> cost;
    function<void(int, int, long long)> Dfs = [&](int u, int p, long long d) {
      if (u != 0 && adj[u].size() == 1) {
        S -= d;
      }
      for (auto v : adj[u]) if (v.first != p) {
        Dfs(v.first, u, d + v.second);
        int w = v.second;
        while (w > 0) {
          int neww = w / 2;
          cost.emplace_back(1ll * leaf[v.first] * (w - neww));
          w = neww;
        }
        leaf[u] += leaf[v.first];
      }
    };
    Dfs(0, -1, 0);
    sort(begin(cost), end(cost));
    S *= -1;
    int ans = 0;
    while (S > 0) {
      S -= cost.back();
      cost.pop_back();
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}