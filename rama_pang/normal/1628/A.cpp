#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<vector<int>> occ(n + 2);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    occ[x].emplace_back(i);
  }
  vector<int> ans;
  int cur = 0;
  while (cur < n) {
    int big = cur;
    for (int i = 0; i <= n + 1; i++) {
      auto it = lower_bound(begin(occ[i]), end(occ[i]), cur);
      if (it == end(occ[i])) {
        ans.emplace_back(i);
        cur = big + 1;
        break;
      } else {
        big = max(big, *it);
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' '; cout << '\n';
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