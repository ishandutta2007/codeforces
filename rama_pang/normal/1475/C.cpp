#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k), b(k);
    vector<vector<int>> adj(n + m);
    for (auto &i : a) cin >> i, i--;
    for (auto &i : b) cin >> i, i--;
    for (int i = 0; i < k; i++) {
      adj[a[i]].emplace_back(b[i] + n);
      adj[b[i] + n].emplace_back(a[i]);
    }
    lint ans = 1ll * k * (k - 1) / 2;
    for (int i = 0; i < n + m; i++) {
      ans -= 1ll * adj[i].size() * (int(adj[i].size()) - 1) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}