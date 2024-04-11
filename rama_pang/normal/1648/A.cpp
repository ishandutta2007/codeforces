#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> x, y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      x[a].emplace_back(i);
      y[a].emplace_back(j);
    }
  }
  const auto Solve = [&](vector<int> v) {
    sort(begin(v), end(v));
    long long res = 0;
    for (int i = 1; i < int(v.size()); i++) {
      res += 1ll * (v[i] - v[i - 1]) * i * (int(v.size()) - i);
    }
    return res;
  };
  long long ans = 0;
  for (auto [i, j] : x) ans += Solve(j);
  for (auto [i, j] : y) ans += Solve(j);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}