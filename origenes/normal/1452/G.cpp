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

int n, k, f[maxn], ans[maxn], propagate[maxn];
vector<int> G[maxn], query[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  cin >> k;
  vector<int> a(k);
  REP(i, k) cin >> a[i];
  reset(f, -1);
  queue<int> q;
  for (auto x : a) {
    f[x] = 0;
    q.emplace(x);
  }
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : G[u]) if (f[v] == -1) {
      f[v] = f[u] + 1;
      q.emplace(v);
    }
  }
  FOR(i, 1, n) query[f[i]].eb(i);
  ROF(i, n - 1, 1) {
    queue<pii> Q;
    for (auto u : query[i]) if (propagate[u] < f[u]) {
      if (!ans[u]) ans[u] = i;
      propagate[u] = f[u];
      Q.emplace(f[u], u);
    }
    while (!Q.empty()) {
      auto [w, u] = Q.front(); Q.pop();
      if (!--w) continue;
      for (auto v : G[u]) {
        int nw = min(f[v], w);
        if (propagate[v] < nw) {
          if (!ans[v]) ans[v] = i;
          propagate[v] = nw;
          Q.emplace(nw, v);
        }
      }
    }
  }
  FOR(i, 1, n) cout << ans[i] << ' ';
}