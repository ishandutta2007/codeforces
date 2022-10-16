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
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312345;
const int maxc = 1123456;

struct Seg {
  int l, r, mx, lzy;
} T[maxc << 2];

int n, m, q;
int a[maxn], b[maxn];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

inline void push_down(int o) {
  T[o << 1].mx += T[o].lzy;
  T[o << 1 | 1].mx += T[o].lzy;
  T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = T[o].mx = 0;
}

inline void push_up(int o) {
  T[o].mx = max(T[o << 1].mx, T[o << 1 | 1].mx);
}

void add(int o, int l, int r, int d) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mx += d;
    T[o].lzy += d;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(o << 1, l, r, d);
  if (r > mi) add(o << 1 | 1, l, r, d);
  push_up(o);
}

int query(int o) {
  if (T[o].mx <= 0) return -1;
  if (T[o].l == T[o].r) return T[o].l;
  push_down(o);
  int ret;
  if (T[o << 1 | 1].mx > 0) ret = query(o << 1 | 1);
  else ret = query(o << 1);
  push_up(o);
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, m) scanf("%d", b + i);
  build(1, 1, 1e6);
  FOR(i, 1, n) add(1, 1, a[i], 1);
  FOR(i, 1, m) add(1, 1, b[i], -1);
  scanf("%d", &q);
  while (q--) {
    int op, i, x;
    scanf("%d%d%d", &op, &i, &x);
    if (op == 1) {
      add(1, 1, a[i], -1);
      a[i] = x;
      add(1, 1, x, 1);
    } else {
      add(1, 1, b[i], 1);
      b[i] = x;
      add(1, 1, b[i], -1);
    }
    printf("%d\n", query(1));
  }
}