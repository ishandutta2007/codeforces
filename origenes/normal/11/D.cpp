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

const int maxn = 19;

int n, m;
bool G[maxn][maxn];
int vis[maxn][1 << maxn];
ll dp[maxn][1 << maxn], ans;

ll dfs(int now, int mask, int st) {
  if (vis[now][mask] == st + 1) return dp[now][mask];
  ll ret = 0;
  FOR(i, st, n - 1) if (G[now][i]) {
    if (i == st) ret += __builtin_popcount(mask) > 2;
    else if (!(mask & (1 << i))) ret += dfs(i, mask | (1 << i), st);
  }
  vis[now][mask] = st + 1;
  return dp[now][mask] = ret;
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    G[u][v] = G[v][u] = true;
  }
  REP(i, n) ans += dfs(i, 1 << i, i);
  printf("%lld", ans / 2);
}