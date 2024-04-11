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

const int maxn = 112345;

struct Seg {
  int l, r;
  int p, mx;
  ll sum;
} T[maxn << 2];

int n, m;
int a[maxn];

void push_up(int o) {
  T[o].sum = T[o << 1].sum + T[o << 1 | 1].sum;
  if (T[o << 1].mx > T[o << 1 | 1].mx) {
    T[o].mx = T[o << 1].mx;
    T[o].p = T[o << 1].p;
  } else {
    T[o].mx = T[o << 1 | 1].mx;
    T[o].p = T[o << 1 | 1].p;
  }
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    T[o].sum = T[o].mx = a[l];
    T[o].p = l;
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  }
}

ll query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].sum;
  ll ret = 0;
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) ret += query(o << 1, l, r);
  if (r > mi) ret += query(o << 1 | 1, l, r);
  return ret;
}

pii get_mx(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return {T[o].mx, T[o].p};
  pii ret = {0, 0};
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) chkmax(ret, get_mx(o << 1, l, r));
  if (r > mi) chkmax(ret, get_mx(o << 1 | 1, l, r));
  return ret;
}

void update(int o, int p, int x) {
  if (T[o].l == T[o].r) {
    T[o].sum = T[o].mx = x;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (p <= mi) update(o << 1, p, x);
  else update(o << 1 | 1, p, x);
  push_up(o);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  build(1, 1, n);
  while (m--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      cout << query(1, l, r) << '\n';
    } else if (type == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      while (true) {
        auto [v, p] = get_mx(1, l, r);
        if (v < x) break;
        update(1, p, v % x);
      }
    } else {
      int k, x;
      cin >> k >> x;
      update(1, k, x);
    }
  }
}