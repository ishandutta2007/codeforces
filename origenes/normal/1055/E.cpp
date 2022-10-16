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

const int maxn = 1512;

struct Seg {
  int l, r, cnt, lzy;
} T[maxn][maxn << 2];

void build(Seg *T, int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].cnt = T[o].lzy = 0;
  if (l < r) {
    int mi = l + r >> 1;
    build(T, o << 1, l, mi);
    build(T, o << 1 | 1, mi + 1, r);
  }
}

inline void push_down(Seg *T, int o) {
  T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

inline void push_up(Seg * T, int o) {
  T[o].cnt = max(T[o << 1].cnt + T[o << 1].lzy, T[o << 1 | 1].cnt + T[o << 1 | 1].lzy);
}

void add(Seg *T, int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy += v;
    return;
  }
  push_down(T, o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(T, o << 1, l, r, v);
  if (r > mi) add(T, o << 1 | 1, l, r, v);
  push_up(T, o);
}

int query(Seg *T, int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].cnt + T[o].lzy;
  push_down(T, o);
  int mi = T[o].l + T[o].r >> 1, ret = 0;
  if (l <= mi) chkmax(ret, query(T, o << 1, l, r));
  if (r > mi) chkmax(ret, query(T, o << 1 | 1, l, r));
  push_up(T, o);
  return ret;
}

int n, m, s, k, a[maxn];
pii ss[maxn];

bool check(int good) {
  vector<int> mark_in(maxn), mark_out(maxn);
  int tot = 0;
  FOR(i, 1, n) {
    mark_in[i] = tot + 1;
    if (a[i] <= good) tot++;
    mark_out[i] = tot;
  }
  if (tot < k) return false;
  vector<pii> lis;
  FOR(i, 1, s) if (mark_in[ss[i]._1] <= mark_out[ss[i]._2]) lis.eb(mark_in[ss[i]._1], mark_out[ss[i]._2]);
  sort(all(lis), [](pii a, pii b) { return a._1 < b._1 || (a._1 == b._1 && a._2 > b._2);});
  vector<int> st(1, 1), en(1, 0);
  for (auto it : lis) if (it._2 > en.back()) {
    st.eb(it._1);
    en.eb(it._2);
  }
  int no = int(st.size()) - 1, sel = min(m, no), pre = 0;
  REP(i, sel + 1) build(T[i], 1, 0, no);
  FOR(i, 1, no) {
    REP(j, min(sel, i)) add(T[j], 1, 0, pre, en[i] - st[i] - en[i - 1] + st[i - 1]);
    int now = pre + 1;
    while (en[now] < st[i]) {
      REP(j, min(sel, i)) add(T[j], 1, now, now, en[i] - st[i] - en[i - 1] + en[now] + 1);
      now++;
    }
    pre = now - 1;
    if (pre + 1 <= i - 1) REP(j, min(sel, i)) add(T[j], 1, pre + 1, i - 1, en[i] - en[i - 1]);
    REP(j, min(sel, i)) {
      int cur = query(T[j], 1, 0, i - 1);
      add(T[j + 1], 1, i, i, cur);
    }
  }
  return query(T[sel], 1, 1, no) >= k;
}

int main() {
  scanf("%d%d%d%d", &n, &s, &m, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, s) scanf("%d%d", &ss[i]._1, &ss[i]._2);
  vector<int> lis(a + 1, a + n + 1);
  sort(all(lis));
  uni(lis);
  int lo = 0, hi = int(lis.size()) - 1;
  if (!check(lis[hi])) {
    puts("-1");
    return 0;
  }
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(lis[mi])) hi = mi;
    else lo = mi + 1;
  }
  printf("%d", lis[lo]);
}