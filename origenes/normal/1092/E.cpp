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

const int maxn = 1123;
const int inf = 0x3f3f3f3f;

int n, m, dis[2][maxn];
vector<int> G[maxn], now;
bool vis[maxn];

int bfs(int r, int *dis) {
  queue<int> q;
  q.emplace(r);
  dis[r] = 0;
  int tail;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    tail = u;
    for (int v : G[u]) if (dis[v] > dis[u] + 1) {
      dis[v] = dis[u] + 1;
      q.emplace(v);
    }
  }
  return tail;
}

void dfs(int u) {
  vis[u] = true;
  now.eb(u);
  for (int v : G[u]) if (!vis[v]) dfs(v);
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  reset(dis, 0x3f);
  vector<pii> cc, ans;
  FOR(i, 1, n) if (!vis[i]) {
    now.clear();
    dfs(i);
    int u = bfs(i, dis[0]), v = bfs(u, dis[1]);
    for (auto j : now) dis[0][j] = inf;
    bfs(v, dis[0]);
    int d = dis[1][v], o;
    for (auto j : now) if (dis[0][j] == d / 2 && dis[1][j] == d - d / 2) o = j;
    cc.eb(d, o);
  }
  nth_element(cc.begin(), cc.end() - 1, cc.end());
  REP(i, int(cc.size()) - 1) {
    G[cc[i]._2].eb(cc.back()._2);
    G[cc.back()._2].eb(cc[i]._2);
    ans.eb(cc[i]._2, cc.back()._2);
  }
  reset(dis, 0x3f);
  int o = bfs(bfs(cc.back()._2, dis[0]), dis[1]);
  printf("%d\n", dis[1][o]);
  for (auto it : ans) printf("%d %d\n", it._1, it._2);
}