#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int TT = 1;
  // cin >> TT;
  while (TT--) {
    vector<int> n(3);
    cin >> n[0] >> n[1] >> n[2];
    vector<vector<int>> a(3);
    vector<int> all;
    for (int i = 0; i < 3; i++) {
      a[i].resize(n[i]);
      for (auto &j : a[i]) {
        cin >> j;
        all.emplace_back(j);
      }
      sort(begin(a[i]), end(a[i]));
    }
    sort(begin(all), end(all));
    lint total = accumulate(begin(all), end(all), 0ll);    
    lint ans = 0;
    for (int i = 0; i < 3; i++) {
      if (n[i] == 1) {
        ans = max(ans, total - 2ll * a[i][0]);
      }
      for (int j = i + 1; j < 3; j++) {
        ans = max(ans, total - 2ll * (a[i][0] + a[j][0]));
      }
    }
    lint tot1 = accumulate(begin(a[0]), end(a[0]), 0ll);
    lint tot2 = accumulate(begin(a[1]), end(a[1]), 0ll);
    lint tot3 = accumulate(begin(a[2]), end(a[2]), 0ll);
    ans = max(ans, tot1 + tot2 - tot3);
    ans = max(ans, tot1 + tot3 - tot2);
    ans = max(ans, tot3 + tot2 - tot1);
    cout << ans << '\n';
  }
  return 0;
}