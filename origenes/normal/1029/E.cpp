#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define reset(a, b) memset(a, b, sizeof(a))
#define _1 first
#define _2 second
#define eb emplace_back
typedef long long ll;
using namespace std;

const int maxn = 212345;
const int inf = 0x3f3f3f3f;

int n, dp[maxn][3];
vector<int> G[maxn];
bool good[maxn];

void dfs(int u, int par) {
  for (int v : G[u]) if (v != par) dfs(v, u);
  if (!good[u]) {
    dp[u][0] = 1, dp[u][2] = 0;
    int tmp[2] = {0, inf};
    for (int v : G[u]) if (v != par) {
      tmp[1] = min(min(tmp[1] + min(dp[v][0], dp[v][1]), tmp[0] + dp[v][0]), inf);
      tmp[0] = min(inf, tmp[0] + dp[v][1]);
      dp[u][2] += dp[v][1];
      dp[u][0] += min(min(dp[v][0], dp[v][1]), dp[v][2]);
      if (dp[u][2] >= inf) dp[u][2] = inf;
    }
    dp[u][1] = min(dp[u][1], tmp[1]);
  } else {
    dp[u][0] = 0;
    for (int v : G[u]) if (v != par)
      dp[u][0] += min(min(dp[v][0], dp[v][1]), dp[v][2]);
  }
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  for (auto v : G[1]) good[v] = true;
  good[1] = true;
  reset(dp, 0x3f);
  dfs(1, 0);
  printf("%d", dp[1][0]);
}