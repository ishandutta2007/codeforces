#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x, pos;
  cin >> n >> x >> pos;

  int fr = 0;
  int needlo = 0;
  int needhi = 0;

  vector<int> cmp(n, -1);
  int lo = 0, hi = n;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (md <= pos) {
      cmp[md] = 0;
      lo = md + 1;
    } else {
      cmp[md] = 1;
      hi = md;
    }
  }
  cmp[pos] = 2;

  assert(lo - 1 == pos);

  for (int i = 0; i < n; i++) {
    if (cmp[i] == -1) {
      fr++;
    }
    if (cmp[i] == 0) {
      needlo++;
    }
    if (cmp[i] == 1) {
      needhi++;
    }
  }

  int lower = x - 1;
  int higher = n - x;

  const int MOD = 1e9 + 7;
  const auto Power = [&](int a, int x) {
    int res = 1;
    int mul = a;
    while (x) {
      if (x & 1) {
        res = 1ll * mul * res % MOD;
      }
      mul = 1ll * mul * mul % MOD;
      x /= 2;
    }
    return res;
  };

  vector<int> fact(n + 1, 0);
  vector<int> invf(n + 1, 0);
  fact[0] = invf[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = 1ll * i * fact[i - 1] % MOD;
    invf[i] = Power(fact[i], MOD - 2);
  }

  const auto C = [&](int n, int r) -> int {
    if (r < 0 || r > n) {
      return 0;
    }
    return 1ll * fact[n] * invf[r] % MOD * invf[n - r] % MOD;
  };

  int ans = 1ll * C(lower, needlo) * C(higher, needhi) % MOD * fact[needlo] % MOD * fact[needhi] % MOD * fact[fr] % MOD;
  cout << ans << "\n";
  return 0;
}