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
#define lson(o) (o << 1)
#define rson(o) (o << 1 | 1)

const int maxn = 112345;

struct Seg {
  int l, r;
  int mx, mn, fi, se, all, lzy;
} T[maxn << 3];

int n, q, dep[maxn << 1];
char s[maxn << 1];

inline void push_up(int o) {
  T[o].mx = max(T[lson(o)].mx, T[rson(o)].mx);
  T[o].mn = min(T[lson(o)].mn, T[rson(o)].mn);
  T[o].fi = max(T[lson(o)].fi, T[rson(o)].fi);
  chkmax(T[o].fi, T[lson(o)].mx - T[rson(o)].mn * 2);
  T[o].se = max(T[lson(o)].se, T[rson(o)].se);
  chkmax(T[o].se, T[rson(o)].mx - T[lson(o)].mn * 2);
  T[o].all = max(T[lson(o)].all, T[rson(o)].all);
  chkmax(T[o].all, max(T[lson(o)].fi + T[rson(o)].mx, T[rson(o)].se + T[lson(o)].mx));
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    T[o].mx = T[o].mn = dep[l];
    T[o].fi = T[o].se = -dep[l];
    return;
  }
  int mi = l + r >> 1;
  build(lson(o), l, mi);
  build(rson(o), mi + 1, r);
  push_up(o);
}

inline void update(int o, int v) {
  T[o].mx += v;
  T[o].mn += v;
  T[o].fi -= v;
  T[o].se -= v;
  T[o].lzy += v;
}

void update(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    update(o, v);
    return;
  }
  if (T[o].lzy) {
    update(lson(o), T[o].lzy);
    update(rson(o), T[o].lzy);
    T[o].lzy = 0;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(lson(o), l, r, v);
  if (r > mi) update(rson(o), l, r, v);
  push_up(o);
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  FOR(i, 1, 2 * (n - 1)) {
    dep[i] = dep[i - 1];
    if (s[i] == '(') dep[i]++;
    else dep[i]--;
  }
  build(1, 1, 2 * (n - 1));
  printf("%d\n", T[1].all);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    int v = s[x] == '(' ? -2 : 2;
    update(1, x, y - 1, v);
    swap(s[x], s[y]);
    printf("%d\n", T[1].all);
  }
}