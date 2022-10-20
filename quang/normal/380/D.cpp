#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 1000000007;

int n, m, pos;
int a[N];
int f[N], inv[N], p[N];

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

int Power(int u, int v) {
  int res = 1;
  while (v) {
    if (v & 1) {
      res= mul(res, u);
    }
    u = mul(u, u);
    v >>= 1;
  }
  return res;
}

int C(int k, int n) {
  int res = mul(inv[k], inv[n - k]);
  return mul(res, f[n]);
}

int case1(int l, int r) {
  pos = l;
  while (!a[pos]) {
    pos++;
  }
  if (a[pos] == 1) {
    return C(pos - l, r - l);
  }
  int res = 0;
  int x = r - l + 1 - a[pos];
  if (pos - a[pos] + 1 >= l) {
    int foo = p[a[pos] - 2];
    res = add(res, mul(foo, C(r - pos, x)));
  }
  if (pos + a[pos] - 1 <= r) {
    int foo = p[a[pos] - 2];
    int xx = C(pos - l, x);
    xx = mul(foo, xx);
    res = add(res, xx);
  }
  return res;
}

int go(int l, int r, int cnt, int pre) {
  if (cnt == 1) {
    return case1(l, r);
  }
  int res = 1;
  int posl = l, posr = r;
  while (!a[posl]) {
    posl++;
  }
  while (!a[posr]) {
    posr--;
  }
  if (max(a[posl], a[posr]) > pre) {
    return 0;
  }
  if (a[posl] > a[posr]) {
    if (posl + a[posl] - 1 > r) {
      return 0;
    }
    res = mul(res, C(posl - l, r - l + 1 - a[posl]));
    return mul(res, go(posl + 1, a[posl] + posl - 1, cnt - 1, a[posl]));
  } else {
    if (posr - a[posr] + 1 < l) {
      return 0;
    }
    res = mul(res, C(r - posr, r - l + 1 - a[posr]));
    return mul(res, go(posr - a[posr] + 1, posr - 1, cnt - 1, a[posr]));
  }
  return res;
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] != 0) {
      m++;
    }
  }
  f[0] = inv[0] = p[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = mul(f[i - 1], i);
    inv[i] = Power(f[i], MOD - 2);
    p[i] = add(p[i - 1], p[i - 1]);
  }
  if (!m) {
    printf("%d\n", p[n - 1]);
    return 0;
  }
  if (m == 1) {
    printf("%d\n", case1(1, n));
    return 0;
  }
  printf("%d\n", go(1, n, m, 1e9));
  return 0;
}