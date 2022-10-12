#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
int w[N];
int demand[N];

vector<pair<int, int>> edges[N];
bool vis[N];
bool eaten[N*2];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &w[i]);
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    ++demand[u], ++demand[v];

    edges[u].push_back({v, i});
    edges[v].push_back({u, i});
  }

  vector<int> ans;
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (demand[i] <= w[i]) {
      q.push(i);
      vis[i] = true;
    }
  }

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (pair<int, int> p: edges[u]) {
      int v = p.first;
      int idx = p.second;

      if (eaten[idx]) continue;
      eaten[idx] = true;
      ans.push_back(p.second);
      --demand[v]; --demand[u];
      if (demand[v] <= w[v] && !vis[v]) {
        vis[v] = true;
        q.push(v);
      }
    }
  }

  if (ans.size() != m) return 0 * printf("DEAD\n");

  reverse(ans.begin(), ans.end());
  printf("ALIVE\n");
  for (int u: ans) printf("%d ", u+1);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}