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

vector<int> G[maxn], D[maxn];
ll f[maxn], a[maxn];
int dep[maxn];
int n, d;

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  chkmax(d, dep[u]);
  D[dep[u]].eb(u);
  for (auto v : G[u]) if (v != par) dfs(v, u);
}

void solve() {
  cin >> n;
  d = 0;
  FOR(i, 1, n) {
    G[i].clear();
    D[i].clear();
    dep[i] = f[i] = 0;
  }
  FOR(i, 2, n) {
    int v; cin >> v;
    G[v].eb(i);
    G[i].eb(v);
  }
  FOR(i, 2, n) cin >> a[i];
  dfs(1, 0);
  ROF(i, d, 2) {
    ll pmx = -1e18, nmx = -1e18, amn = 1e18, amx = -1e18;
    for (auto u : D[i]) {
      chkmax(pmx, f[u] + a[u]);
      chkmax(nmx, f[u] - a[u]);
      chkmin(amn, a[u]);
      chkmax(amx, a[u]);
    }
    for (auto u : D[i - 1]) for (auto v : G[u]) if (dep[v] == dep[u] + 1) {
      chkmax(f[u], f[v] + abs(amn - a[v]));
      chkmax(f[u], f[v] + abs(amx - a[v]));
      chkmax(f[u], pmx - a[v]);
      chkmax(f[u], nmx + a[v]);
    }
  }
  cout << f[1] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}