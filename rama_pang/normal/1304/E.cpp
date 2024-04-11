#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

int N;
vector<int> adj[MAXN];


int P[MAXN][20];
int depth[MAXN];

void dfs(int n, int p) {
  P[n][0] = p;
  depth[n] = depth[p] + 1;
  for (auto &i : adj[n]) if (i != p) {
    dfs(i, n);
  }
}

int getAnc(int n, int d) {
  for (int j = 19; j >= 0; j--) {
    if (d & (1 << j)) {
      n = P[n][j];
    }
  }
  return n;
}

int lca(int x, int y) {
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  y = getAnc(y, depth[y] - depth[x]);
  for (int j = 19; j >= 0; j--) {
    if (P[x][j] != P[y][j]) {
      x = P[x][j];
      y = P[y][j];
    }
  }
  return x == y ? x : P[x][0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  dfs(1, 0);
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= N; i++) {
      P[i][j] = P[P[i][j - 1]][j - 1];
    }
  }

  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int x, y, a, b, k, w;
    cin >> x >> y >> a >> b >> k;

    w = lca(a, b);
    int path = depth[a] + depth[b] - 2 * depth[w];
    if (path <= k && k % 2 == path % 2) {
      cout << "YES\n";
      continue;
    }
    
    int w1, w2;
    w1 = lca(a, x);
    w2 = lca(b, y);
    path = 1; // use edge (x, y)
    path += depth[a] + depth[x] - 2 * depth[w1];
    path += depth[b] + depth[y] - 2 * depth[w2];
    if (path <= k && k % 2 == path % 2) {
      cout << "YES\n";
      continue;
    }

    w1 = lca(a, y);
    w2 = lca(b, x);
    path = 1; // use edge (x, y)
    path += depth[a] + depth[y] - 2 * depth[w1];
    path += depth[b] + depth[x] - 2 * depth[w2];
    if (path <= k && k % 2 == path % 2) {
      cout << "YES\n";
      continue;
    }
    
    cout << "NO\n";

  }

}