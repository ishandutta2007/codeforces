#include <bits/stdc++.h>

using namespace std;

const int N = 200010, MOD = 1000000007;

int n, m;
int a[N];
int b[N], c[N];

int mul(int u, int v) {
  return 1ll * u * v % MOD;
}

int power(int u, int v) {
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

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  b[1] = a[1];
  c[1] = 1;
  m = 1;
  int f = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] != b[m]) {
      b[++m] = a[i];
    }
    c[m]++;
  }
  int u = 1;
  for (int i = 1; i <= m; i++) {
    if (c[i] % 2) {
      f = 1;
    }
    u = mul(u, power(b[i], c[i]));
  }
  if (f) {
    int res = u;
    int ff = 0;
    for (int i = 1; i <= m; i++) {
      if (!ff && c[i] % 2) {
        ff = 1;
        res = power(res, (c[i] + 1) / 2);
      } else {
        res = power(res, c[i] + 1);
      }
    }
    cout << res << endl;
  } else {
    u = 1;
    int ff = 0;
    for (int i = 1; i <= m; i++) {
      u = mul(u, power(b[i], c[i] / 2));
    }
    int res = u;
    for (int i =1 ; i <= m; i++) {
      res = power(res, c[i] + 1);
    }
    cout << res << endl;
  }
  return 0;
}