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

int n;
int l[maxn], h[maxn], w[maxn];
bool vis[maxn];
vector<int> G[maxn];
vector<pii> edges;

void dfs1(int u, int par) {
  h[u] = l[u] ? 0 : 1e9;
  for (auto v : G[u]) if (v != par) {
    dfs1(v, u);
    edges.eb(u, v);
    chkmin(h[u], h[v] + 1);
  }
}

void dfs2(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    edges.eb(v, u);
    chkmin(h[v], h[u] + 1);
    dfs2(v, u);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> l[i];
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  vector<int> stages;
  FOR(u, 1, n) for (auto v : G[u]) if (h[u] == h[v]) {
    vis[u] = vis[v] = true;
    stages.eb(h[u]);
  }
  FOR(i, 1, n) w[i] = h[i];
  sort(all(stages), greater<>());
  uni(stages);
  for (auto stage : stages) {
    vector<int> d(n + 1, -1e9);
    FOR(i, 1, n) if (h[i] == stage && vis[i]) d[i] = 0;
    for (auto [u, v] : edges) if (h[u] >= h[v]) chkmax(d[u], min(d[v], 0) + (h[u] == h[v] ? -1 : 1));
    FOR(i, 1, n) if (d[i] >= 0) chkmin(w[i], stage);
  }
  FOR(i, 1, n) cout << 2 * h[i] - w[i] << ' ';
}