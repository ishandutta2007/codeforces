#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto Check = [&](int x) {
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
      if (a[i] <= x) {
        b[i] = 1;
      }
    }
    int mx = 0;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--) {
      dp[i][0] = 1;
      dp[i][1] = (b[i] == 1);
      if (i + 1 < n) {
        dp[i][0] += dp[i + 1][1];
        if (b[i] == 1) {
          dp[i][1] += dp[i + 1][0];
        }
        dp[i][0] = max(dp[i][0], dp[i + 1][0]);
        dp[i][1] = max(dp[i][1], dp[i + 1][1]);
      }

      mx = max({mx, dp[i][0], dp[i][1]});
    }
    return mx >= k;
  };

  int lo = 1, hi = 1e9;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (Check(md)) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }

  cout << lo << "\n";
  return 0;
}