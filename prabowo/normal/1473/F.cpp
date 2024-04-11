#include <bits/stdc++.h>
using namespace std;
 
const int N = 3005;
const int INF = 1e9;

struct Dinic {
  int s, t;
  vector<int> edges[N], cap[N], rev[N];
  int dist[N], it[N];
  
  void addEdge(int u, int v, int c) {
    if (u == v) return;
    
    rev[u].push_back(edges[v].size());
    cap[u].push_back(c);
    edges[u].push_back(v);
    
    rev[v].push_back((int) edges[u].size() - 1);
    cap[v].push_back(0);
    edges[v].push_back(u);
  }
  
  bool bfs() {
    queue<int> q;
    q.push(s);
    
    for (int i = 0; i <= t; ++i) dist[i] = -1;
    dist[s] = 0;
    
    while (q.size()) {
      int u = q.front();
      q.pop();
      
      for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        int c = cap[u][i];
        if (dist[v] >= 0 || c == 0) continue;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
    
    return dist[t] >= 0;
  }
  
  int dfs(int u, int f) {
    if (u == t) return f;
    for (; it[u] < edges[u].size(); ++it[u]) {
      int i = it[u];
      int v = edges[u][i];
      int c = cap[u][i];
      if (dist[v] == dist[u] + 1 && c > 0) {
        int flow = dfs(v, min(f, c));
        if (flow > 0) {
          cap[u][i] -= flow;
          cap[v][rev[u][i]] += flow;
          return flow;
        }
      }
    }
    
    return 0;
  }
  
  int maxflow() {
    int ret = 0;
    while (bfs()) {
      for (int i = 0; i <= t; ++i) it[i] = 0;
      while (int flow = dfs(s, INF)) {
        ret += flow;
      }
    }
    
    return ret;
  }
} dinic;

int n;
int a[N], b[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  int ans = 0;
  dinic.s = n; dinic.t = n + 1;
  vector<int> lst(101, -1);
  for (int i = 0; i < n; ++i) {
    if (b[i] < 0) {
      dinic.addEdge(i, dinic.t, -b[i]);
      if (lst[a[i]] != -1) {
        dinic.addEdge(i, lst[a[i]], INF);
      }
      lst[a[i]] = i;
    } else {
      dinic.addEdge(dinic.s, i, b[i]);
      for (int j = 1; j <= a[i]; ++j) {
        if (a[i] % j == 0 && lst[j] != -1) {
          dinic.addEdge(i, lst[j], INF);
        }
      }
      ans += b[i];
    }
  }

  ans -= dinic.maxflow();
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}