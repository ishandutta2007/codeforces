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
  ll v;
} T[maxn << 2];

int n;
ll a[maxn], fen[maxn], ans[maxn], pre[maxn];

void add(int x, int v) {
  while (x <= 3e5) {
    fen[x] += v;
    x += x & -x;
  }
}

ll sum(int x) {
  ll ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= x & -x;
  }
  return ret;
}

ll sum(int l, int r) {
  return sum(r) - sum(l - 1);
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l != r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void update(int o, int l, int r, ll v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].v += v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(o << 1, l, r, v);
  if (r > mi) update(o << 1 | 1, l, r, v);
}

ll query(int o, int x) {
  if (T[o].l == T[o].r) return T[o].v;
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) return T[o].v + query(o << 1, x);
  else return T[o].v + query(o << 1 | 1, x);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  build(1, 1, 3e5);
  FOR(i, 1, n) {
    pre[i] = pre[i - 1] + a[i];
    ans[i] = ans[i - 1];
    ans[i] += pre[i - 1] + (i - 1) * a[i];
    ll tmp = 0;
    for (int j = 1; j * a[i] <= 3e5; j++) tmp += j * sum(j * a[i], min((j + 1) * a[i] - 1, ll(3e5)));
    ans[i] -= tmp * a[i];
    ans[i] -= query(1, a[i]);
    add(a[i], 1);
    for (int j = 1; j * a[i] <= 3e5; j++) update(1, j * a[i], min((j + 1) * a[i] - 1, ll(3e5)), a[i] * j);
  }
  FOR(i, 1, n) cout << ans[i] << ' ';
}