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

const int maxn = 212345;

struct Seg {
  int l, r;
  int sum, lzy;
} T[maxn << 2];

void push_down(int o) {
  if (T[o].lzy != -1) {
    T[o << 1].sum = T[o].lzy * (T[o << 1].r - T[o << 1].l + 1);
    T[o << 1 | 1].sum = T[o].lzy * (T[o << 1 | 1].r - T[o << 1 | 1].l + 1);
    T[o << 1].lzy = T[o << 1 | 1].lzy = T[o].lzy;
    T[o].lzy = -1;
  }
}

void push_up(int o) {
  T[o].sum = T[o << 1].sum + T[o << 1 | 1].sum;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].lzy = -1;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

int query(int o, int p) {
  if (T[o].l == T[o].r) return T[o].sum;
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (p <= mi) return query(o << 1, p);
  return query(o << 1 | 1, p);
}

void update(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].sum = (T[o].r - T[o].l + 1) * v;
    T[o].lzy = v;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(o << 1, l, r, v);
  if (r > mi) update(o << 1 | 1, l, r, v);
  push_up(o);
}

int find_next(int o, int p, int v) {
  if (p < T[o].l) {
    if (T[o].sum == (T[o].r - T[o].l + 1) * v) return T[o].l;
    if (T[o].sum == (T[o].r - T[o].l + 1) * (1 - v)) return 1e9;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1, ret = 1e9;
  if (p < mi) chkmin(ret, find_next(o << 1, p, v));
  if (ret != 1e9) return ret;
  return find_next(o << 1 | 1, p, v);
}

int find_last(int o) {
  if (T[o << 1 | 1].sum > 0) {
    if (T[o << 1 | 1].sum == T[o << 1 | 1].r - T[o << 1 | 1].l + 1) return T[o].r;
    return find_last(o << 1 | 1);
  }
  if (T[o << 1].sum == T[o << 1].r - T[o << 1].l + 1) return T[o << 1].r;
  return find_last(o << 1);
}

void inc(int p) {
  if (query(1, p) == 0) {
    update(1, p, p, 1);
    return;
  }
  auto r = find_next(1, p, 0);
  update(1, p, r - 1, 0);
  update(1, r, r, 1);
}

void dec(int p) {
  if (query(1, p) == 1) {
    update(1, p, p, 0);
    return;
  }
  auto r = find_next(1, p, 1);
  update(1, p, r - 1, 1);
  update(1, r, r, 0);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  build(1, 1, 2e5 + 100);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  FOR(i, 1, n) {
    cin >> a[i];
    inc(a[i]);
  }
  while (q--) {
    int k, l;
    cin >> k >> l;
    dec(a[k]);
    inc(l);
    a[k] = l;
    cout << find_last(1) << '\n';
  }
}