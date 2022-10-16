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

int n, m;
vector<int> G[maxn], adj[maxn];
int x[maxn], y[maxn], deg[maxn], clk[maxn], clkt[maxn];
char mark[maxn];

void dfs(const vector<int> *G, int u, int t, int *clk) {
  clk[u] = t;
  for (auto v : G[u]) if (clk[v] > t) dfs(G, v, t, clk);
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    scanf("%d%d", x + i, y + i);
    adj[x[i]].eb(y[i]); deg[y[i]]++;
    G[y[i]].eb(x[i]);
  }
  iota(clk + 1, clk + n + 1, 1);
  iota(clkt + 1, clkt + n + 1, 1);
  queue<int> q;
  FOR(i, 1, n) if (!deg[i]) q.emplace(i);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : adj[u]) if (!--deg[v]) q.emplace(v);
  }
  FOR(i, 1, n) if (deg[i]) {
    puts("-1");
    return 0;
  }
  int ans = 0;
  FOR(i, 1, n) {
    mark[i] = 'A';
    if (clk[i] < i || clkt[i] < i) mark[i] = 'E';
    if (mark[i] == 'A') ans++;
    dfs(G, i, i, clk);
    dfs(adj, i, i, clkt);
  }
  printf("%d\n%s", ans, mark + 1);
}