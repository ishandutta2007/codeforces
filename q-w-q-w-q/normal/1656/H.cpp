#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long u64;
typedef __int128 i128;

char gc() {
  const int sz = 1 << 21;
  static char v[sz], *b, *e;
  return b == e ? (e = (b = v) + fread(v, 1, sz, stdin), b == e ? EOF : *b++) : *b++;
}
template <class _Tp> void rd(_Tp &x) {
  char c = gc();
  x = 0;
  while (isspace(c))
    c = gc();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = gc();
  }
}
void wr(i128 x) {
  if (x < 10)
    cout << (char)('0' + x);
  else
    wr(x / 10), cout << (char)('0' + x % 10);
}

const int N = 1005;
int t, n, m;
bool ua[N], ub[N];
i128 a[N], b[N];
int ctz(i128 x) {
  if (u64(x) == 0)
    return __builtin_ctzll(u64(x >> 64)) + 64;
  else
    return __builtin_ctzll(u64(x));
}
i128 gcd(i128 a, i128 b) {
  if (b == 0)
    return a;
  int shift = ctz(a | b);
  b >>= ctz(b);
  while (a) {
    a >>= ctz(a);
    if (a < b)
      swap(a, b);
    a -= b;
  }
  return b << shift;
}

struct sgt {
  i128 v[N], f[2048];
  int p[N];
  void build(int i, int l, int r) {
    if (l == r) {
      p[l] = i, f[i] = v[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
    f[i] = gcd(f[i << 1], f[i << 1 | 1]);
  }
  void del(int x) {
    x = p[x], f[x] = 0;
    while (x >>= 1)
      f[x] = gcd(f[x << 1], f[x << 1 | 1]);
  }
} fn[N], fm[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  rd(t);
  while (t--) {
    rd(n), rd(m);
    int rn = n, rm = m;
    for (int i = 1; i <= n; i++)
      rd(a[i]), ua[i] = 1;
    for (int i = 1; i <= m; i++)
      rd(b[i]), ub[i] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        i128 d = gcd(a[i], b[j]);
        fn[i].v[j] = a[i] / d;
        fm[j].v[i] = b[j] / d;
      }
    for (int i = 1; i <= n; i++)
      fn[i].build(1, 1, m);
    for (int i = 1; i <= m; i++)
      fm[i].build(1, 1, n);

    while (1) {
      int p = -1;
      for (int i = 1; i <= n; i++)
        if (fn[i].f[1] != 1 && ua[i]) {
          p = i, rn--;
          break;
        }
      if (p != -1) {
        if (!rn)
          break;
        ua[p] = 0;
        for (int i = 1; i <= m; i++)
          if (ub[i])
            fm[i].del(p);
        continue;
      }
      for (int i = 1; i <= m; i++)
        if (fm[i].f[1] != 1 && ub[i]) {
          p = i, rm--;
          break;
        }
      if (p != -1) {
        if (!rm)
          break;
        ub[p] = 0;
        for (int i = 1; i <= n; i++)
          if (ua[i])
            fn[i].del(p);
        continue;
      }
      break;
    }
    if (rn == 0 || rm == 0)
      cout << "NO\n";
    else {
      cout << "YES\n" << rn << ' ' << rm << '\n';
      for (int i = 1; i <= n; i++)
        if (ua[i])
          wr(a[i]), cout << ' ';
      cout << '\n';
      for (int i = 1; i <= m; i++)
        if (ub[i])
          wr(b[i]), cout << ' ';
      cout << '\n';
    }
  }
}