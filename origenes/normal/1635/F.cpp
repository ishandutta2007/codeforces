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

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].v = 5e18;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void update(int o, int x, ll v) {
  chkmin(T[o].v, v);
  if (T[o].l < T[o].r) {
    int mi = T[o].l + T[o].r >> 1;
    if (x <= mi) update(o << 1, x, v);
    else update(o << 1 | 1, x, v);
  }
}

ll query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].v;
  int mi = T[o].l + T[o].r >> 1;
  ll ret = 5e18;
  if (l <= mi) chkmin(ret, query(o << 1, l, r));
  if (r > mi) chkmin(ret, query(o << 1 | 1, l, r));
  return ret;
}

int n, q;
int x[maxn], w[maxn], L[maxn], R[maxn];
ll ans[maxn];
vector<pii> queries[maxn];
vector<pair<int, ll>> events[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  FOR(i, 1, n) cin >> x[i] >> w[i];
  stack<int> s;
  FOR(i, 1, n) {
    L[i] = -1;
    while (!s.empty() && w[s.top()] > w[i]) s.pop();
    if (!s.empty()) L[i] = s.top();
    s.emplace(i);
  }
  while (!s.empty()) s.pop();
  ROF(i, n, 1) {
    R[i] = -1;
    while (!s.empty() && w[s.top()] > w[i]) s.pop();
    if (!s.empty()) R[i] = s.top();
    s.emplace(i);
  }
  FOR(i, 1, q) {
    int l, r;
    cin >> l >> r;
    queries[r].eb(l, i);
  }
  auto f = [](int i, int j) {
    return abs(x[i] - x[j]) * ll(w[i] + w[j]);
  };
  FOR(i, 1, n) {
    if (L[i] != -1) events[i].eb(L[i], f(L[i], i));
    if (R[i] != -1) events[R[i]].eb(i, f(i, R[i]));
  }
  build(1, 1, n);
  FOR(r, 1, n) {
    for (auto [l, v] : events[r]) update(1, l, v);
    for (auto [l, id] : queries[r]) ans[id] = query(1, l, r);
  }
  FOR(i, 1, q) cout << ans[i] << '\n';
}