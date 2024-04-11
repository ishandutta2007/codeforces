#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

struct Seg {
  int l, r;
  bool flip;
  int lock;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int m = l + r >> 1;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
  }
}

void push_down(int o) {
  if (T[o].lock) {
    T[o << 1].lock = T[o << 1 | 1].lock = T[o].lock;
    T[o << 1].flip = T[o << 1 | 1].flip = false;
    T[o].lock = 0;
  }
  if (T[o].flip) {
    T[o << 1].flip ^= true;
    T[o << 1 | 1].flip ^= true;
    T[o].flip = false;
  }
}

void flips(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].flip ^= true;
    return;
  }
  int m = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= m) flips(o << 1, l, r);
  if (r > m) flips(o << 1 | 1, l, r);
}

void update(int o, int l, int r, int val) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lock = val;
    T[o].flip = false;
    return;
  }
  int m = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= m) update(o << 1, l, r, val);
  if (r > m) update(o << 1 | 1, l, r, val);
}

int query(int o, int x) {
  if (T[o].l == T[o].r) {
    if (!T[o].lock) return T[o].flip;
    if (T[o].lock == 1) return T[o].flip ? -2 : 2;
    return T[o].flip ? 2 : -2;
  }
  int m = T[o].l + T[o].r >> 1;
  push_down(o);
  if (x <= m) return query(o << 1, x);
  else return query(o << 1 | 1, x);
}

int n, q, x, a[maxn];
char op[5];

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", a + i);
  build(1, 0, 1e5 + 5);
  while (q--) {
    scanf("%s%d", op, &x);
    if (op[0] == '<') {
      if (x > 0) {
        flips(1, 0, x - 1);
        update(1, x, 1e5 + 5, 1);
      } else update(1, -x + 1, 1e5 + 5, 1);
    } else {
      if (x < 0) {
        flips(1, 0, -x - 1);
        update(1, -x, 1e5 + 5, -1);
      } else update(1, x + 1, 1e5 + 5, -1);
    }
  }
  FOR(i, 1, n) {
    int sig = query(1, abs(a[i]));
    if (!sig) printf("%d ", a[i]);
    else if (sig == 1) printf("%d ", -a[i]);
    else if (sig > 0) printf("%d ", abs(a[i]));
    else printf("%d ", -abs(a[i]));
  }
}