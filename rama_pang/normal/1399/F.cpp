#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    vector<int> x = {0, 2000000};
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      a.emplace_back(l, r);
      x.emplace_back(l);
      x.emplace_back(r);
    }
    sort(begin(x), end(x));
    x.resize(unique(begin(x), end(x)) - begin(x));
    vector<vector<int>> seg(x.size());
    for (int i = 0; i < n; i++) {
      a[i].first = lower_bound(begin(x), end(x), a[i].first) - begin(x);
      a[i].second = lower_bound(begin(x), end(x), a[i].second) - begin(x);
      seg[a[i].first].emplace_back(a[i].second);
    }
    for (int i = 0; i < (int) x.size(); i++) {
      sort(begin(seg[i]), end(seg[i]));
    }
    n = x.size();
    int ans = 0;
    vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0));
    for (int i = n - 1; i > 0; i--) {
      for (int j = i; j < n; j++) {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        ans = max(ans, dp[i][j]);
      }
      for (int j = i, ptr = 0; j < n; j++) {
        while (ptr < (int) seg[i].size() && seg[i][ptr] < j) {
          ptr++;
        }
        int add = (ptr < (int) seg[i].size() && seg[i][ptr] == j);
        dp[i][j] = max(dp[i][j], add + dp[i + 1][j]);
        dp[i][j] = max(dp[i][j], add + dp[i][j - 1]);
        for (auto k : seg[i]) {
          if (k >= j) break;
          dp[i][j] = max(dp[i][j], add + dp[i][k] + dp[k + 1][j]);
        }
        ans = max(ans, dp[i][j]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}