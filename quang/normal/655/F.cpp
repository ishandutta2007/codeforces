#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, MOD = 1000000007;

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int sub(int u, int v) {
  u -= v;
  if (u < 0) {
    u += MOD;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

inline int power(int u, int v) {
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

inline int inv(int u) {
  return power(u, MOD - 2);
}

int n, k, m;
int phi[N], c[N], cnt[N];

int main() {
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 1; i < N; i++) {
    phi[i] = i;
  }
  for (int i = 1; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      phi[j] -= phi[i];
    }
  }
  c[k] = 1;
  for (int i = k + 1; i <= n + m; i++) {
    c[i] = mul(c[i - 1], mul(i, inv(i - k)));
  }
  int res = 0;
  for (int id = 1; id <= n + m; id++) {
    int u;
    scanf("%d", &u);
    for (int i = 1; i * i <= u; i++) {
      if (u % i) {
        continue;
      }
      for (int rot = 0; rot < 2; rot++) {
        cnt[i]++;
        res = add(res, mul(phi[i], sub(c[cnt[i]], c[cnt[i] - 1])));
        if (i * i == u) {
          break;
        }
        i = u / i;
      }
    }
    if (id > n) {
      printf("%d\n", res);
    }
  }
  return 0;
}