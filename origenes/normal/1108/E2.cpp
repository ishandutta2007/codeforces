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
const int maxm = 312;
const int inf = 0x3f3f3f3f;

struct Seg {
  int l, r, val, lzy;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r, T[o].val = inf;
  if (l < r) {
    int m = l + r >> 1;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
  }
}

inline void push_down(int o) {
  T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

inline void push_up(int o) {
  T[o].val = min(T[o << 1].val + T[o << 1].lzy, T[o << 1 | 1].val + T[o << 1 | 1].lzy);
}

void add(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy += v;
    return;
  }
  int m = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= m) add(o << 1, l, r, v);
  if (r > m) add(o << 1 | 1, l, r, v);
  push_up(o);
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].val + T[o].lzy;
  int m = T[o].l + T[o].r >> 1, ret = inf;
  push_down(o);
  if (l <= m) chkmin(ret, query(o << 1, l, r));
  if (r > m) chkmin(ret, query(o << 1 | 1, l, r));
  push_up(o);
  return ret;
}

int a[maxn], c[maxm][2], n, m;

int main() {
  build(1, 1, 1 << 17);
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    add(1, i, i, a[i] - inf);
  }
  FOR(i, 1, m) {
    scanf("%d%d", &c[i][0], &c[i][1]);
    add(1, c[i][0], c[i][1], -1);
  }
  int ans = -1, sel = 0;
  FOR(i, 1, n) {
    FOR(j, 1, m) {
      if (c[j][0] == i) add(1, c[j][0], c[j][1], 1);
      else if (c[j][1] == i - 1) add(1, c[j][0], c[j][1], -1);
    }
    int now = query(1, 1, n);
    if (ans < a[i] - now) {
      ans = a[i] - now;
      sel = i;
    }
  }
  printf("%d\n", ans);
  vector<int> res;
  FOR(i, 1, m) if (sel < c[i][0] || c[i][1] < sel) res.eb(i);
  printf("%d\n", int(res.size()));
  for (auto it : res) printf("%d ", it);
}