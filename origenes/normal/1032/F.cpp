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
const int MOD = 998244353;

vector<int> G[maxn];
int n, dp[maxn][3];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int inv(int a) {
  int ret = 1, pw = MOD - 2;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

void dfs(int u, int par) {
  dp[u][0] = dp[u][1] = 1;
  int prod = 1;
  for (int v : G[u]) if (v != par) {
    dfs(v, u);
    dp[u][0] = mul(dp[u][0], add(dp[v][0], dp[v][2]));
    dp[u][1] = mul(dp[u][1], add(dp[v][0], add(dp[v][2], dp[v][2])));
    prod = mul(prod, add(dp[v][0], add(dp[v][2], dp[v][2])));
  }
  for (int v : G[u]) if (v != par) {
    int now = mul(prod, inv(add(dp[v][0], add(dp[v][2], dp[v][2]))));
    dp[u][2] = add(dp[u][2], mul(dp[v][1], now));
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
  dfs(1, 0);
  printf("%d", add(dp[1][0], dp[1][2]));
}