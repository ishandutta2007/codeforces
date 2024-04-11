#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> ans(n - 1, -1);
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v, i - 1);
    adj[v].emplace_back(u, i - 1);
  }
  
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int a, int b) { return adj[a].size() > adj[b].size(); });

  int cnt = 0;
  for (auto &i : ord) {
    for (auto &j : adj[i]) {
      if (ans[j.second] == -1) {
        ans[j.second] = cnt++;
      }
    }
  }

  for (int i = 0; i < n - 1; i++) {
    cout << ans[i] << "\n";
  }
  
}