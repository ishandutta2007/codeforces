#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<lint> c(n);
    for (auto &x : c) {
      cin >> x;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[v].emplace_back(u);
    }

    for (int i = 0; i < n; i++) {
      sort(begin(adj[i]), end(adj[i]));
    }

    map<vector<int>, lint> val;
    for (int i = 0; i < n; i++) {
      val[adj[i]] += c[i];
    }
    lint g = 0;
    for (auto &v : val) {
      if (v.first.empty()) {
        continue;
      }
      if (g == 0) {
        g = v.second;
      }
      g = __gcd(g, v.second);
    }

    cout << g << "\n";
  } 


}