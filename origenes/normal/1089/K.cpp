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

const int maxn = 1123456;
const int upp = 1e6;

struct Seg {
  int l, r;
  ll val, lzy;
} T[maxn << 2];

inline void push_up(int o) {
  T[o].val = max(T[o << 1].val, T[o << 1 | 1].val);
}

inline void push_down(int o) {
  T[o << 1].val += T[o].lzy, T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].val += T[o].lzy, T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = T[o].l + T[o].r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  } else T[o].val = l;
}

void add(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].val += v;
    T[o].lzy += v;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(o << 1, l, r, v);
  if (r > mi) add(o << 1 | 1, l, r, v);
  push_up(o);
}

ll query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].val;
  push_down(o);
  ll ret = 0;
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) chkmax(ret, query(o << 1, l, r));
  if (r > mi) chkmax(ret, query(o << 1 | 1, l, r));
  return ret;
}

char op[5];
int q;
ll fen[maxn];
pii event[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int x, int d) {
  while (x <= upp) {
    fen[x] += d;
    x += lowbit(x);
  }
}

ll sum(int x) {
  ll ret = 0;
  while (x) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

ll suf(int x) {
  if (x > upp) return 0;
  return sum(upp) - sum(x - 1);
}

int main() {
  scanf("%d", &q);
  build(1, 1, upp);
  FOR(i, 1, q) {
    scanf("%s", op);
    if (op[0] == '?') {
      int t; scanf("%d", &t);
      ll ans = query(1, 1, t) - suf(t + 1);
      printf("%lld\n", ans - t);
    } else if (op[0] == '+') {
      int t, d;
      scanf("%d%d", &t, &d);
      add(1, 1, t, d);
      event[i] = {t, d};
      add(t, d);
    } else {
      int id;
      scanf("%d", &id);
      add(1, 1, event[id]._1, -event[id]._2);
      add(event[id]._1, -event[id]._2);
    }
  }
}