#include <bits/stdc++.h>

using namespace std;

const int N = 1010, MOD = 1000000007;

int n, m, k;
int Fac[N];

void Build() {
  Fac[0] = 1;
  for (int i = 1; i <= max(n, m); i++) {
    Fac[i] = 1ll * Fac[i - 1] * i % MOD;
  }
}

int Mul(int u, int v) {
  int res = 1;
  while (v) {
    if (v & 1) {
      res = 1ll * res * u % MOD;
    }
    u = 1ll * u * u % MOD;
    v /= 2;
  }
  return res;
}

int C(int u, int v) {
  if (v > u) {
    return 0;
  }
  if (!v || v == u) {
    return 1;
  }
  int res = 1ll * Fac[v] * Fac[u - v] % MOD;
  res = 1ll * Fac[u] * Mul(res, MOD - 2) % MOD;
  return res;
}

int main() {
  //ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  Build();
  cout << 1ll * C(n - 1, k * 2) * C(m - 1, k * 2) % MOD;
}