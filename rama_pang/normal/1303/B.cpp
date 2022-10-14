#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()



int solve() {
  
  lint n, g, b;
  cin >> n >> g >> b;

  lint req = (n + 1) / 2;
  lint season = g + b;
  lint ans = -1;
  for (lint l = 0, r = 1e18, m = (l + r) / 2; l <= r; m = (l + r) / 2) {
    lint goodSeason = m / season;
    lint left = m - goodSeason * season;
    if (left > g) left = g;
    if (goodSeason * g + left >= req && m >= n) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << "\n";


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}