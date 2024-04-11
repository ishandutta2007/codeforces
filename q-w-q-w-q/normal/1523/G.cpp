#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
#define pr pair<int, int>
#define mkp(x, y) make_pair(x, y)
#define fst first
#define sec second
using namespace std;
const int N = 50005;
mt19937 rnd(time(0));
int n, m, x, y, ans[N];
vector<pair<pr, pr>> tmp;
namespace fhq {
const int md = 2147483647, sz = 1 << 23;
int cnt, lc[sz], rc[sz], w[sz], qwq;
pr id[sz], v[sz], mx[sz];
inline void update(int x) { mx[x] = max({v[x], mx[lc[x]], mx[rc[x]]}); }
inline int newn(pr x, pr r) {
  cnt++;
  id[cnt] = x, mx[cnt] = v[cnt] = r, w[cnt] = rnd() & md;
  return cnt;
}
inline void split(int i, pr v1, pr v2, int &x, int &y) {
  if (!i) {
    x = y = 0;
    return;
  }
  if (id[i] < v1 || (id[i] == v1 && v[i] <= v2))
    x = i, split(rc[i], v1, v2, rc[x], y);
  else
    y = i, split(lc[i], v1, v2, x, lc[y]);
  update(i);
}
inline int merge(int x, int y) {
  if (x == 0 || y == 0) return x | y;
  if (w[x] <= w[y]) {
    rc[x] = merge(rc[x], y);
    update(x);
    return x;
  }
  lc[y] = merge(x, lc[y]);
  update(y);
  return y;
}
inline int insert(int i, pr v1, pr v2) {
  int x, y, z = newn(v1, v2);
  split(i, v1, v2, x, y);
  return merge(merge(x, z), y);
}
inline int del(int i, pr v1, pr v2) {
  int x, y, z, t;
  split(i, v1, v2, t, z), split(t, v1, mkp(v2.fst, v2.sec - 1), x, y);
  return merge(x, z);
}
inline void query(int i, int x) {
  if (mx[i].fst < x || !i) return;
  if (v[i].fst >= x) tmp.push_back(make_pair(id[i], v[i]));
  query(lc[i], x), query(rc[i], x);
}
inline void ask(int i, int v1, int v2) {
  int x, y;
  split(i, mkp(v1, md), mkp(md, md), x, y);
  query(x, v2);
  merge(x, y);
}
}  // namespace fhq
namespace bits {
using namespace fhq;
int rt[N];
inline int lb(int x) { return x & (-x); }
inline void add(int l, int r, int x, int y) {
  y = min(y, r - l + 1);
  if (y < x) return;
  for (int i = l; i <= n; i += lb(i)) rt[i] = insert(rt[i], mkp(x, y), mkp(r, l));
}
inline void delt(int l, int r, int x, int y) {
  for (int i = l; i <= n; i += lb(i)) rt[i] = del(rt[i], mkp(x, y), mkp(r, l));
}
inline void work(int lf, int rf) {
  tmp.clear();
  int len = rf - lf + 1;
  for (int i = lf; i; i -= lb(i)) ask(rt[i], len, rf);
  for (auto tp : tmp) {
    pr a = tp.fst, b = tp.sec;
    int l = a.fst, r = a.sec, x = b.sec, y = b.fst;
    delt(x, y, l, r);
    add(x, y, len + 1, r), r = min(r, len);
    add(x, lf - 1, l, r);
    add(rf + 1, y, l, r);
    for (int i = l; i <= r; i++) ans[i] += len;
  }
}
}  // namespace bits
int main() {
  cin >> n >> m;
  bits::add(1, n, 1, n);
  while (m--) {
    scanf("%d%d", &x, &y);
    bits::work(x, y);
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}