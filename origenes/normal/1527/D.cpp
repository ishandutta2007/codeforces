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

vector<int> G[maxn];
int n, clk;
int sz[maxn], in[maxn], out[maxn], p[maxn];
bool vis[maxn];
ll ans[maxn];

void dfs(int u, int par) {
  in[u] = ++clk;
  p[u] = par;
  sz[u] = 1;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    if (u) ans[0] += ll(sz[u]) * sz[v];
    sz[u] += sz[v];
  }
  out[u] = clk;
}

void solve() {
  cin >> n;
  clk = 0;
  REP(i, n) G[i].clear();
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  REP(i, n + 1) ans[i] = 0;
  dfs(0, -1);
  REP(i, n + 1) vis[i] = false;
  vis[0] = true;
  int j = 1;
  while (p[j]) {
    vis[j] = true;
    j = p[j];
  }
  vis[j] = true;
  ll tot = 1;
  for (auto v : G[0]) {
    if (v != j) {
      ans[1] += tot * sz[v];
      tot += sz[v];
    } else {
      ans[1] += tot * (sz[v] - sz[1]);
      tot += sz[v] - sz[1];
    }
  }
  int h = 0, t = 1;
  bool bad = false;
  FOR(i, 2, n - 1) if (!vis[i]) {
    int k = i;
    while (!vis[k]) {
      vis[k] = true;
      k = p[k];
    }
    ll sz1 = sz[h], sz2 = sz[t];
    if (k == h) sz1 -= sz[i];
    else if (k == t) sz2 -= sz[i];
    if (h == 0) ans[i] = (sz1 - sz[j]) * sz2;
    else ans[i] = sz1 * sz2;
    if (k == h) h = i;
    else if (k == t) t = i;
    else {
      bad = true;
      break;
    }
  }
  if (!bad) ans[n] = 1;
  REP(i, n + 1) cout << ans[i] << ' ';
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}