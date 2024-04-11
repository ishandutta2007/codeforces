#include <bits/stdc++.h>

using namespace std;

const int N = 100100, MOD = 1000000007;

int n, k;
char a[N];

int Fac[N], Pow[N], Sum[N];

int QPow(int u, int v) {
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
  if (v == 0 || v == u) {
    return 1;
  }
  int res = Fac[u];
  int foo = 1ll * Fac[v] * Fac[u - v] % MOD;
  res =  1ll * res * QPow(foo, MOD - 2) % MOD;
  return res;
}

int Solve(int l) {
  int res = Pow[l];
  int u = n - l - 2, v = k - 1;
  res = 1ll * res * C(u, v) % MOD;
  return res;
}

void Build() {
  Fac[0] = 1;
  Pow[0] = 1;
  for (int i = 1; i <= n; i++) {
    Fac[i] = 1ll * Fac[i - 1] * i % MOD;
    Pow[i] = 1ll * Pow[i - 1] * 10 % MOD;
  }
  Sum[0] = Solve(0);
  for (int i = 1; i <= n; i++) {
    Sum[i] = (1ll * Sum[i - 1] + Solve(i)) % MOD;
  }
}

int Solve2(int l) {
  int res = Pow[l];
  int u = n - l - 1, v = k;
  res = 1ll * res * C(u, v) % MOD;
  return res;
}

void Main() {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int l = min(n - k - 1, n - i - 1);
    if (l >= 0) {
      res = (1ll * Sum[l] * (a[i] - '0') + res) % MOD;
    }
    l = n - i;
    if (l <= n - k - 1) {
      res = (1ll * (a[i] - '0') * Solve2(l) + res) % MOD;
    }
  }
  cout << res;
}

int main() {
  ios_base::sync_with_stdio(0);
 //freopen("C.inp", "r", stdin);
  cin >> n >> k;
  cin >> a + 1;
  Build();
  Main();
  return 0;
}