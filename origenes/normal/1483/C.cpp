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
int h[maxn], b[maxn], pre[maxn];
ll f[maxn];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r, T[o].v = -1e18;
  int mi = l + r >> 1;
  if (l < r) {
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

ll query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].v;
  ll ret = -1e18;
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) chkmax(ret, query(o << 1, l, r));
  if (r > mi) chkmax(ret, query(o << 1 | 1, l, r));
  return ret;
}

void update(int o, int x, ll v) {
  if (T[o].l == T[o].r) {
    T[o].v = v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) update(o << 1, x, v);
  else update(o << 1 | 1, x, v);
  T[o].v = max(T[o << 1].v, T[o << 1 | 1].v);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> h[i];
  FOR(i, 1, n) cin >> b[i];
  build(1, 0, n - 1);
  stack<int> s;
  s.emplace(0);
  FOR(i, 1, n) {
    while (h[s.top()] > h[i]) s.pop();
    pre[i] = s.top();
    s.emplace(i);
  }
  update(1, 0, 0);
  FOR(i, 1, n) {
    f[i] = query(1, pre[i], i - 1) + b[i];
    if (pre[i]) chkmax(f[i], f[pre[i]]);
    if (i != n) update(1, i, f[i]);
  }
  cout << f[n];
}