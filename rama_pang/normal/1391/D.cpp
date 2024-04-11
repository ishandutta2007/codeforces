#include <bits/stdc++.h>
using namespace std;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (min(n, m) >= 4) {
    cout << -1 << "\n";
    return 0;
  }
  if (min(n, m) == 1) {
    cout << 0 << "\n";
    return 0;
  }
  if (n > m) {
    vector<string> na(m, string(n, '-'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        na[j][i] = a[i][j];
      }
    }
    a = na;
    swap(n, m);
  }
  vector<int> dp(1 << n);
  for (int i = 0; i < m; i++) {
    vector<int> ndp(1 << n, 1e9);
    for (int m1 = 0; m1 < (1 << n); m1++) {
      for (int m2 = 0; m2 < (1 << n); m2++) {
        int can = 1, cost = 0;
        for (int j = 0; j + 1 < n; j++) {
          int cnt = 0;
          cnt += !!(m1 & (1 << (j + 0)));
          cnt += !!(m1 & (1 << (j + 1)));
          cnt += !!(m2 & (1 << (j + 0)));
          cnt += !!(m2 & (1 << (j + 1)));
          if (cnt % 2 == 0) {
            can = 0;
          }
        }
        for (int j = 0; j < n; j++) {
          cost += ((a[j][i] == '1') != !!(m2 & (1 << j)));
        }
        if (can) {
          ndp[m2] = min(ndp[m2], dp[m1] + cost);
        }
      }
    }
    dp = ndp;
  }

  cout << *min_element(begin(dp), end(dp)) << "\n";
  return 0;
}