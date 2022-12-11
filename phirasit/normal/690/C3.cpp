/*
TASK: o58_apr23_avgdist
LANG: C++
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 200010;
const int LG_N = 20;

struct edge {
  int v;
  int c;
  edge(int _v, int _c = 1)
    : v(_v), c(_c) {}
};

vector<int> adjC[N];
int pass[N], sz[N], PC[N];
int root;

pair<int, int> Path[N][2];
int P[N][LG_N], H[N];
int dis[N];
int inside[N];

vector<edge> adj[N];
int n;
int ans = 0;

void dfs_sz(int u, int p) {
  if(pass[u]) {
    sz[u] = 0;
    return;
  }
  sz[u] = 1;
  for(edge e : adj[u]) {
    if(e.v == p) {
      continue;
    }
    dfs_sz(e.v, u);
    sz[u] += sz[e.v];
  }
}
void dfsC(int u, int p) {
  if(pass[u]) {
    return;
  }

  dfs_sz(u, p);
  int fs = u;

  while(true) {
    int nx = -1;
    for(edge e : adj[u]) {
      if(sz[e.v] < sz[u] and 2 * sz[e.v] >= sz[fs]) {
        nx = e.v;
      }
    }
    if(nx != -1) {
      u = nx;
    }else {
      break;
    }
  }

  pass[u] = 1;
  PC[u] = p;
  if(p != -1) {
    adjC[p].emplace_back(u);
  }else {
    root = u;
  }
  for(edge e : adj[u]) {
    dfsC(e.v, u);
  }
}
void dfsLCA(int u, int p, int d, int h) {
  dis[u] = d;
  H[u] = h;
  P[u][0] = p;
  for(int i = 1;i < LG_N;i++) {
    P[u][i] = P[P[u][i-1]][i-1];
  }
  for(edge e : adj[u]) {
    if(e.v == p) {
      continue;
    }
    dfsLCA(e.v, u, d + e.c, h + 1);
  }
}
int LCA(int u, int v) {
  if(H[u] < H[v]) {
    swap(u, v);
  }
  for(int i = LG_N-1;i >= 0;i--) {
    if(H[P[u][i]] >= H[v]) {
      u = P[u][i];
    }
  }
  if(u == v) {
    return u;
  }
  for(int i = LG_N-1;i >= 0;i--) {
    if(P[u][i] != P[v][i]) {
      u = P[u][i];
      v = P[v][i];
    }
  }
  return P[u][0];
}
double dist(int u, int v) {
  return dis[u] + dis[v] - 2.0 * dis[LCA(u, v)];
}
void add(int u ) {
  int v = u, ls = u;
  while(v != -1) {
    int d = dist(v, u);
    if ( ls == Path[v][0].first ) {
      Path[v][0].second = max ( Path[v][0].second, d );
    } else if ( ls == Path[u][1].first ) {
      Path[v][1].second = max ( Path[v][1].second, d );
      if ( Path[v][1].second > Path[v][1].first ) {
        swap( Path[v][0], Path[v][1] );
      }
    } else if ( d > Path[v][0].second ) {
      Path[v][1] = Path[v][0];
      Path[v][0] = { ls, d };
    } else if ( d > Path[v][1].second ) {
      Path[v][1] = { ls, d };
    }
    if ( inside[v] ) {
      ans = max( ans, Path[v][0].second + Path[v][1].second );
    }
    // cout << u << " " << v << " " << d << endl;
    // cout << u << " # " << v << " " << inside[v] << " " << Path[v][0].first << ", " << Path[v][0].second << " " << Path[v][1].first << ", " << Path[v][1].second << endl;
    ls = v;
    v = PC[v];
  }
}
int main() {

  cin >> n;
  for ( int i = 2 ; i <= n ; i++ ) {
    int p;
    cin >> p;
    adj[p].emplace_back(edge(i, 1));
    adj[i].emplace_back(edge(p, 1));
  }
  
  dfsC(1, -1);
  dfsLCA(1, 1, 0, 0);

  for(int i = 1;i <= n;i++) {
    Path[i][0] = Path[i][1] = { 0, 0 };
  }


  inside[1] = 1;
  add(1);
  for ( int i = 2 ; i <= n ; i++ ) {
    inside[i] = 1;
    add(i);
    cout << ans << " ";
  }
  cout << endl;

  return 0;
}