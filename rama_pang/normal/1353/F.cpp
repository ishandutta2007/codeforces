#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m, 0));
    vector<long long> elems;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        a[i][j] -= (i + j);
        elems.emplace_back(a[i][j]);
      }
    }
    sort(begin(elems), end(elems));
    elems.resize(unique(begin(elems), end(elems)) - begin(elems));
    long long ans = 1e18;
    vector<vector<long long>> dp(n, vector<long long>(m, 1e18));
    for (auto pv : elems) {
      if (a[0][0] < pv) continue;
      dp.assign(n, vector<long long>(m, 1e18));
      dp[0][0] = a[0][0] - pv;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i + 1 < n && pv <= a[i + 1][j]) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j] - pv);
          }
          if (j + 1 < m && pv <= a[i][j + 1]) {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1] - pv);
          }
        }
      }
      ans = min(ans, dp[n - 1][m - 1]);
    }

    cout << ans << "\n";
  }
}