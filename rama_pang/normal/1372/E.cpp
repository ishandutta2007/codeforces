#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> intervals;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      intervals.emplace_back(l, r);
    }
  }

  sort(begin(intervals), end(intervals));
  vector<vector<int>> dp(m, vector<int>(m, 0));
  for (int l = m - 1; l >= 0; l--) {
    for (int r = l; r < m; r++) {
      vector<int> cnt(m);
      for (auto i : intervals) {
        if (l <= i.first && i.second <= r) {
          cnt[i.first]++;
          if (i.second + 1 < m) {
            cnt[i.second + 1]--;
          }
        }
      }
      for (int i = 1; i < m; i++) {
        cnt[i] += cnt[i - 1];
      }
      for (int piv = l; piv <= r; piv++) {
        dp[l][r] = max(dp[l][r], (piv > 0 ? dp[l][piv - 1] : 0) + (piv + 1 < m ? dp[piv + 1][r] : 0) + cnt[piv] * cnt[piv]);
      }
    }
  }

  cout << dp[0][m - 1] << "\n";
  return 0;
}