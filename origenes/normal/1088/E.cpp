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

const int maxn = 312345;

vector<int> G[maxn];
int a[maxn], n, k;
ll dp[maxn], w = -1e16;

void dfs(int u, int par) {
  dp[u] = a[u];
  for (int v : G[u]) if (v != par) {
    dfs(v, u);
    if (dp[v] > 0) dp[u] += dp[v];
  }
  chkmax(w, dp[u]);
}

void dfs2(int u, int par) {
  dp[u] = a[u];
  for (int v : G[u]) if (v != par) {
    dfs2(v, u);
    if (dp[v] > 0) dp[u] += dp[v];
  }
  if (dp[u] == w) {
    k++;
    dp[u] = -1e16;
  }
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  printf("%lld %d", w * k, k);
}