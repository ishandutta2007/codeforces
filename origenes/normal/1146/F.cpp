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
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int dp[maxn][2], n;
vector<int> G[maxn];

void dfs(int u) {
  if (G[u].empty()) {
    dp[u][0] = dp[u][1] = 1;
    return;
  }
  for (int v : G[u]) dfs(v);
  vector<vector<int>> dp2(G[u].size() + 1, vector<int>(3));
  dp2[0][0] = 1;
  REP(i, int(G[u].size())) {
    int v = G[u][i];
    REP(j, 3) {
      dp2[i + 1][j] = add(dp2[i + 1][j], mul(dp2[i][j], dp[v][0]));
      if (j < 2) dp2[i + 1][j + 1] = add(dp2[i + 1][j + 1], mul(dp2[i][j], dp[v][1]));
      else dp2[i + 1][j] = add(dp2[i + 1][j], mul(dp2[i][j], dp[v][1]));
    }
  }
  dp[u][0] = add(dp2[G[u].size()][0], dp2[G[u].size()][2]);
  dp[u][1] = add(dp2[G[u].size()][1], dp2[G[u].size()][2]);
}

int main() {
  scanf("%d", &n);
  FOR(i, 2, n) {
    int par;
    scanf("%d", &par);
    G[par].eb(i);
  }
  dfs(1);
  printf("%d", dp[1][0]);
}