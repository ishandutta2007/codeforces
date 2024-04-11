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
vector<int> G[maxn];
ll dp[maxn], tot, ans;

void dfs1(int u, int par, int dep) {
  dp[u] = 1;
  tot += dep;
  for (auto v : G[u]) if (v != par) {
    dfs1(v, u, dep + 1);
    dp[u] += dp[v];
  }
}

void dfs2(int u, int par, ll pre) {
  chkmax(ans, pre);
  for (auto v : G[u]) if (v != par)
    dfs2(v, u, pre - 2 * dp[v] + dp[1]);
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs1(1, 0, 0);
  dfs2(1, 0, tot);
  printf("%lld", ans + n);
}