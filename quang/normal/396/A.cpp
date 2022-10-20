#include <bits/stdc++.h>

using namespace std;

const int N = 20010, MOD = 1000000007;

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int mul(int u, int  v) {
  return (long long) u * v % MOD;
}

int n;
int a[N];
int f[N];
map<int, int> m;

int Power(int u, int v) {
  int res = 1;
  while (v) {
    if (v & 1) {
      res = mul(res, u);
    }
    u = mul(u, u);
    v >>= 1;
  }
  return res;
}

int c(int k, int n) {
  int x = mul(f[k], f[n - k]);
  x = Power(x, MOD - 2);
  x = mul(x, f[n]);
  return x;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = mul(f[i - 1], i);
  }
  for (int i = 1; i <= n; i++) {
    int u = a[i];
    for (int j = 2; j * j <= u; j++) {
      while (u % j == 0) {
        m[j]++;
        u /= j;
      }
    }
    if (u > 1) {
      m[u]++;
    }
  }
  int res = 1;
  for (auto x : m) {
    int foo = c(n - 1, n - 1 + x.second);
    res = mul(res, foo);
  }
  cout << res << endl;
  return 0;
}