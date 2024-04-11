#include <bits/stdc++.h>

using namespace std;

const int N = 2000010, MOD = 1000000007;

int n;
long long f[N];

long long qplus(long long u, long long v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

long long qpow(long long u, long long v) {
  long long res = 1;
  while (v) {
    if (v & 1) {
      res = res * u % MOD;
    }
    u = u * u % MOD;
    v >>= 1;
  }
  return res;
}

long long c(int k, int n) {
  if (k == 0 || k == n) {
    return 1;
  }
  long long res = f[k] * f[n - k] % MOD;
  res =  f[n] * qpow(res, MOD - 2) % MOD;
  return res;
}

long long solve(int l, int r, int base) {
  return (c(base + 1, r + 1) - c(base + 1, l) + MOD) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = f[i - 1] * i % MOD;
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = qplus(ans, qpow(2, i));
  }
  for (int i = 1; i <= n; i++) {
    long long foo = solve(n + 1, i + n, i);
    ans = qplus(ans, foo);
  }
  cout << ans << endl;
  return 0;
}