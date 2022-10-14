#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  lint n;
  cin >> n;
  // 1 is always divisor
  // 2 for {1, 3, 5, 7, 9, 11, ...}
  // Not yet: {2, 4, 6, 8, ...}
  // 3 for {2, 4, 8, ...}
  // Not yet: {6, 12, 18, ...}
  // 4 for {6, 18, ..}
  // Not yet: {12, 24, ...}
  // 5 for {12, 24, ...}
  // Not yet: {60, 120, ...}
  
  lint ans = 0;
  const lint MOD = 1e9 + 7;

  const auto lcm = [&](lint x, lint y) {
    return x / __gcd(x, y) * y;
  };

  lint cand = 1;
  for (lint d = 2;; d++) {
    lint num = n / cand;
    if (num == 0) break;
    cand = lcm(cand, d);
    lint nxtNum = n / cand;
    ans += 1ll * (num - nxtNum) % MOD * d % MOD;
    ans %= MOD;
  }

  cout << ans << '\n';
  return;  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}