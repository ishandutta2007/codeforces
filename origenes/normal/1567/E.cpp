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
  int lb, rb;
  ll v;
} T[maxn << 2];
int a[maxn];

Seg unite(Seg lc, Seg rc) {
  Seg ret;
  ret.l = lc.l, ret.r = rc.r;
  ret.v = lc.v + rc.v;
  ret.lb = rc.lb, ret.rb = lc.rb;
  if (a[lc.r] <= a[rc.l]) {
    ret.v += ll(lc.r - lc.lb + 1) * (rc.rb - rc.l + 1);
    if (rc.lb == rc.l) ret.lb = lc.lb;
    if (lc.rb == lc.r) ret.rb = rc.rb;
  }
  return ret;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    T[o].v = 1;
    T[o].lb = T[o].rb = l;
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    T[o] = unite(T[o << 1], T[o << 1 | 1]);
  }
}

void update(int o, int x, int v) {
  if (T[o].l == T[o].r) {
    a[x] = v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) update(o << 1, x, v);
  else update(o << 1 | 1, x, v);
  T[o] = unite(T[o << 1], T[o << 1 | 1]);
}

Seg query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o];
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi && r > mi) return unite(query(o << 1, l, r), query(o << 1 | 1, l, r));
  if (l <= mi) return query(o << 1, l, r);
  if (r > mi) return query(o << 1 | 1, l, r);
  assert(0);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, q;
  cin >> n >> q;
  FOR(i, 1, n) cin >> a[i];
  build(1, 1, n);
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) update(1, l, r);
    else {
      auto ans = query(1, l, r);
      cout << ans.v << '\n';
    }
  }
}