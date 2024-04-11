#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
vector<int> edges[N];

int d[N];
void bfs() {
  queue<int> q;
  vector<bool> vis(n, false);
  vis[0] = true;
  q.push(0);
  d[0] = 0;

  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : edges[u]) {
      if (vis[v]) continue;
      vis[v] = true;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
}

int memo[N];
int dfs(int u) {
  if (~memo[u]) return memo[u];

  int mini = d[u];
  for (int v : edges[u]) {
    if (d[v] > d[u]) mini = min(mini, dfs(v));
    else mini = min(mini, d[v]);
  }

  return memo[u] = mini;
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) edges[i].clear(), memo[i] = -1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edges[u].push_back(v);
  }

  bfs();

  // for (int i = 0; i < n; ++i) cerr << d[i] << " "; cerr << endl;

  for (int i = 0; i < n; ++i) printf("%d ", dfs(i));
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}