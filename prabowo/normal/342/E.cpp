#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int LN = 17;

int n, m;
vector<int> edges[N];

namespace Centroid {

int par_centroid[N];
int size[N];
bool removed[N];

void compute_subtree(int u, int p=-1) {
  size[u] = 1;
  for (int v: edges[u]) {
    if (v == p || removed[v]) continue;
    compute_subtree(v, u);
    size[u] += size[v];
  }
}

int find_centroid(int u) {
  compute_subtree(u);
  int tree_size = size[u];
  
  bool found = false;
  while (!found) {
    found = true;
    for (int v: edges[u]) {
      if (removed[v] || size[v] > size[u]) continue;
      if (size[v] > tree_size/2) {
        found = false;
        u = v;
        break;
      }
    }
  }
  
  return u;
}

int build_centroid_tree(int u) {
  u = find_centroid(u);
  removed[u] = true;

  for (int v: edges[u]) {
    if (!removed[v]) {
      v = build_centroid_tree(v);

      par_centroid[v] = u;
    }
  }

  return u;
}

}

namespace LCA {
  
int depth[N];
int par[LN][N];

void dfs(int u, int p) {
  par[0][u] = p;
  for (int v: edges[u]) {
    if (v == p) continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

void build_lca() {
  depth[0] = 0;  
  dfs(0, 0);
  
  for (int i=1; i<LN; i++) for (int j=0; j<n; j++) {
    par[i][j] = par[i-1][par[i-1][j]];
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  while (depth[u] != depth[v]) {
    u = par[__builtin_ctz(depth[u] - depth[v])][u];
  }
  
  if (u == v) return u;
  for (int i=LN-1; i>=0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  
  return par[0][u];
}

int dist(int u, int v) {
  return depth[u] + depth[v] - depth[lca(u, v)] * 2;
}

}

using namespace Centroid;
using namespace LCA;

void read() {
  scanf("%d %d", &n, &m);
  for (int i=1; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}

void solve() {
  int mini[n];
  for (int i=0; i<n; i++) {
    mini[i] = n;
  }
  
  build_lca();
  
  int root_centroid = build_centroid_tree(0);
  par_centroid[root_centroid] = -1;
    
  auto update = [&](int u) {
    for (int v = u; v != -1; v = par_centroid[v]) {
      mini[v] = min(mini[v], dist(v, u));
    }
  };
  
  auto query = [&](int u) {
    int v = u;
    int ret = n;
    for (int v = u; v != -1; v = par_centroid[v]) {
      ret = min(ret, mini[v] + dist(v, u));
    }
    
    return ret;
  };
  
  update(0);
  
  while (m--) {
    int t, u;
    scanf("%d %d", &t, &u);
    --u;
    
    if (t == 1) {
      update(u);
    } else if (t == 2) {
      printf("%d\n", query(u));
    }
  }
}

int main() {
  read();
  solve();
  return 0;
}