// First build the graph of rest places
//
// How:
//   1. bfs from the rest vertices, get the closest rest vertices to each vertices
//   2. For each edge (u, v) on the tree, connect close[u] and close[v] if dist[u] + dist[v] <= k
//
// A vacation from u to v will always contain all the vertices on the path from u to v.
// which is also u to LCA(u, v) and LCA(u, v) to p
//
// if dist(u, v) <= k, done
// else theres always a need for entering a rest
//
// considering vertice u, on its way to its parent.
// If we enter some rest place in some branch of some ancestor p and go back with more energy => we can always do that
// So for each vertex find the first ancestor that gives the profit by entering it
// The remaining problem is from a connected componenet of rest places, find the shortest path to some vertex v
// => Centroid decomposition
//
//  I dont know if this sol is too overkill, cause it looks stupid as fuck
//
// But not so many people solved it during the contest anyway
//
//
// More on finding the cloest profit ancestor
//
// => h[v] > h[anc] + f[anc].first
//
// deque on tree?

// So in the end i decided to implement fenwick tree + stack instead, works fine
// The remaining part in the editorial is good, but annoying to think about
// Hence, I implemented centroid decomp for the last part, seems buggy to code but good practice anw

#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;
const int MAXN = maxn;
const int LG = 20;
const int inf = 1e9 + 7;

struct Dsu{
  vector<int> par;
  Dsu(){}
  Dsu(int N){
    par.resize(N, -1);
  }
  int find(int x) {
    return par[x] < 0 ? x : par[x] = find(par[x]);
  }
  void join(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
  }
};

int n, k, r;
vector<int> rests;
vector<int> g[maxn];
vector<int> adj[maxn];
pair<int, int> f[maxn];

void bfs_prepare() {
  memset(f, 60, sizeof f);
  queue<int> que;

  for(int v : rests) {
    f[v] = make_pair(0, v);
    que.push(v);
  }


  while(!que.empty()) {
    int v = que.front(); que.pop();
    for(int s : g[v]) {
      if(f[s].first > f[v].first + 1) {
        f[s] = make_pair(f[v].first + 1, f[v].second);
        que.push(s);
      }
    }
  }
}

Dsu dsu;

void build_span() {
  dsu = Dsu(n);
  for(int u = 0; u < n; ++u) {
    for(int v : g[u]) {
      if(f[u].first + f[v].first + 1 > k) continue;
      dsu.join(f[u].second, f[v].second);
    }
  }
}

int height[maxn];
pair<int, int> up[maxn];
vector<pair<int, int>> bit[maxn];

void upd(pair<int, int> &u, pair<int, int> v) {
  if(u.first == -1) {
    u = v;
    return;
  }
  if(v.first != -1 && height[v.first] > height[u.first]) u = v;
}

void dfs_anc(int v, int p) {
  up[v] = make_pair(-1, -1);
  for(int x = height[v]; x > 0; x -= x & -x) {
    if(!bit[x].empty()) upd(up[v], bit[x].back());
  }

  if(up[v].first != -1) {
    int anc = up[v].first;
    if(height[v] - height[anc] + f[anc].first > k) {
      up[v] = make_pair(-1, -1);
    }
    if(up[v].first != -1) up[v].first = height[up[v].first];
  }

  for(int x = height[v] + f[v].first + 1; x < maxn; x += x & -x) {
    bit[x].emplace_back(v, f[v].second);
  }

  for(int s : g[v]) if(s != p) {
    height[s] = height[v] + 1;
    dfs_anc(s, v);
  }
  for(int x = height[v] + f[v].first + 1; x < maxn; x += x & -x) {
    bit[x].pop_back();
  }
}

int jump[maxn][LG];

void dfs_prepare(int v, int p) {
  for(int s : g[v]) if(s != p) {
    jump[s][0] = v;
    for(int j = 1; j < LG; ++j) jump[s][j] = jump[jump[s][j - 1]][j - 1];
    dfs_prepare(s, v);
  }
}

int LCA(int u, int v) {
  if(height[u] < height[v]) swap(u, v);
  for(int i = LG - 1; i >= 0; --i) {
    if(height[jump[u][i]] >= height[v]) u = jump[u][i];
  }
  if(u == v) return v;
  for(int i = LG - 1; i >= 0; --i) {
    if(jump[u][i] != jump[v][i]) {
      u = jump[u][i];
      v = jump[v][i];
    }
  }
  return jump[u][0];
}

int DIST(int u, int v) {
  int p = LCA(u, v);
  return height[u] + height[v] - 2 * height[p];
}

int answer[maxn];
vector<pair<int, int>> queries[maxn];


int del[MAXN];
int child[MAXN];
int best_dist[maxn];

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

void calc(int v, int len) {
  for(auto &q : queries[v]) {
    if(len + best_dist[q.first] <= k) answer[q.second] = 1;
  }
}

void add(int v, int len) {
  best_dist[dsu.find(v)] = min(best_dist[dsu.find(v)], len);
}

void remov(int v) {
  best_dist[dsu.find(v)] = inf;
}

void dfs_calc(int v, int p, int len) {
  calc(v, len);
  for(int s : adj[v]) if(s != p && !del[s]) {
    dfs_calc(s, v, len + 1);
  }
}


void dfs_add(int v, int p, int len) {
  add(v, len);
  for(int s : adj[v]) if(s != p && !del[s]) {
    dfs_add(s, v, len + 1);
  }
}

void dfs_del(int v, int p) {
  remov(v);
  for(int s : adj[v]) if(s != p && !del[s]) {
    dfs_del(s, v);
  }
}

void solve(int v) {
  for(int s : g[v]) if(!del[s]) {
    dfs_calc(s, v, 1);
    dfs_add(s, v, 1);
  }
  calc(v, 0);
  dfs_del(v, -1);

  add(v, 0);
  reverse(g[v].begin(), g[v].end());
  for(int s : g[v]) if(!del[s]) {
    dfs_calc(s, v, 1);
    dfs_add(s, v, 1);
  }
  dfs_del(v, -1);
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


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> k >> r;
  for(int i = 0; i + 1 < n; ++i) {
    int u, v; cin >> u >> v;
    g[--u].push_back(--v);
    g[v].emplace_back(u);
  }

  for(int i = 0; i < n; ++i) adj[i] = g[i];

  for(int i = 0; i < r; ++i) {
    int v; cin >> v;
    rests.push_back(--v);
  }


  bfs_prepare();
  build_span();
  dfs_anc(0, -1);
  dfs_prepare(0, -1);

  int q; cin >> q;
  for(int i = 0; i < q; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    if(DIST(u, v) <= k) {
      answer[i] = 1;
      continue;
    }

    int p = LCA(u, v);
    if(up[u].first == -1) swap(u, v);
    if(up[u].first < up[v].first) swap(u, v);
    if(up[u].first < height[p]) continue;

    queries[v].emplace_back(dsu.find(up[u].second), i);
  }

  memset(best_dist, 60, sizeof best_dist);

  go(0);

  for(int i = 0; i < q; ++i) cout << (answer[i] ? "YES" : "NO") << "\n";


  return 0;
}