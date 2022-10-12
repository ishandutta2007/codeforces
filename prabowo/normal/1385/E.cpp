#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
vector<int> edges[N];

vector<tuple<int, int, int>> dirs;

int vis[N];
int deg[N];

void topo() {
  for (int i = 0; i < n; ++i) {
    vis[i] = -1;
    deg[i] = 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int v: edges[i]) ++deg[v];
  }

  queue<int> q;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }

  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = cnt++;

    for (int v: edges[u]) {
      --deg[v];
      if (deg[v] == 0) {
        q.push(v);
      }
    }
  }
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) edges[i].clear();
  dirs.clear();

  for (int i = 0; i < m; ++i) {
    int t, u, v;
    scanf("%d %d %d", &t, &u, &v);
    --u, --v;

    if (t == 1) {
      edges[u].push_back(v);
    }
    dirs.emplace_back(t, u, v);
  }

  topo();

  for (int i = 0; i < n; ++i) if (vis[i] == -1) {
    return 0 * printf("NO\n");
  }

  printf("YES\n");
  for (tuple<int, int, int> e: dirs) {
    int t, u, v;
    tie(t, u, v) = e;

    if (t == 1) {
      printf("%d %d\n", u+1, v+1);
    } else {
      if (vis[u] < vis[v]) printf("%d %d\n", u+1, v+1);
      else printf("%d %d\n", v+1, u+1);
    }
  }

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