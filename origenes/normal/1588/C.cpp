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
  ll mn, lzy;
  int cnt;
} T[2][maxn << 1];

void push_up(Seg *T, int o) {
  T[o].mn = min(T[o << 1].mn, T[o << 1 | 1].mn);
  T[o].cnt = 0;
  if (T[o].mn == T[o << 1].mn) T[o].cnt += T[o << 1].cnt;
  if (T[o].mn == T[o << 1 | 1].mn) T[o].cnt += T[o << 1 | 1].cnt;
}

void push_down(Seg *T, int o) {
  if (T[o].lzy) {
    T[o << 1].mn += T[o].lzy; T[o << 1].lzy += T[o].lzy;
    T[o << 1 | 1].mn += T[o].lzy; T[o << 1 | 1].lzy += T[o].lzy;
    T[o].lzy = 0;
  }
}

void build(Seg *T, int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].lzy = 0;
  if (l < r) {
    int mi = l + r >> 1;
    build(T, o << 1, l, mi);
    build(T, o << 1 | 1, mi + 1, r);
    push_up(T, o);
  } else {
    T[o].mn = 0;
    T[o].cnt = 1;
  }
}

void update(Seg *T, int o, int l, int r, ll x) {
  if (r < T[o].l || l > T[o].r) return;
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mn += x;
    T[o].lzy += x;
    return;
  }
  push_down(T, o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(T, o << 1, l, r, x);
  if (r > mi) update(T, o << 1 | 1, l, r, x);
  push_up(T, o);
}

int query1(Seg *T, int o, int l, int r) {
  if (r < T[o].l || l > T[o].r) return 0;
  if (l <= T[o].l && T[o].r <= r) {
    if (T[o].mn >= 0) return T[o].r;
    if (T[o].l == T[o].r) return T[o].l - 1;
  }
  push_down(T, o);
  int ret = T[o].l - 1, mi = T[o].l + T[o].r >> 1;
  if (l <= mi) {
    chkmax(ret, query1(T, o << 1, l, r));
    if (ret < mi) return ret;
  }
  if (r > mi) chkmax(ret, query1(T, o << 1 | 1, l, r));
  return ret;
}

pair<ll, int> query(Seg *T, int o, int l, int r) {
  if (r < T[o].l || l > T[o].r) return {1e18, 0};
  if (l <= T[o].l && T[o].r <= r) return {T[o].mn, T[o].cnt};
  push_down(T, o);
  ll mn = 1e18;
  int cnt = 0, mi = T[o].l + T[o].r >> 1;
  if (l <= mi) tie(mn, cnt) = query(T, o << 1, l, r);
  if (r > mi) {
    auto [mn2, cnt2] = query(T, o << 1 | 1, l, r);
    if (mn2 > mn) return {mn, cnt};
    if (mn2 < mn) return {mn2, cnt2};
    return {mn, cnt + cnt2};
  }
  return {mn, cnt};
}

int n, a[maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  if (n == 1) {
    cout << (a[1] == 0 ? 1 : 0) << '\n';
    return;
  }
  build(T[1], 1, 1, (n + 1) / 2);
  build(T[0], 1, 1, n / 2);
  ll now = 0, ans = 0;
  FOR(i, 1, n) {
    now = a[i] - now;
    if (i % 2 == 0) update(T[0], 1, i / 2, i / 2, now);
    else update(T[1], 1, (i + 1) / 2, (i + 1) / 2, now);
  }
  FOR(l, 1, n - 1) {
    if (l % 2 == 1) {
      update(T[1], 1, (l + 1) / 2, (n + 1) / 2, a[l - 1]);
      update(T[0], 1, (l + 1) / 2, n / 2, -a[l - 1]);
    } else {
      update(T[0], 1, l / 2, n / 2, a[l - 1]);
      update(T[1], 1, (l + 2) / 2, (n + 1) / 2, -a[l - 1]);
    }
    int l1 = query1(T[1], 1, (l + 2 - l % 2) / 2, (n + 1) / 2);
    l1 = 2 * l1 + 1;
    int l2 = query1(T[0], 1, (l + l % 2) / 2, n / 2);
    l2 = 2 * l2 + 2;
    int en = min(l1, l2) - 1;
    auto [mn, cnt] = query(T[0], 1, (l + l % 2) / 2, en / 2);
    if (mn == 0) ans += cnt;
    tie(mn, cnt) = query(T[1], 1, (l + 2 - l % 2) / 2, (en + 1) / 2);
    if (mn == 0) ans += cnt;
  }
  cout << ans + (a[n] == 0) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
/*
 4
 1 0 1 0
 2
 1 0
 3
 1 1 0
 5
 0 1 0 1 0
 4
 3 0 2 0

 */