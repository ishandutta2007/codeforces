#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> dp(n + 2);
  vector<int> pref(n + 2);
  const int MOD = 998244353;
  const auto Power = [&](int n, int x) {
    int res = 1;
    while (x > 0) {
      if (x & 1) {
        res = 1ll * res * n % MOD;
      }
      n = 1ll * n * n % MOD;
      x /= 2;
    }
    return res;
  };

  dp[0] = 1;
  pref[0] = 0;
  for (int i = 0; i <= n; i++) {
    if (i >= 2) {
      pref[i] += pref[i - 2];
      pref[i] %= MOD;
    }
    dp[i] += pref[i];
    dp[i] %= MOD;
    if (i + 1 <= n) {
      pref[i + 1] += dp[i];
      pref[i + 1] %= MOD;
    }
  }
  cout << 1ll * dp[n] * Power(Power(2, MOD - 2), n) % MOD << "\n";
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