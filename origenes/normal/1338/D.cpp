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

const int maxn = 112345;

vector<int> G[maxn];
int n, f[maxn][2], ans;

void dfs(int u, int par) {
  f[u][0] = 1;
  f[u][1] = G[u].size() - (par > 0);
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    chkmax(ans, f[u][0] + f[v][1]);
    chkmax(ans, f[u][1] - 1 + (par > 0) + f[v][0]);
    chkmax(ans, f[u][1] - 1 + (par > 0) + f[v][1]);
    chkmax(f[u][0], f[v][1] + 1);
    chkmax(f[u][1], f[v][0] + int(G[u].size()) - (par > 0) - 1);
    chkmax(f[u][1], f[v][1] + int(G[u].size()) - (par > 0) - 1);
  }
  chkmax(ans, f[u][0]);
  chkmax(ans, f[u][1] + (par > 0));
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  printf("%d", ans);
}