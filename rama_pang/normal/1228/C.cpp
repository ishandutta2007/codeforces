#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MOD = 1e9 + 7;

lint power(lint a, lint x) {
  if (x == 0) {
    return 1;
  }
  if (x & 1ll) {
    return (a * power(a, x - 1)) % MOD;
  }
  lint res = power(a, x / 2);
  return (res * res) % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  lint x, n;
  cin >> x >> n;

  lint ans = 1;

  vector<lint> p;
  for (lint i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      p.emplace_back(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    p.emplace_back(x);
  }

  for (auto &p : p) {
    lint cur = p;
    lint tmp = 0;
    while (cur <= n) {
      tmp += n / cur;
      if (cur > n / p) {
        break;
      }
      cur *= p;
    }
    ans *= power(p, tmp);
    ans %= MOD;
  }

  cout << ans << "\n";
  return 0;
}