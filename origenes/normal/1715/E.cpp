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

inline ll f(pair<ll, ll> coeff, ll x) {
  return coeff._1 * x + coeff._2;
}

inline bool check(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
  double u = double(b._2 - a._2) / (a._1 - b._1);
  double v = double(b._2 - c._2) / (c._1 - b._1);
  return u <= v;
}

struct Hull {
  const ll inf = 1e18;

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

void dijkstra(vector<vector<pii>> &G, vector<ll> &f) {
  int n = size(G);
  vector<bool> vis(n);
  set<pair<ll, int>> q;
  REP(i, n) q.emplace(f[i], i);
  while (!q.empty()) {
    auto [_, u] = *q.begin(); q.erase(q.begin());
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : G[u]) if (f[v] > f[u] + w) {
      f[v] = f[u] + w;
      q.emplace(f[v], v);
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pii>> G(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  vector<ll> f(n, 1e15);
  f[0] = 0;
  dijkstra(G, f);
  REP(i, k) {
    Hull hull;
    hull.add(0, 0);
    FOR(j, 1, n - 1) hull.add(-2 * j, f[j] + sqr(ll(j)));
    REP(j, n) f[j] = hull.query(j) + sqr(ll(j));
    dijkstra(G, f);
  }
  for (auto x : f) cout << x << ' ';
}