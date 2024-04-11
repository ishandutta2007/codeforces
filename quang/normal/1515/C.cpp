#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> h(n);
    for (auto &u : h) {
      cin >> u;
    }
    set<pair<int, int>> s;
    vector<int> a(m, 0);
    for (int i = 0; i < m; i++) {
      s.insert({a[i], i});
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
      auto u = s.begin()->second;
      s.erase(s.begin());
      a[u] += h[i];
      res[i] = u;
      s.insert({a[u], u});
    }
    cout << "YES\n";
    for (auto u : res) {
      cout << u + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}