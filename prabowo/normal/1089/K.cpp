#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ft first
#define sc second

int ti[300005], no;

struct _d {
  ll lim;
  ll lubang;
  ll l;
  ll r;
  ll total_lubang;

  _d() {}

  _d(ll lim, ll lubang, ll total_lubang, ll l, ll r) : lim(lim), lubang(lubang), total_lubang(total_lubang), l(l), r(r) {}

  _d(_d L, _d R) {
    l = L.l;
    r = R.r;
    if (L.lim == -1 && R.lim == -1) {
      lim = -1;
      lubang = L.lubang + R.lubang;
      total_lubang = L.total_lubang + R.total_lubang;
      return;
    }
    ll tembus = max(0ll, L.lim - R.l);
    if (R.lim == -1) {
      lim = L.lim;
      lubang = L.lubang;
      
      total_lubang = L.total_lubang + max(0ll, R.total_lubang - tembus);
      return;
    }
    lubang = L.total_lubang + max(0ll, R.lubang - tembus);

    total_lubang = L.total_lubang + max(0ll, R.total_lubang - tembus);
    if (tembus <= R.lubang) {
      lim = R.lim;
    } else {
      lim = R.lim + tembus - R.lubang;
    }
  }
};

_d seg[4000005];
int ql, qv;

void build(int id, int l, int r) {
  if (l == r) {
    seg[id] = _d(-1, 1, 1, l, r);
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  seg[id] = _d(seg[id * 2], seg[id * 2 + 1]);
}

_d query(int id, int l, int r) {
  if (r <= ql) return seg[id];
  int mid = (l + r) / 2;
  _d res = query(id * 2, l, mid);
  if (ql > mid) res = _d(res, query(id * 2 + 1, mid + 1, r));
  // printf("query %d %d %d, ", id, l, r), res.print();
  return res;
}

void query() {
  scanf("%d", &ql);
  printf("%lld\n", max(0ll, query(1, 0, 1000000).lim - ql));
}

void update(int id, int l, int r) {
  if (l == r) {
    seg[id] = _d(l + qv, 0, 0, l, r);
    // printf("update %d %d %d, ", id, l, r), seg[id].print();
    return;
  }
  int mid = (l + r) / 2;
  if (ql <= mid) update(id * 2, l, mid);
  else update(id * 2 + 1, mid + 1, r);
  seg[id] = _d(seg[id * 2], seg[id * 2 + 1]);
  // printf("update %d %d %d, ", id, l, r), seg[id].print();
}

void update() {
  scanf("%d%d", &ql, &qv);
  ti[no] = ql;
  update(1, 0, 1000000);
}

void cancel(int id, int l, int r) {
  if (l == r) {
    seg[id] = _d(-1, 1, 1, l, r);
    return;
  }
  int mid = (l + r) / 2;
  if (ql <= mid) cancel(id * 2, l, mid);
  else cancel(id * 2 + 1, mid + 1, r);
  seg[id] = _d(seg[id * 2], seg[id * 2 + 1]);
}

void cancel() {
  scanf("%d", &ql);
  ql = ti[ql];
  cancel(1, 0, 1000000);
}

int main() {
  build(1, 0, 1000000);
  int q;
  scanf("%d", &q);
  char cmd[2];
  while (q--) {
    ++no;
    scanf("%s", cmd);
    if (cmd[0] == '?') query();
    else if (cmd[0] == '+') update();
    else cancel();
  }
}