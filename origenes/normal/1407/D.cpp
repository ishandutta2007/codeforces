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

struct Seg {
  int l, r;
  int mn;
} T[2][maxn << 2];

void build(Seg *T, int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].mn = 1e9;
  if (l < r) {
    int mi = l + r >> 1;
    build(T, o << 1, l, mi);
    build(T, o << 1 | 1, mi + 1, r);
  }
}

void upd(Seg *T, int o, int x, int v) {
  if (T[o].l == T[o].r) {
    T[o].mn = v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) upd(T, o << 1, x, v);
  else upd(T, o << 1 | 1, x, v);
  T[o].mn = min(T[o << 1].mn, T[o << 1 | 1].mn);
}

int query(const Seg *T, int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].mn;
  int mi = T[o].l + T[o].r >> 1, ret = 1e9;
  if (l <= mi) chkmin(ret, query(T, o << 1, l, r));
  if (r > mi) chkmin(ret, query(T, o << 1 | 1, l, r));
  return ret;
}

int n;
int h[maxn], f[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", h + i);
  REP(j, 2) build(T[j], 1, 1, n);
  deque<int> mx, mn;
  f[1] = 0;
  mx.eb(1), mn.eb(1);
  REP(j, 2) upd(T[j], 1, 1, 0);
  FOR(i, 2, n) {
    auto get = [&](deque<int> &q, const function<bool(int, int)> &cmp) -> int {
      int lo = 0, hi = int(q.size()) - 1;
      if (!cmp(h[q.back()], h[i])) lo = hi + 1;
      while (lo < hi) {
        int mi = lo + hi >> 1;
        if (cmp(h[q[mi]], h[i])) hi = mi;
        else lo = mi + 1;
      }
      lo--;
      if (lo < 0) lo++;
      return q[lo];
    };
    int l = get(mn, [](int x, int y) { return x < y; });
    f[i] = query(T[0], 1, l, i - 1) + 1;
    l = get(mx, [](int x, int y) { return x > y; });
    chkmin(f[i], query(T[1], 1, l, i - 1) + 1);
    while (!mn.empty() && h[mn.back()] <= h[i]) {
      upd(T[0], 1, mn.back(), 1e9);
      mn.pop_back();
    }
    mn.eb(i);
    while (!mx.empty() && h[mx.back()] >= h[i]) {
      upd(T[1], 1, mx.back(), 1e9);
      mx.pop_back();
    }
    mx.eb(i);
    REP(j, 2) upd(T[j], 1, i, f[i]);
  }
  printf("%d", f[n]);
}