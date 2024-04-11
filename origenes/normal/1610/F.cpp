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

const int maxn = 112345;

vector<int> G[maxn][3], chain[maxn];
vector<pii> G2[maxn];
int n, m, tot;
int x[maxn], y[maxn], w[maxn], dir[maxn];
bool par[maxn][3], vis[maxn];

void go(int s, int w) {
  tot++;
  int u = s;
  while (true) {
    while (!G[u][w].empty() && vis[G[u][w].back()]) G[u][w].pop_back();
    if (G[u][w].empty()) break;
    int e = G[u][w].back();
    vis[e] = true; chain[tot].eb(e);
    int v = x[e] ^ y[e] ^ u;
    par[u][w] ^= true; par[v][w] ^= true;
    u = v;
  }
  if (chain[tot].empty()) {
    tot--;
    return;
  }
  G2[s].eb(u, tot);
  G2[u].eb(s, -tot);
}

void dfs(int u) {
  while (!G2[u].empty() && vis[abs(G2[u].back()._2)]) G2[u].pop_back();
  if (G2[u].empty()) return;
  auto [v, e] = G2[u].back();
  if (e < 0) {
    e = -e;
    reverse(all(chain[e]));
  }
  vis[e] = true;
  for (auto i : chain[e]) {
    dir[i] = u == x[i] ? 1 : 2;
    u = u ^ x[i] ^ y[i];
  }
  dfs(v);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, m) {
    cin >> x[i] >> y[i] >> w[i];
    par[x[i]][w[i]] ^= true;
    par[y[i]][w[i]] ^= true;
    G[x[i]][w[i]].eb(i);
    G[y[i]][w[i]].eb(i);
  }
  int ans = 0;
  FOR(i, 1, n) if (par[i][1]) ans++;
  FOR(i, 1, n) FOR(j, 1, 2) if (par[i][j]) go(i, j);
  FOR(i, 1, n) FOR(j, 1, 2) go(i, j);
  FOR(i, 1, m) vis[i] = false;
  FOR(i, 1, n) if (G2[i].size() % 2 == 1) dfs(i);
  FOR(i, 1, n) dfs(i);
  cout << ans << '\n';
  FOR(i, 1, m) cout << dir[i];
}