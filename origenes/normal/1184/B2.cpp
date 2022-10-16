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

const int maxn = 112;
const int maxs = 1123;

struct SS {
  int x, a, f;
} s[maxs];

struct Base {
  int x, d;
} b[maxs];

int n, m, S, B, K, H;
int dis[maxn][maxn], match[maxs * 2];
bool vis[maxs * 2];
vector<int> G[maxs];

bool dfs(int u) {
  if (vis[u]) return false;
  vis[u] = true;
  for (auto v : G[u]) if (match[v] == -1 || dfs(match[v])) {
    match[u] = v;
    match[v] = u;
    return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  reset(dis, 0x3f);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    dis[u][v] = dis[v][u] = 1;
  }
  FOR(i, 1, n) dis[i][i] = 0;
  FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) chkmin(dis[i][j], dis[i][k] + dis[k][j]);
  scanf("%d%d%d%d", &S, &B, &K, &H);
  ll ans = ll(S) * H;
  FOR(i, 1, S) scanf("%d%d%d", &s[i].x, &s[i].a, &s[i].f);
  FOR(i, 1, B) scanf("%d%d", &b[i].x, &b[i].d);
  FOR(i, 1, S) FOR(j, 1, B) if (s[i].a >= b[j].d && dis[s[i].x][b[j].x] <= s[i].f) G[i].eb(j + S);
  ll tot = 0;
  reset(match, -1);
  FOR(i, 1, S) if (match[i] == -1) {
    reset(vis, false);
    tot += dfs(i);
  }
  chkmin(ans, tot * K);
  printf("%lld", ans);
}