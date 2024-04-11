#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
  int mx, lzy;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void push_down(int o) {
  T[o << 1].lzy += T[o].lzy, T[o << 1].mx += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy, T[o << 1 | 1].mx += T[o].lzy;
  T[o].lzy = 0;
}

void push_up(int o) {
  T[o].mx = max(T[o << 1].mx, T[o << 1 | 1].mx);
}

void add(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mx++;
    T[o].lzy++;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(o << 1, l, r);
  if (r > mi) add(o << 1 | 1, l, r);
  push_up(o);
}

int get(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].mx;
  push_down(o);
  int mi = T[o].l + T[o].r >> 1, ret = 0;
  if (l <= mi) chkmax(ret, get(o << 1, l, r));
  if (r > mi) chkmax(ret, get(o << 1 | 1, l, r));
  return ret;
}

int n, q;
int a[maxn], ans[maxn];
vector<pii> query[maxn];

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    a[i] = i - a[i];
  }
  FOR(i, 1, q) {
    int x, y;
    scanf("%d%d", &x, &y);
    query[n - y].eb(x + 1, i);
  }
  build(1, 1, n);
  if (a[1] == 0) add(1, 1, 1);
  for (auto [l, id] : query[1]) ans[id] = get(1, l, 1);
  FOR(r, 2, n) {
    if (a[r] >= 0 && a[r] <= get(1, 1, 1)) {
      int lo = 1, hi = r;
      while (lo < hi) {
        int mi = lo + hi >> 1;
        if (get(1, mi + 1, hi) >= a[r]) lo = mi + 1;
        else hi = mi;
      }
      add(1, 1, lo);
    }
    for (auto [l, id] : query[r]) ans[id] = get(1, l, r);
  }
  FOR(i, 1, q) printf("%d\n", ans[i]);
}