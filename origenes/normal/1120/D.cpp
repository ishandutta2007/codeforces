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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;

int n, c[maxn], par[maxn];
ll dp[maxn][2], s[maxn];
bool vis[maxn][2], sel[maxn];
vector<int> G[maxn];

void dfs(int u) {
  if (par[u] && G[u].size() == 1) {
    dp[u][0] = c[u];
    dp[u][1] = 0;
    return;
  }
  for (int v : G[u]) if (v != par[u]) {
      par[v] = u;
      dfs(v);
      s[u] += dp[v][0];
    }
  for (int v : G[u]) if (v != par[u]) {
      chkmin(dp[u][0], s[u] - dp[v][0] + dp[v][1] + c[u]);
      chkmin(dp[u][1], s[u] - dp[v][0] + dp[v][1]);
    }
  chkmin(dp[u][0], s[u]);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", c + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  reset(dp, 0x3f);
  dfs(1);
  queue<pii> q;
  q.emplace(1, 0); vis[1][0] = true;
  while (!q.empty()) {
    auto now = q.front(); q.pop();
    int u = now._1, need = now._2, pre = -1;
    if (par[u] && G[u].size() == 1) {
      if (!need) sel[u] = true;
      continue;
    }
    if (!need && dp[u][0] == s[u]) {
      for (int v : G[u]) if (v != par[u] && !vis[v][0]) {
          vis[v][0] = true;
          q.emplace(v, 0);
        }
    }
    for (int v : G[u]) if (v != par[u])
        if ((!need && dp[u][0] == s[u] - dp[v][0] + dp[v][1] + c[u]) || (need && dp[u][1] == s[u] - dp[v][0] + dp[v][1])) {
          if (!need) sel[u] = true;
          if (pre < 0) {
            pre = v;
            for (int w : G[u]) if (par[u] != w && w != v && !vis[w][0]) {
                vis[w][0] = true;
                q.emplace(w, 0);
              }
          } else if (pre <= n) {
            if (!vis[pre][0]) {
              vis[pre][0] = true;
              q.emplace(pre, 0);
            }
            pre = n + 1;
          }
          if (!vis[v][1]) {
            vis[v][1] = true;
            q.emplace(v, 1);
          }
        }
  }
  vector<int> ans;
  FOR(i, 1, n) if (sel[i]) ans.eb(i);
  printf("%lld %d\n", dp[1][0], int(ans.size()));
  for (auto it : ans) printf("%d ", it);
}