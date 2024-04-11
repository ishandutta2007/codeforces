#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  const int N = 205;

  vector<vector<lint>> choose(2 * N, vector<lint>(2 * N));
  for (int i = 0; i < 2 * N; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
    }
  }

  vector<lint> factorial(2 * N);
  factorial[0] = 1;
  for (int i = 1; i < 2 * N; i++) {
    factorial[i] = 1ll * i * factorial[i - 1] % MOD;
  }

  vector<vector<lint>> dp(2 * N, vector<lint>(N)); // dp[count_element][count_ops] = cycle is formed with minimum swaps
  dp[0][0] = 1;
  for (int n = 0; n < 2 * N; n++) {
    for (int ops = 0; ops < N; ops++) {
      for (int cyc = 2; cyc < N && n + cyc < 2 * N && ops + cyc - 1 < N; cyc++) {
        // choose smallest index to be on next cycle to avoid double counting
        dp[n + cyc][ops + cyc - 1] += dp[n][ops] * choose[n + cyc - 1][cyc - 1] % MOD * factorial[cyc - 1] % MOD;
        dp[n + cyc][ops + cyc - 1] %= MOD;
      }
    }
  }

  const auto Power = [&](int n, int x) {
    int z = 1;
    while (x) {
      if (x & 1) z = 1ll * z * n % MOD;
      n = 1ll * n * n % MOD;
      x /= 2;
    }
    return z;
  };

  vector<lint> inverse(2 * N);
  for (int i = 1; i < 2 * N; i++) {
    inverse[i] = Power(i, MOD - 2);
  }

  const auto C = [&](int n, int k) -> lint {
    if (k < 0 || k > n) return 0;
    lint z = 1;
    for (int i = 0; i < k; i++) {
      z = 1ll * z * (n - i) % MOD;
      z = 1ll * z * inverse[i + 1] % MOD;
    }
    return z;
  };

  int T = 1;
//   cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<lint> res(k + 1);
    vector<lint> Cn(2 * k + 1);
    for (int d = 0; d <= 2 * k; d++) {
      Cn[d] = C(n, d);
    }
    for (int op = 0; op <= k; op++) {
      for (int d = 0; d <= min(n, 2 * k); d++) {
        res[op] += dp[d][op] * Cn[d] % MOD;
        res[op] %= MOD;
      }
    }
    for (int j = 1; j <= k; j++) {
      lint ans = 0;
      for (int i = j; i >= 0; i -= 2) {
        ans += res[i];
        ans %= MOD;
      }
      if (ans < 0) ans += MOD;
      cout << ans << ' ';
    }
    cout << '\n';
  }
  return 0;
}