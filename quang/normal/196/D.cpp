#include <bits/stdc++.h>

using namespace std;

const int N = 400010, MOD = 1000000007, base = 10007;

inline int plusmod(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

inline int sub(int u, int v) {
  u -= v;
  if (u < 0) {
    u += MOD;
  }
  return u;
}

inline int Power(int u, int v) {
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

int d, n;
char a[N];
int p[N], inv[N], pref[N], suff[N];

struct bit {
  int t[N];

  void add(int x, int v) {
    while (x <= n) {
      t[x] = plusmod(t[x], v);
      x += (x & -x);
    }
  }

  int get(int x) {
    int res = 0;
    while (x) {
      res = plusmod(res, t[x]);
      x -= (x & -x);
    }
    return res;
  }
} tpref, tsuff;

bool check(int u) {
  int h1 = sub(pref[u], mul(pref[u - d], p[d]));
  int h2 = sub(suff[u - d + 1], mul(suff[u + 1], p[d]));
  if (h1 == h2) {
    return 0;
  }
  if (u == d) {
    return 1;
  }
  h1 = sub(pref[u], mul(pref[u - d - 1], p[d + 1]));
  h2 = sub(suff[u - d], mul(suff[u + 1], p[d + 1]));
  if (h1 == h2) {
    return 0;
  }
  return 1;
}

bool check1(int u) {
  if (u < d) {
    return 1;
  }
  int h1 = mul(sub(tpref.get(u), tpref.get(u - d)), inv[u - d + 1]);
  int h2 = mul(sub(tsuff.get(u), tsuff.get(u - d)), inv[n - u + 1]);
  if (h1 == h2) {
    return 0;
  }
  if (u == d) {
    return 1;
  }
  h1 = mul(sub(tpref.get(u), tpref.get(u - d - 1)), inv[u - d]);
  h2 = mul(sub(tsuff.get(u), tsuff.get(u - d - 1)), inv[n - u + 1]);
  if (h1 == h2) {
    return 0;
  }
  return 1;
}

void go(int u) {
  if (u > n) {
    printf("%s", a + 1);
    exit(0);
  }
  for (char x = 'a'; x <= 'z'; x++) {
    tpref.add(u, mul(p[u], x - 'a'));
    tsuff.add(u, mul(p[n - u + 1], x - 'a'));
    if (check1(u)) {
      a[u] = x;
      go(u + 1);
    }
    tpref.add(u, sub(0, mul(p[u], x - 'a')));
    tsuff.add(u, sub(0, mul(p[n - u + 1], x - 'a')));
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  p[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    p[i] = mul(p[i - 1], base);
    inv[i] = Power(p[i], MOD - 2);
  }
  scanf("%d", &d);
  scanf("%s", a + 1);
  n = strlen(a + 1);
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = plusmod(mul(pref[i - 1], base), a[i]);
  }
  suff[n + 1] = 0;
  for (int i = n; i; i--) {
    suff[i] = plusmod(mul(suff[i + 1], base), a[i]);
  }
  int pos = d;
  while (pos < n && check(pos)) {
    pos++;
  }
  for (int i = 1; i <= pos; i++) {
    tpref.add(i, mul(p[i], a[i] - 'a'));
    tsuff.add(i, mul(p[n - i + 1], a[i] - 'a'));
  }
  for (int i = pos; i; i--) {
    tpref.add(i, sub(0, mul(p[i], a[i] - 'a')));
    tsuff.add(i, sub(0, mul(p[n - i + 1], a[i] - 'a')));
    for (char j = a[i] + 1; j <= 'z'; j++) {
      tpref.add(i, mul(p[i], j - 'a'));
      tsuff.add(i, mul(p[n - i + 1], j - 'a'));
      if (check1(i)) {
        a[i] = j;
        go(i + 1);
      }
      tpref.add(i, sub(0, mul(p[i], j - 'a')));
      tsuff.add(i, sub(0, mul(p[n - i + 1], j - 'a')));
    }
  }
  puts("Impossible");
//  freopen("input.txt", "w", stdout);
//  cout << 3 << endl;
//  for (int i = 1; i <= 400000; i++) {
//    if (i & 1) {
//      cout << 'z';
//    } else {
//      cout << 'y';
//    }
//  }
  return 0;
}