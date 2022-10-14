#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> dp(k, -1e9);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> d(k, vector<int>(m / 2 + 1, -1e9));
    d[0][0] = 0;
    for (int j = 0; j < m; j++) {
      auto nd = d;
      for (int l = 0; l < k; l++) {
        for (int b = 0; b < m / 2; b++) {
          nd[(l + a[i][j]) % k][b + 1] = max(nd[(l + a[i][j]) % k][b + 1], d[l][b] + a[i][j]);
        }
      }
      d = nd;
    }
    auto ndp = dp;
    for (int l = 0; l < k; l++) {
      for (int b = 0; b <= m / 2; b++) {
        for (int c = 0; c < k; c++) {
          ndp[(c + l) % k] = max(ndp[(c + l) % k], dp[c] + d[l][b]);
        }
      }
    }
    dp = ndp;
  }
  cout << dp[0] << "\n";
  return 0; 
}