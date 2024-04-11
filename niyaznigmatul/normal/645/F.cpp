#include <bits/stdc++.h>

using namespace std;

int const MOD = 1000000007;
int const N = 1034567;

int INV[N], FACT[N], INVFACT[N];

int mul(int a, int b) {
  return (int) ((long long) a * b % MOD);
}

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int c(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mul(FACT[n], mul(INVFACT[k], INVFACT[n - k]));
}

vector<int> d[N], z[N];

int a[N], mo[N], p[N], ans[N], f[N];

int main() {
  INV[1] = 1;
  for (int i = 2; i < N; i++) {
    INV[i] = mul(MOD - MOD / i, INV[MOD % i]);
  }
  FACT[0] = 1;
  INVFACT[0] = 1;
  for (int i = 1; i < N; i++) {
    FACT[i] = mul(FACT[i - 1], i);
    INVFACT[i] = mul(INVFACT[i - 1], INV[i]);
  }
  for (int i = 1; i < N; i++) mo[i] = 1;
  for (int i = 2; i < N; i++) {
    if (p[i] != 0) continue;
    for (int j = i; j < N; j += i) {
      p[j] = i;
      mo[j] = -mo[j];
    }
  }
  for (int i = 2; i * i < N; i++) {
    for (int j = i * i; j < N; j += i * i) {
      mo[j] = 0;
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      d[j].push_back(i);
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      add(f[j], mul(MOD + mo[i], j / i));
    }
  }
  int n, k, q;
  scanf("%d%d%d", &n, &k, &q);
  int md = 0;
  for (int i = 0; i < n + q; i++) {
    scanf("%d", a + i);
    if (a[i] > md) md = a[i];
    for (int j : d[a[i]]) {
      z[j].push_back(i);
    }
  }
  for (int i = 1; i <= md; i++) {
    int cn = 0;
    for (size_t e = 0; e < z[i].size(); e++) {
      ++cn;
      int ways = mul(c(cn, k), f[i]);
      //printf("%d %d %d %d %d\n", i, (int) e, cn, k, ways);
      add(ans[z[i][e]], ways);
      if (e + 1 < z[i].size()) {
        add(ans[z[i][e + 1]], MOD - ways);
      }
    }
  }
  for (int i = 1; i < n + q; i++) {
    add(ans[i], ans[i - 1]);
  }
  for (int i = n; i < n + q; i++) {
    printf("%d\n", ans[i]);
  }
}