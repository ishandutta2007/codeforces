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

const int maxn = 312345;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

vector<int> G[maxn];
int f[maxn][3], n;

void dfs(int u, int par) {
  f[u][0] = f[u][1] = f[u][2] = 1;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    f[u][0] = mul(f[u][0], f[v][0]);
    f[u][1] = mul(f[u][1], add(add(f[v][0], f[v][1]), f[v][2]));
    f[u][2] = mul(f[u][2], add(f[v][0], f[v][1]));
  }
  f[u][0] = add(add(f[u][1], f[u][2]), MOD - f[u][0]);
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
  printf("%d", add(f[1][0], MOD - 1));
}