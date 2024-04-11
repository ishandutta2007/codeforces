#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint LEN = 32;
lint lim, mod;
lint memo[40];

lint dp(lint n) {
  if (n >= 0 && (1ll << n) > lim) return 0;
  if (n >= 0 && memo[n] != -1) {
    return memo[n];
  }
  lint res = 1;
  for (lint i = n + 1; i < LEN; i++) {
    res += dp(i);
    res %= mod;
  }

  if (n >= 0) {
    lint mul = min(1ll << (n), lim - (1 << n) + 1);
    res *= mul;
  }
  res %= mod;
  return memo[n] = res;
}

void solve() {
  memset(memo, -1, sizeof(memo));
  cin >> lim >> mod;
  lint ans = dp(-1) - 1;
  ans %= mod;
  ans += mod;
  ans %= mod;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }


}