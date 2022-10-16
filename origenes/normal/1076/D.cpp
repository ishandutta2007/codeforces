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

struct Edge {
  int u, v, w;
} e[maxn];

int n, m, k, to;
pii par[maxn];
ll dis[maxn];
vector<int> G[maxn];
set<int> rem;

void dfs(int u) {
  if (to <= 0) return;
  for (int v : G[u]) {
    dfs(v);
    if (to <= 0) return;
  }
  rem.erase(par[u]._2);
  to--;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, m) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    G[e[i].u].eb(i);
    G[e[i].v].eb(i);
  }
  reset(dis, 0x3f);
  dis[1] = 0;
  set<pair<ll, int>> q;
  q.emplace(0, 1);
  while (!q.empty()) {
    auto now = *q.begin(); q.erase(now);
    int u = now._2;
    ll d = now._1;
    if (d > dis[u]) continue;
    for (int id : G[u]) {
      int v = e[id].u == u ? e[id].v : e[id].u, w = e[id].w;
      if (d + w < dis[v]) {
        par[v] = {u, id};
        dis[v] = d + w;
        q.emplace(dis[v], v);
      }
    }
  }
  FOR(i, 2, n) rem.insert(par[i]._2);
  assert(rem.size() == n - 1);
  FOR(i, 1, n) G[i].clear();
  FOR(i, 2, n) G[par[i]._1].eb(i);
  to = int(rem.size()) - k;
  dfs(1);
  printf("%d\n", int(rem.size()));
  for (auto it : rem) printf("%d ", it);
}