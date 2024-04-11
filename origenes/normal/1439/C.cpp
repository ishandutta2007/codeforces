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
  ll lzy, s;
  int len() {
    return r - l + 1;
  }
} T[maxn << 2];

int a[maxn];

void push_up(int o) {
  T[o].s = T[o << 1].s + T[o << 1 | 1].s;
}

void push_down(int o) {
  if (!T[o].lzy) return;
  T[o].s = T[o].len() * T[o].lzy;
  a[T[o].l] = a[T[o].r] = T[o].lzy;
  if (T[o].l < T[o].r) T[o << 1].lzy = T[o << 1 | 1].lzy = T[o].lzy;
  T[o].lzy = 0;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  } else {
    T[o].s = a[l];
  }
}

void update(int o, int r, int y) {
  push_down(o);
  if (r < T[o].l || a[T[o].r] >= y) return;
  if (T[o].r <= r && a[T[o].l] <= y) {
    T[o].lzy = y;
    push_down(o);
    return;
  }
  update(o << 1, r, y);
  update(o << 1 | 1, r, y);
  push_up(o);
}

int query(int o, int l, int &y) {
  push_down(o);
  if (T[o].r < l) return 0;
  if (l <= T[o].l && y >= T[o].s) {
    y -= T[o].s;
    return T[o].len();
  }
  if (a[T[o].r] > y) return 0;
  int ret = query(o << 1, l, y);
  ret += query(o << 1 | 1, l, y);
  return ret;
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
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) update(1, x, y);
    else cout << query(1, x, y) << '\n';
  }
}