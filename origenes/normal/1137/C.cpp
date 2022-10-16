#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;
const int maxa = 5123456;

vector<int> G[maxn], adj[maxa];
int pre[maxn][51], low[maxn][51], cc[maxn][51], clk, scc_cnt;
char tbl[maxn][51];
int n, m, d, in[maxn], sz[maxa], dp[maxa];
stack<pii> s;

void dfs(int u, int t) {
  pre[u][t] = low[u][t] = ++clk;
  s.emplace(u, t);
  int tt = (t + 1) % d;
  for (int v : G[u]) if (!cc[v][tt]) {
      if (!pre[v][tt]) {
        dfs(v, tt);
        chkmin(low[u][t], low[v][tt]);
      } else chkmin(low[u][t], pre[v][tt]);
    }
  if (low[u][t] == pre[u][t]) {
    scc_cnt++;
    for (;;) {
      int v = s.top()._1;
      tt = s.top()._2; s.pop();
      cc[v][tt] = scc_cnt;
      if (tbl[v][tt] == '1' && in[v] != scc_cnt) {
        in[v] = scc_cnt;
        sz[scc_cnt]++;
      }
      if (v == u && tt == t) break;
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &d);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
  }
  FOR(i, 1, n) scanf("%s", tbl[i]);
  dfs(1, 0);
  FOR(u, 1, n) REP(i, d) for (int v : G[u]) {
        int j = (i == d - 1 ? 0 : i + 1);
        if (cc[u][i] != cc[v][j]) adj[cc[u][i]].eb(cc[v][j]);
      }
  FOR(u, 1, scc_cnt) {
    for (int v : adj[u]) chkmax(dp[u], dp[v]);
    dp[u] += sz[u];
  }
  printf("%d", dp[scc_cnt]);
}