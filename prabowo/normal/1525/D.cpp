#include <bits/stdc++.h>
using namespace std;
 
const int N = 5005;
const int INF = 1e9;
 
int n;
int a[N];
 
struct MinCostFlow {
  struct Edge {
    int to, cap, flow, rev;
    int cost;
  };
 
  int source, sink;
  vector<Edge> edge[N];
  int pot[N];
 
  void reset() {
    for (int i = 0; i < N; ++i) {
      edge[i].clear();
      pot[i] = 0;
    }
  }
 
  void addEdge(int u, int v, int c, int f) {
    Edge edge1 = {v, f, 0, (int) edge[v].size(), c};
    Edge edge2 = {u, 0, 0, (int) edge[u].size(), -c};
    edge[u].push_back(edge1);
    edge[v].push_back(edge2);
  }
 
  pair<int, int> dijkstra() {
    // pq{cost, flow}
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, source));
 
    vector<bool> vis(sink + 1, false);
    vector<int> dist(sink + 1, INF);
    vector<pair<int, int>> prev(sink + 1);
    
    dist[source] = 0;
    
    while (pq.size()) {
      pair<int, int> now = pq.top();
      int u = now.second;
      pq.pop();
      
      if (vis[u]) continue;
      vis[u] = 1;
      
      for (int i = 0; i < edge[u].size(); ++i) {
        Edge e = edge[u][i];
        int v = e.to;
        
        if (e.cap - e.flow == 0) continue;
        
        int d = dist[u] + e.cost + pot[u] - pot[v];
        if (d < dist[v]) {
          dist[v] = d;
          pq.push(make_pair(-d, v));
          prev[v] = make_pair(u, i);
        }
      }
    }
    
    for (int i = 0; i <= sink; ++i) pot[i] += dist[i];
    
    if (dist[sink] == INF) return make_pair(0, 0);
 
    int f = INF;
    int sum = 0;
    int now = sink;
    
    while (now ^ source) {
      int u = prev[now].first;
      int i = prev[now].second;
      f = min(f, edge[u][i].cap - edge[u][i].flow);
      sum += edge[u][i].cost;
      now = u;
    }
    
    now = sink;
    while (now ^ source) {
      int u = prev[now].first;
      int i = prev[now].second;
      edge[u][i].flow += f;
      edge[now][edge[u][i].rev].flow -= f;
      now = u;
    }
    
    return make_pair(f, sum * f);
  };
  
  // {flow, cost}
  pair<int, int> minCostMaxFlow() {
    pair<int, int> tmp = dijkstra();
    pair<int, int> ret = make_pair(0, 0);
    while (tmp.first) {
      ret.first += tmp.first;
      ret.second += tmp.second;
      tmp = dijkstra();
    }
    return ret;
  }
} mcmf;
 
int solve() {
  scanf("%d", &n);
 
  vector<int> zeros, ones;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 1) ones.push_back(i);
    else zeros.push_back(i);
  }
 
  mcmf.source = n; mcmf.sink = n + 1;
 
  for (int i = 0; i < ones.size(); ++i) mcmf.addEdge(mcmf.source, ones[i], 0, 1);
  for (int i = 0; i < zeros.size(); ++i) mcmf.addEdge(zeros[i], mcmf.sink, 0, 1);

  for (int i = 1; i < n; ++i) {
    mcmf.addEdge(i - 1, i, 1, n);
    mcmf.addEdge(i, i - 1, 1, n);
  }
 
  printf("%d\n", mcmf.minCostMaxFlow().second);
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