// for a query
// first find the midpoint of two vertices and split the tree
// into two parts that each part belongs to one vertice
//
// obs: theres always one part which is a subtree
//
// Solution:
//   Call the vertice that "dominate a subtree" v and the other vertice u
//
//   Calculate sum of distance of all vertices to u = x
//   Calculate sum of distance of vertices in "subtree" to u = y
//   Calculate sum of distances of vertices in "subtree" to v = z
//
//   answer: x - y + z
//
//   to calculate x: root lifting technique
//   to calculate y: the LCA of vertices in "subtree" to u is fixed, so calculate
//   the sums of depth is enough
//
//   to calculate z:
//
//     distances = move all the other vertices to root, and move to v
//     then for each vertices on the way from root to v, we will minus by
//     subtree size * 2.

//
// upd: wrongly read statement

#include<bits/stdc++.h>

using namespace std;

const int LG = 20;
const int MAXN = 200010;
const int INF = -MAXN-MAXN-MAXN;

struct segtree{
  int T[MAXN << 2];

  #define mid ((l + r) >> 1)
  #define lc (x << 1)
  #define rc (lc | 1)

  segtree() {
//    memset(T, sizeof T, -60);
    for(int i = 0; i < (MAXN << 2); ++i) T[i] = INF;
  }

  void modify(int x, int l, int r, int p, int val) {
    if(l == r) {
      T[x] = val;
      return;
    }
    if(p <= mid) modify(lc, l, mid, p, val);
    else modify(rc, mid + 1, r, p, val);
    T[x] = max(T[lc], T[rc]);
  }

  int query(int x, int l, int r, int u, int v) {
    if(u > v) return INF;
    if(l > v || r < u) return INF;
    if(l >= u && r <= v) return T[x];
    return max(query(lc, l, mid, u, v), query(rc, mid + 1, r, u, v));
  }

  #undef mid
  #undef lc
  #undef rc
}seg;

int n;
int sub[MAXN];
int height[MAXN];
int jump[MAXN][LG];
vector<int> g[MAXN];

int answer[MAXN];

void dfs_prepare(int v, int p) {
  for(int s : g[v]) if(s != p) {
    height[s] = height[v] + 1;
    jump[s][0] = v;
    for(int j = 1; j < LG; ++j) jump[s][j] = jump[jump[s][j - 1]][j - 1];
    dfs_prepare(s, v);
  }
}

int LCA(int u, int v) {
  if(height[u] < height[v]) swap(u, v);
  for(int i = LG - 1; i >= 0; --i) if(height[jump[u][i]] >= height[v]) u = jump[u][i];
  if(u == v) return u;
  for(int i = LG - 1; i >= 0; --i) if(jump[u][i] != jump[v][i]) {
    u = jump[u][i];
    v = jump[v][i];
  }
  return jump[u][0];
}

int tin[MAXN], tout[MAXN], tnow;

void dfs_time(int v, int p) {
  tin[v] = ++tnow;
  for(int s : g[v]) if(s != p) {
    dfs_time(s, v);
  }
  tout[v] = tnow;
}

vector<pair<int, pair<int, int>>> queries[MAXN];

int del[MAXN];
int child[MAXN];
vector<int> adj[MAXN];

void dfs_prepare2(int v, int p) {
  child[v] = 1;
  for(int s : adj[v]) if(s != p && !del[s]) {
    dfs_prepare2(s, v);
    child[v] += child[s];
  }
}

int dfs_centroid(int v, int p, int root) {
  for(int s : adj[v]) if(s != p && !del[s]) {
    if(child[s] * 2 >= child[root]) return dfs_centroid(s, v, root);
  }
  return v;
}

void add(int v, int h) {
  seg.modify(1, 1, n, tin[v], h);
}

void dfs_add(int v, int p, int h) {
  for(int s : adj[v]) if(s != p && !del[s]) {
    dfs_add(s, v, h + 1);
  }
  add(v, h);
}

void query(int v, int h) {
  for(auto &q : queries[v]) {
    answer[q.first] = max(answer[q.first], h + seg.query(1, 1, n, q.second.first, q.second.second));
  }
}

void dfs_query(int v, int p, int h) {
  for(int s : adj[v]) if(s != p && !del[s]) {
    dfs_query(s, v, h + 1);
  }
  query(v, h);
}

void solve(int v) {
  for(int s : adj[v]) if(!del[s]) {
    dfs_query(s, v, 1);
    dfs_add(s, v, 1);
  }
  query(v, 0);
  add(v, 0);
  for(int s : adj[v]) if(!del[s]) {
    dfs_add(s, v, INF);
    dfs_query(s, v, 1);
  }
  add(v, INF);
}

void go(int v) {
  dfs_prepare2(v, -1);
  v = dfs_centroid(v, -1, v);
  del[v] = 1;
  solve(v);
  for(int s : adj[v]) if(!del[s]) {
    go(s);
  }
}


int correct[MAXN];

int dist(int u, int v) {
  int p = LCA(u, v);
  return height[u] + height[v] - height[p];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n;


  for(int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_prepare(0, -1);
  dfs_time(0, -1);


  int m; cin >> m;



  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    if(height[u] > height[v]) swap(u, v);

    int p = LCA(u, v), pv = v;
    for(int i = LG - 1; i >= 0; --i) {
      int np = jump[pv][i];
      if(height[np] <= height[p]) continue;
      if(height[v] - height[np] >= height[np] - 2 * height[p] + height[u]) continue;
      pv = np;
    }
    queries[v].emplace_back(i, make_pair(tin[pv], tout[pv]));
    queries[u].emplace_back(i, make_pair(1, tin[pv] - 1));
    queries[u].emplace_back(i, make_pair(tout[pv] + 1, n));
  }


  go(0);

  for(int i = 0; i < m; ++i) cout << answer[i] << "\n";
  return 0;
}