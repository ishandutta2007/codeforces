#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int MOD = 1000000007;

int n, m;
int cost[N];
vector<int> edge[N];

bool vis[N];
void dfs(int u, vector<int> *edge, vector<int> &order) {
  for (int v: edge[u]) if (!vis[v]) {
    vis[v] = true;
    dfs(v, edge, order);
  }
  order.push_back(u);
}

vector<vector<int>> components;
void scc() {
  vector<int> order;
  for (int u=0; u<n; u++) if (!vis[u]) {
    vis[u] = true;
    dfs(u, edge, order);
  }
    
  vector<int> reverseEdge[n];
  for (int u=0; u<n; u++) 
    for (int v: edge[u])
      reverseEdge[v].push_back(u);
      
  memset(vis, 0, sizeof vis);
  reverse(order.begin(), order.end());
  for (int u: order) {
    if (vis[u]) continue;
    vis[u] = true;
    
    vector<int> component;
    dfs(u, reverseEdge, component);
    components.push_back(component);
  }
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", cost + i);
  
  int u, v;
  scanf("%d", &m);
  for (int i=0; i<m; i++) {
    scanf("%d %d", &u, &v);
    edge[--u].push_back(--v);
  }
  
  scc();
  
  long long sum = 0, ways = 1;
  for (vector<int> component: components) {
    int mini = 2e9;
    int cnt = 0;
    
    for (int u: component) {
      if (cost[u] < mini) {
        mini = cost[u];
        cnt = 1;
      } else if (cost[u] == mini) ++cnt;
    }
    
    sum += mini;
    ways = ways * cnt % MOD;
  }
  
  printf("%lld %lld\n", sum, ways);
  return 0;
}