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

vector<int> G[maxn], adj[maxn];
int c[maxn], ans[maxn], f[maxn];
int n;

void dfs(int u, int par) {
  f[u] = c[u];
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    f[u] += f[v];
  }
}

void build(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    if (c[v] == 1 || f[v] >= 2) adj[v].eb(u);
    if (c[u] == 1 || f[1] - f[v] >= 2) adj[u].eb(v);
    build(v, u);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> c[i];
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  build(1, 0);
  queue<int> q;
  FOR(i, 1, n) if (c[i]) {
    ans[i] = 1;
    q.emplace(i);
  }
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : adj[u]) if (!ans[v]) {
      ans[v] = 1;
      q.emplace(v);
    }
  }
  FOR(i, 1, n) cout << ans[i] << ' ';
}