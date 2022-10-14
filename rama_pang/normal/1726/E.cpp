#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 998244353;

#define int lint

lint Power(lint x, lint y) {
  lint z = 1;
  while (y) {
    if (y & 1) {
      z = 1ll * z * x % MOD;
    }
    x = 1ll * x* x % MOD;
    y /= 2;
  }
  return z;
}

// lint memo[200][200][200];

// lint DP(int n, int two, int four) {
//   if (n == 0) return two == 0 && four == 0;
//   if (n < 0 || two < 0 || four < 0) return 0;
//   if (memo[n][two][four] != -1) return memo[n][two][four];
//   lint ret = 0;
//   ret += DP(n - 1, two, four);
//   ret += DP(n - 1, two + 1, four);
//   ret += two * DP(n - 1, two - 1, four);
//   ret += DP(n - 2, two, four + 1);
//   ret += 2 * four * DP(n - 2, two, four - 1) % MOD;
//   ret %= MOD;
//   return memo[n][two][four] = ret;
// }

void Main() {
  int n;
  cin >> n;
  // memset(memo, -1, sizeof(memo));
  // cout << DP(n, 0, 0) << '\n';

  vector<lint> fact(n + 1, 1);
  vector<lint> ifact(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    fact[i] = 1ll * i * fact[i - 1] % MOD;
    ifact[i] = Power(fact[i], MOD - 2);
  }
  const auto C = [&](int n, int k) {
    if (k < 0 || k > n) return 0ll;
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
  };
  lint ans = 0;
  vector<lint> dp(n + 1), dp2(n + 1);
  dp[0] = 1;
  dp2[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (i >= 2) {
      dp2[i] = 2 * dp2[i - 2] * (i - 1) % MOD;
      dp[i] += dp[i - 2] * (i - 1) % MOD;
    }
    dp2[i] %= MOD;
    dp[i] %= MOD;
  }
  for (int four = 0; four * 4 <= n; four++) {
    int cnt = four * 2;
    lint ways = C(n - cnt, cnt);
    ways *= dp2[cnt];
    ways %= MOD;
    ans += ways * dp[n - four * 4] % MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
  // vector<lint> dp(n + 1);
  // dp[0] = 1;
  // for (int i = 1; i <= n; i++) {
  //   dp[i] = dp[i - 1];
  //   if (i >= 2) {
  //     dp[i] += 1ll * (i - 1) * dp[i - 2] % MOD;
  //   }
  //   if (i >= 4) {
  //     dp[i] += 1ll * (i - 1) * (i - 2) * (i - 3) % MOD * dp[i - 4] % MOD;
  //   }
  //   dp[i] %= MOD;
  // }
  // cout << dp[n] << '\n';
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