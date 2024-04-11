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

const int maxn = 112345;

int n, k;
vector<pii> G[maxn];
bool vis[maxn];
int deg[maxn], dis[maxn], cnt[maxn];

bool check(int good) {
  reset(dis, 0);
  reset(vis, 0);
  queue<int> q;
  int gg = 0, ins = n;
  FOR(i, 1, n) {
    deg[i] = G[i].size();
    if (deg[i] == 1) q.push(i);
    else if (deg[i] > 2) gg++;
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto _ : G[u]) if (!vis[_._2]) {
      int v = _._2, d = _._1;
      if (dis[u] + d > good) break;
      chkmax(dis[v], dis[u] + d);
      vis[u] = true;
      if (deg[v] == 3) gg--;
      deg[v]--;
      if (deg[v] == 1) q.push(v);
      ins--;
      break;
    }
  }
  return !gg && ins <= k;
}

int main() {
  scanf("%d%d", &n, &k);
  if (n == 1) {
    puts("0");
    return 0;
  }
  REP(i, n - 1) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    G[u].eb(d, v);
    G[v].eb(d, u);
  }
  int lo = 0, hi = 1e9 + 5;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  printf("%d", lo);
}