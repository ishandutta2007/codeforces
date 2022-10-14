#include <bits/stdc++.h>
using namespace std;

using lint = long long;
// #define int lint

void Main() {
  int n;
  cin >> n;
  lint ans = 0;
  vector<vector<int>> a(2 * n, vector<int>(2 * n));
  for (int i = 0; i < n + n; i++) {
    for (int j = 0; j < n + n; j++) {
      cin >> a[i][j];
      if (i >= n && j >= n) {
        ans += a[i][j];
      }
    }
  }
  int add = 2e9;
  for (int x : {0, n - 1}) {
    for (auto y : {0, n - 1}) {
      add = min(add, a[n + x][y]);
      add = min(add, a[x][n + y]);
    }
  }
  ans += add;
  cout << ans << '\n';
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