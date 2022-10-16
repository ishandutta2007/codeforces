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

int n, m;
vector<int> G[1 << 17], adj[1 << 17], ans, modify;
int pre[1 << 17], dep[1 << 17];
bool vis[1 << 17];

int bfs(int u) {
  queue<int> q;
  fill(vis + 1, vis + m + 1, false);
  q.emplace(u);
  pre[u] = -1;
  vis[u] = true;
  while (!q.empty()) {
    u = q.front(); q.pop();
    for (auto v : G[u]) if (!vis[v]) {
      vis[v] = true;
      pre[v] = u;
      q.emplace(v);
    }
  }
  return u;
}

bool dfs(int u) {
  vis[u] = true;
  dep[u] = 0;
  for (auto &v : adj[u]) if (vis[v]) {
    v = adj[u].back();
    adj[u].pop_back();
    break;
  }
  for (auto v : adj[u]) {
    if (!dfs(v)) return false;
    chkmax(dep[u], dep[v] + 1);
  }
  if (adj[u].empty()) return true;
  if (adj[u].size() == 1) {
    if (dep[u] > 1) return false;
    modify.eb(u);
  } else if (adj[u].size() == 2) {
    return dep[adj[u][0]] == dep[adj[u][1]];
  } else if (adj[u].size() == 3) {
    sort(all(adj[u]), [](int a, int b) { return dep[a] < dep[b]; });
    if (dep[adj[u][0]] != dep[adj[u][1]]) return false;
    if (dep[adj[u][1]] + 1 != dep[adj[u][2]]) return false;
    modify.eb(u);
  } else return false;
  return modify.size() <= 1;
}

void check(int u) {
  fill(vis + 1, vis + m + 1, false);
  FOR(i, 1, m) adj[i] = G[i];
  modify.clear();
  if (dfs(u)) for (auto v : modify) ans.eb(v);
}

int main() {
  scanf("%d", &n);
  if (n == 2) {
    puts("2\n1 2");
    return 0;
  }
  m = (1 << n) - 2;
  REP(i, m - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, m) if (G[i].size() > 4) {
    puts("0");
    return 0;
  }
  vector<int> path;
  for (int u = bfs(bfs(1)); ~u; u = pre[u]) path.eb(u);
  set<int> candidate;
  FOR(i, -2, 2) {
    int idx = (i + path.size()) / 2;
    if (idx >= 0 && idx < path.size()) {
      candidate.emplace(path[idx]);
      for (auto v : G[path[idx]]) candidate.emplace(v);
    }
  }
  for (auto u : candidate) check(u);
  sort(all(ans));
  uni(ans);
  printf("%d\n", int(ans.size()));
  for (auto u : ans) printf("%d ", u);
}