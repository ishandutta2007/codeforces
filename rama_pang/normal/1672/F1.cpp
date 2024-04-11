#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  map<int, vector<int>> occ;
  for (int i = 0; i < n; i++) {
    occ[a[i]].emplace_back(i);
  }
  vector<int> ans(n, -1);
  while (!occ.empty()) {
    vector<int> todel;
    vector<int> ls;
    for (auto &[x, y] : occ) {
      int u = y.back();
      ls.emplace_back(u);
      y.pop_back();
      if (y.empty()) {
        todel.emplace_back(x);
      }
    }
    for (auto x : todel) {
      occ.erase(x);
    }
    for (int i = 0; i < int(ls.size()); i++) {
      int j = (i + 1) % ls.size();
      ans[ls[i]] = a[ls[j]];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i + 1 == n];
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}