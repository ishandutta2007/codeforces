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
const ll inf = 1e18;

inline ll f(pair<ll, ll> coeff, ll x) {
  return coeff._1 * x + coeff._2;
}

inline bool check(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
  double u = double(b._2 - a._2) / (a._1 - b._1);
  double v = double(b._2 - c._2) / (c._1 - b._1);
  return u <= v;
}

struct Hull {
  vector<pair<ll, ll>> q;

  void add(ll k, ll b) {
    if (!q.empty() && q.back()._1 == k) {
      chkmin(b, q.back()._2);
      q.pop_back();
    }
    while (q.size() > 1 && !check(q[q.size() - 2], q.back(), {k, b})) q.pop_back();
    q.eb(k, b);
  }

  ll query(ll x) {
    if (q.empty()) return inf;
    int lo = 0, hi = q.size() - 1;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      if (f(q[mi], x) > f(q[mi + 1], x)) lo = mi + 1;
      else hi = mi;
    }
    return f(q[lo], x);
  }
};

int sz[maxn], n;
ll dp[maxn], ans = inf;
vector<int> G[maxn];

void dfs(int u, int par) {
  sz[u] = 1;
  if (G[u].size() == 1) {
    dp[u] = 1;
    return;
  }
  dp[u] = inf;
  vector<pair<ll, ll>> data;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    sz[u] += sz[v];
    data.eb(sz[v], dp[v] - sz[v] * ll(2 * n - sz[v]));
  }
  for (auto v : G[u]) if (v != par) {
    chkmin(dp[u], dp[v] + sqr(ll(sz[u] - sz[v])));
    chkmin(ans, dp[v] + sqr(ll(n - sz[v])));
  }
  sort(all(data), greater<>());
  Hull hull;
  for (auto now : data) {
    if (!hull.q.empty()) chkmin(ans, sqr(ll(n)) + now._2 + hull.query(now._1));
    hull.add(2 * now._1, now._2);
  }
}

int main() {
  scanf("%d", &n);
  if (n == 2) {
    puts("2");
    return 0;
  }
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) if (G[i].size() > 1) {
    dfs(i, 0);
    break;
  }
  printf("%lld", ll(n) * (n - 1) / 2 + (sqr(ll(n)) - ans) / 2);
}