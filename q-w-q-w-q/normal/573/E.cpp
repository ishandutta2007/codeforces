#include <chrono>
#include <cstdio>
#include <iostream>
#include <random>

using namespace std;

typedef long long i64;

const int N = 100005;
int n, rt, t;

namespace fhq {
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
unsigned w[N];
int sz[N], lc[N], rc[N], cnt;
i64 lazy0[N], lazy1[N];
i64 v[N], lv[N], rv[N];

int newnode(i64 vv) {
  cnt++;
  w[cnt] = rnd(), sz[cnt] = 1;
  v[cnt] = lv[cnt] = rv[cnt] = vv;
  return cnt;
}

void update(int i) {
  lv[i] = lc[i] ? lv[lc[i]] : v[i];
  rv[i] = rc[i] ? rv[rc[i]] : v[i];
  sz[i] = sz[lc[i]] + sz[rc[i]] + 1;
}
void pushdown(int i) {
  if (lazy0[i]) {
    i64 x = lazy0[i];
    if (lc[i])
      lazy0[lc[i]] += x, v[lc[i]] += x, lv[lc[i]] += x, rv[lc[i]] += x;
    if (rc[i])
      lazy0[rc[i]] += x, v[rc[i]] += x, lv[rc[i]] += x, rv[rc[i]] += x;
    lazy0[i] = 0;
  }
  if (lazy1[i]) {
    i64 x = lazy1[i];
    v[i] += x * sz[lc[i]];
    if (lc[i])
      lazy1[lc[i]] += x, rv[lc[i]] += x * (sz[lc[i]] - 1);
    if (rc[i]) {
      i64 y = x * (sz[lc[i]] + 1);
      lv[rc[i]] += y, rv[rc[i]] += x * (sz[lc[i]] + sz[rc[i]]);
      lazy1[rc[i]] += x;
      lazy0[rc[i]] += y, v[rc[i]] += y;
    }
    lazy1[i] = 0;
  }
}

void split(int i, int t, int &x, int &y) {
  if (!i) {
    x = y = 0;
    return;
  }

  pushdown(i);
  if (sz[lc[i]] + 1 <= t) {
    x = i;
    split(rc[i], t - sz[lc[i]] - 1, rc[x], y);
  } else {
    y = i;
    split(lc[i], t, x, lc[y]);
  }
  update(i);
}
int merge(int i, int j) {
  if (i == 0 || j == 0)
    return i | j;

  pushdown(i), pushdown(j);
  if (w[i] < w[j]) {
    rc[i] = merge(rc[i], j);
    update(i);
    return i;
  }
  lc[j] = merge(i, lc[j]);
  update(j);
  return j;
}

void add(int i, i64 x, int y) {
  lazy0[i] += x, v[i] += x, lv[i] += x, rv[i] += x;
  lazy1[i] += y, rv[i] += 1ll * y * (sz[lc[i]] + sz[rc[i]]);
}

void query(int x) {
  int i = rt, lt = 0;
  i64 vr = -(1ll << 60);

  while (i) {
    pushdown(i);
    if (v[i] + 1ll * x * (lt + sz[lc[i]] + 1) > (rc[i] ? lv[rc[i]] : vr))
      t = lt + sz[lc[i]] + 1, vr = v[i], i = lc[i];
    else
      lt += sz[lc[i]] + 1, i = rc[i];
  }
}

i64 qans(int i) {
  if (!i)
    return 0;

  pushdown(i);
  return max(max(qans(lc[i]), qans(rc[i])), v[i]);
}
} // namespace fhq

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  rt = fhq::newnode(0);
  while (n--) {
    int x;
    cin >> x;
    t = 1 << 30, fhq::query(x);
    int a, b;
    fhq::split(rt, t, a, b);
    int c = fhq::newnode(fhq::rv[a] + 1ll * t * x);
    fhq::add(b, 1ll * (t + 1) * x, x);
    a = fhq::merge(a, c), rt = fhq::merge(a, b);
  }

  cout << fhq::qans(rt);
}