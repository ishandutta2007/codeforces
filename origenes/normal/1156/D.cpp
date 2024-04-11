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

bool vis[2][maxn];
vector<int> cc[2][maxn], G[maxn][2];
int n, in[maxn];
ll ans;

void dfs(int u, bool c, vector<int> &cur) {
  cur.eb(u);
  vis[c][u] = true;
  for (auto v : G[u][c]) if (!vis[c][v]) dfs(v, c, cur);
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    G[u][c].eb(v);
    G[v][c].eb(u);
  }
  REP(i, 2) FOR(j, 1, n) if (!vis[i][j]) {
    dfs(j, i, cc[i][j]);
    if (i == 1) for (auto k : cc[i][j]) in[k] = j;
  }
  REP(i, 2) FOR(j, 1, n) ans += ll(cc[i][j].size()) * (int(cc[i][j].size()) - 1);
  FOR(i, 1, n) if (!cc[0][i].empty()) {
    int sz = 0;
    for (auto j : cc[0][i]) sz += int(cc[1][in[j]].size()) - 1;
    ans += sz * ll(cc[0][i].size() - 1);
  }
  printf("%lld", ans);
}