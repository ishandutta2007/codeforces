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

const int MOD = 1e9 + 7;
const int maxn = 112345;

vector<int> G[maxn];
int n, anc[maxn][20], ans, dep[maxn];
ll x[maxn], d[maxn][20];

void dfs(int u, int par) {
  anc[u][0] = par;
  d[u][0] = __gcd(x[u], x[par]);
  dep[u] = dep[par] + 1;
  FOR(i, 1, 19) {
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
    d[u][i] = __gcd(d[u][i - 1], d[anc[u][i - 1]][i - 1]);
  }
  for (auto v : G[u]) if (v != par) dfs(v, u);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", x + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  dfs(1, 0);
  FOR(i, 1, n) {
    int u = i;
    ll pre = x[u];
    while (u) {
      int v = u;
      ROF(j, 19, 0) if (dep[anc[u][j]] && __gcd(d[u][j], pre) == pre) {
        u = anc[u][j];
      }
      ans = (ans + (pre % MOD * (dep[v] - dep[u] + 1)) % MOD) % MOD;
      u = anc[u][0];
      pre = __gcd(pre, x[u]);
    }
  }
  printf("%d", ans);
}