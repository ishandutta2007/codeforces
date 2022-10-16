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

const int maxn = 512345;

struct Seg {
  int l, r, maxpos;
  ll mx, lzy;
} T[maxn << 3];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r; T[o].maxpos = l;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

inline void push_down(int o) {
  T[o << 1].mx += T[o].lzy; T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].mx += T[o].lzy; T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

inline void push_up(int o) {
  T[o].mx = max(T[o << 1].mx, T[o << 1 | 1].mx);
  T[o].maxpos = T[o << 1].mx > T[o << 1 | 1].mx ? T[o << 1].maxpos : T[o << 1 | 1].maxpos;
}

void add(int o, int l, int r, ll v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mx += v;
    T[o].lzy += v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) add(o << 1, l, r, v);
  if (r > mi) add(o << 1 | 1, l, r, v);
  push_up(o);
}

pair<ll, int> query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return {T[o].mx, T[o].maxpos};
  pair<ll, int> ret = {-1e18, -1};
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) chkmax(ret, query(o << 1, l, r));
  if (r > mi) chkmax(ret, query(o << 1 | 1, l, r));
  push_up(o);
  return ret;
}

int n;
int x[maxn], y[maxn], c[maxn], cost[maxn * 2];
map<int, int> idx;
vector<int> out[maxn * 2];

int main() {
  scanf("%d", &n);
  vector<int> coords; coords.reserve(n * 2);
  FOR(i, 1, n) {
    scanf("%d%d%d", x + i, y + i, c + i);
    coords.eb(x[i]); coords.eb(y[i]);
  }
  sort(all(coords)); uni(coords);
  int m = coords.size();
  REP(i, m) idx[coords[i]] = i + 1;
  build(1, 1, m);
  FOR(j, 1, n) {
    int i = idx[max(x[j], y[j])], o = idx[min(x[j], y[j])];
    out[o].eb(j);
    add(1, i, m, c[j]);
  }
  FOR(i, 1, m - 1) cost[i + 1] = coords[i] - coords[i - 1];
  FOR(i, 1, m) add(1, i, m, -cost[i]);
  ll ans = 0;
  int st = -1, en = -1;
  FOR(i, 1, m) {
    add(1, i, m, cost[i]);
    auto cur = query(1, i, m);
    if (cur._1 > ans) {
      ans = cur._1;
      st = i, en = cur._2;
    }
    for (auto j : out[i]) {
      int st = idx[max(x[j], y[j])];
      add(1, st, m, -c[j]);
    }
  }
  printf("%lld\n", ans);
  if (ans) printf("%d %d %d %d", coords[st - 1], coords[st - 1], coords[en - 1], coords[en - 1]);
  else {
    for (int i = 0; ; i++) if (!idx.count(i)) {
      printf("%d %d %d %d", i, i, i, i);
      break;
    }
  }
}