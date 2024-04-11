#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

char gc() {
  const int sz = 1 << 21;
  static char v[sz], *b, *e;
  return b == e ? (e = (b = v) + fread(v, 1, sz, stdin), b == e ? EOF : *b++) : *b++;
}
void rd(int &x) {
  char c = gc();
  x = 0;
  while (isspace(c))
    c = gc();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = gc();
  }
}

const int N = 1000005;
int n, m, a[N];
int l[2000005], r[2000005];

int main() {
  rd(n);
  for (int i = 1; i <= n; i++)
    rd(a[i]), l[a[i]] = r[a[i]] = a[i];
  m = a[n];
  for (int i = 1; i <= m; i++)
    if (!l[i])
      l[i] = l[i - 1];
  for (int i = m; i; i--)
    if (!r[i])
      r[i] = r[i + 1];

  for (int g = 1;; g++) {
    if (1ll * (g + 1) * (g + 1) <= a[1])
      continue;
    i64 d = 1ll * g * g - a[1];
    i64 vl = 0, vr = g;
    if (d < 0)
      vl = -d;
    for (int i = g; 1ll * i * i <= a[n] + d; i++) {
      int b = 1ll * i * i - d;
      int p1 = l[min(m, b + i)], p2 = b + i + 1 <= m ? r[b + i + 1] : -1;
      if (p1 >= b)
        vr = min(vr, 1ll * i * i + i - (p1 + d));
      if (p2 != -1 && p2 + d < 1ll * (i + 1) * (i + 1))
        vl = max(vl, 1ll * (i + 1) * (i + 1) - (p2 + d));
    }
    if (vl <= vr) {
      cout << d + vl;
      return 0;
    }
  }
}