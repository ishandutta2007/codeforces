#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

void Main() {
  // a + b + c = 3/2 * (a + c)
  // a + b + c = 3/2 a + 3/2 c
  // b = 1/2 a + 1/2 c
  // abc is arithmetic
  // then bcd is arithmetic
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= 2) {
    cout << 0 << '\n';
    return;
  }
  int ans = 0;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      dp[i][j] = max(dp[i][j], 2ll);
      for (int k = j + 1; k < n; k++) {
        if ((a[j] - a[i]) * (k - j) == (a[k] - a[j]) * (j - i)) {
          dp[i][j] = max(dp[i][j], 1 + dp[j][k]);
        }
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << n - ans << '\n';
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