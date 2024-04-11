#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> t(n);
  vector<int> ans;
  vector<int> mark(n, -1);
  vector<vector<int>> adj(n);
  vector<vector<int>> ls(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    t[i]--;
    ls[t[i]].emplace_back(i);
  }

  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    for (auto j : ls[i]) {
      int mn = 1e9;
      mp.clear();
      for (auto v : adj[j]) {
        if (mark[v] != -1) {
          mp[mark[v]] = 1;
        }
        if (mark[v] == i) {
          cout << -1 << "\n";
          return;
        }
      }
      for (int k = 0; k < min(i, (int) adj[j].size() + 1); k++) {
        if (mp.count(k) == 0) {
          cout << -1 << "\n";
          return;
        }
      }
      mark[j] = i;
      ans.emplace_back(j);
    }
  }

  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}