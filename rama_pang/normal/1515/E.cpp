#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

lint dp[405][405];

void Main() {
  lint N, MOD;
  cin >> N >> MOD;

  const auto Add = [&](lint &a, lint b) {
    b %= MOD;
    a += b;
    a %= MOD;
  };

  dp[0][0] = 1;
  for (lint n = 0; n < N; n++) {
    for (lint c = 0; c <= n; c++) {
      // Add new component
      Add(dp[n + 1][c + 1], dp[n][c]);
      // Append to front of component
      Add(dp[n + 1][c], c * dp[n][c]);
      Add(dp[n + 2][c], c * dp[n][c]); // automatic
      // Append to back
      Add(dp[n + 1][c], c * dp[n][c]);
      Add(dp[n + 2][c], c * dp[n][c]); // automatic

      // Merge
      if (c > 0) {
        Add(dp[n + 2][c - 1], c * (c - 1) % MOD * dp[n][c]);
        Add(dp[n + 2][c - 1], c * (c - 1) % MOD * dp[n][c]);
        Add(dp[n + 3][c - 1], c * (c - 1) % MOD * dp[n][c]);
      }
    }
  }

  cout << dp[N][1] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}