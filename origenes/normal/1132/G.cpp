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

const int maxn = 1123456;

struct Seg {
  int l, r, val, lzy;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l != r) {
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
  T[o].val = max(T[o << 1].val + T[o << 1].lzy, T[o << 1 | 1].val + T[o << 1 | 1].lzy);
}

void add(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy++;
    return;
  }
  push_down(o);
  int m = T[o].l + T[o].r >> 1;
  if (l <= m) add(o << 1, l, r);
  if (r > m) add(o << 1 | 1, l, r);
  push_up(o);
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].val + T[o].lzy;
  push_down(o);
  int m = T[o].l + T[o].r >> 1, ret = 0;
  if (l <= m) chkmax(ret, query(o << 1, l, r));
  if (r > m) chkmax(ret, query(o << 1 | 1, l, r));
  push_up(o);
  return ret;
}

deque<pii> q;

void add(int pos, int a) {
  int cnt = 1;
  while (!q.empty()) {
    if (q.back()._1 < a) {
      cnt += q.back()._2;
      q.pop_back();
    } else if (q.back()._1 == a) {
      add(1, pos - cnt + 1, pos);
      q.back()._2 += cnt;
      return;
    } else break;
  }
  q.eb(a, cnt);
  add(1, pos - cnt + 1, pos);
}

void del() {
  if (q.front()._2 == 1) q.pop_front();
  else q.front()._2--;
}

int k, n;
int a[maxn];

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  build(1, 1, 1 << 20);
  FOR(i, 1, k) add(i, a[i]);
  printf("%d", query(1, 1, k));
  FOR(i, k + 1, n) {
    del();
    add(i, a[i]);
    printf(" %d", query(1, i - k + 1, i));
  }
}