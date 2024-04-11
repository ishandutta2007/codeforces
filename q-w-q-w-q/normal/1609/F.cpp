#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char gc() {
  const int sz = 1 << 21;
  static char v[sz], *b, *e;
  return b == e ? (e = (b = v) + fread(v, 1, sz, stdin), b == e ? EOF : *b++) : *b++;
}
void rd(long long &x) {
  char c;
  x = 0, c = gc();
  while (isspace(c))
    c = gc();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = gc();
  }
}

const int N = 1000005;
int n, b[N];
long long a[N];
int stx[N], topx;
int stn[N], topn;
bool u[105];

namespace sgt {
int mx[N << 2], s[N << 2], lazy[N << 2];
int sz[N << 2];

void bbuild(int i, int l, int r) {
  sz[i] = r - l + 1;
  if (l == r)
    return;

  int mid = (l + r) >> 1;
  bbuild(i << 1, l, mid), bbuild(i << 1 | 1, mid + 1, r);
}

void build() {
  memset(mx, 0, n * 4 * 4);
  memset(lazy, 0, n * 4 * 4);
  memcpy(s, sz, n * 4 * 4);
}

void update(int i) {
  if (mx[i << 1] == mx[i << 1 | 1])
    mx[i] = mx[i << 1], s[i] = s[i << 1] + s[i << 1 | 1];
  else if (mx[i << 1] > mx[i << 1 | 1])
    mx[i] = mx[i << 1], s[i] = s[i << 1];
  else
    mx[i] = mx[i << 1 | 1], s[i] = s[i << 1 | 1];

  mx[i] += lazy[i];
}

void modify(int i, int l, int r, int x, int y, int z) {
  if (x <= l && y >= r) {
    mx[i] += z, lazy[i] += z;
    return;
  }

  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(i << 1, l, mid, x, y, z);
  if (y > mid)
    modify(i << 1 | 1, mid + 1, r, x, y, z);

  update(i);
}
} // namespace sgt

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    rd(a[i]), b[i] = __builtin_popcountll(a[i]), u[b[i]] = 1;

  sgt::bbuild(1, 1, n);

  long long ans = 0;

  for (int pc = 0; pc <= 62; pc++) {
    if (!u[pc])
      continue;
    sgt::build();

    topx = topn = 0;

    for (int i = 1; i <= n; i++) {
      while (topx && a[stx[topx]] <= a[i]) {
        if (b[stx[topx]] == pc)
          sgt::modify(1, 1, n, stx[topx - 1] + 1, stx[topx], -1);
        topx--;
      }

      if (b[i] == pc)
        sgt::modify(1, 1, n, stx[topx] + 1, i, 1);
      stx[++topx] = i;

      while (topn && a[stn[topn]] >= a[i]) {
        if (b[stn[topn]] == pc)
          sgt::modify(1, 1, n, stn[topn - 1] + 1, stn[topn], -1);
        topn--;
      }

      if (b[i] == pc)
        sgt::modify(1, 1, n, stn[topn] + 1, i, 1);
      stn[++topn] = i;

      if (sgt::mx[1] == 2)
        ans += sgt::s[1];
    }
  }

  cout << ans;
}