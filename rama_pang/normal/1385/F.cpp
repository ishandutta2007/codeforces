#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      deg[u]++, deg[v]++;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    queue<int> q;
    vector<int> demand(n, 0);
    vector<int> dead(n, 0);
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == 1) {
        q.emplace(i);
      }
    }
    int ans = 0;
    while (!q.empty()) {
      int u = q.front();
      dead[u] = 1;
      q.pop();
      for (auto v : adj[u]) if (!dead[v]) {
        deg[v]--;
        demand[v]++;
        if (demand[v] == k) {
          ans++;
          demand[v] = 0;
        }
        if (deg[v] == 1 && demand[v] == 0) {
          q.emplace(v);
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}