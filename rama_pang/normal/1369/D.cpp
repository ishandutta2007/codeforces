#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  const int mod = 1e9 + 7;
  const int m = 2e6 + 5;
  vector<int> dp(m);
  dp[3] = 4;
  dp[4] = 4;
  for (int i = 5; i < m; i++) {
    dp[i] = ((i % 3 == 0 ? 4 : 0) + dp[i - 1] + 2ll * dp[i - 2]) % mod;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
  }
  return 0;
}