#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, k;
vector<int> edges[N];

int par[N], depth[N];
int col[N];

pair<int, int> cyc;

vector<int> c[2];

void bfs(int u) {
  for (int i = 0; i < n; ++i) col[i] = -1;
  queue<int> q;
  q.push(u);
  col[u] = 0;
  depth[u] = 0;
  par[u] = u;

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int v: edges[u]) {
      if (col[v] != -1 && col[v] != 1 - col[u]) {
        cyc = make_pair(u, v);
        return;
      }

      if (col[v] != -1) continue;

      col[v] = 1 - col[u];
      q.push(v);
      par[v] = u;
      depth[v] = depth[u] + 1;
    }

    c[col[u]].push_back(u);
    if (c[col[u]].size() >= (k+1) / 2) return;
  }
}

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  cyc = {-1, -1};
  bfs(0);

  if (cyc == make_pair(-1, -1)) {
    if (c[0].size() >= (k + 1) / 2) {
      printf("1\n");
      for (int i = 0; i < (k+1) / 2; ++i) {
        printf("%d ", c[0][i] + 1);
      }
      return 0 * printf("\n");
    }

    if (c[1].size() >= (k + 1) / 2) {
      printf("1\n");
      for (int i = 0; i < (k+1) / 2; ++i) {
        printf("%d ", c[1][i] + 1);
      }
      return 0 * printf("\n");
    }
  }

  // cerr << cyc.first << " " << cyc.second << endl;

  vector<int> ans1, ans2;
  {
    int u, v;
    tie(u, v) = cyc;

    if (depth[u] < depth[v]) swap(u, v);

    while (depth[u] != depth[v]) {
      ans1.push_back(u);
      u = par[u];
    }

    while (u != v) {
      ans1.push_back(u); u = par[u];
      ans2.push_back(v); v = par[v];
    }

    ans1.push_back(u);
  }

  reverse(ans2.begin(), ans2.end());

  printf("2\n%d\n", (int) ans1.size() + (int) ans2.size());
  for (int u: ans1) printf("%d ", u + 1);
  for (int u: ans2) printf("%d ", u + 1);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}