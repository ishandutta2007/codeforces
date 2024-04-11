#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;

vector<int> edge[N << 3];
vector<int> weight[N << 3];

long long dist[N << 3];

int cnt;
struct SegTree1 {
  int idx[N << 2];
  
  void build(int node, int l, int r) {
    if (l == r) {
      idx[node] = l;
      edge[idx[node - 1 >> 1]].push_back(l);
      weight[idx[node - 1 >> 1]].push_back(0);
      return;
    }
    
    idx[node] = cnt++;
    edge[idx[node - 1 >> 1]].push_back(idx[node]);
    weight[idx[node - 1 >> 1]].push_back(0);
  
    int mid = l + r >> 1;
    build(node*2 + 1, l, mid+0);
    build(node*2 + 2, mid+1, r);
  }
  
  void update(int node, int l, int r, int a, int b, int u, int w) {
    if (l > b || r < a) return;
    if (l >= a && r <= b) {
      edge[u].push_back(idx[node]);
      weight[u].push_back(w);
      return;
    }
    
    int mid = l + r >> 1;
    update(node*2 + 1, l, mid+0, a, b, u, w);
    update(node*2 + 2, mid+1, r, a, b, u, w);
  }
} tree1;

struct SegTree2 {
  int idx[N << 2];
  
  void build(int node, int l, int r) {
    if (l == r) {    
      idx[node] = l;
      edge[l].push_back(idx[node - 1 >> 1]);
      weight[l].push_back(0);
      
      return;
    }
    
    idx[node] = cnt++;
    edge[idx[node]].push_back(idx[node - 1 >> 1]);
    weight[idx[node]].push_back(0);
  
    int mid = l + r >> 1;
    build(node*2 + 1, l, mid+0);
    build(node*2 + 2, mid+1, r);
  }
  
  void update(int node, int l, int r, int a, int b, int u, int v, int w) {
    if (l > b || r < a) return;
    if (l >= a && r <= b) {
      tree1.update(0, 1, n, u, v, idx[node], w);
      return;
    }
    
    int mid = l + r >> 1;
    update(node*2 + 1, l, mid+0, a, b, u, v, w);
    update(node*2 + 2, mid+1, r, a, b, u, v, w);
  }
} tree2;

int main() {
  int q, s;
  scanf ("%d %d %d", &n, &q, &s);
  
  cnt = n + 1;
  
  tree2.build(0, 1, n); 
  tree1.build(0, 1, n); // printEdges();
  
  edge[0].clear();
  
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      tree2.update(0, 1, n, u, u, v, v, w);
    } else if (t == 2) {
      int u, a, b, w;
      scanf("%d %d %d %d", &u, &a, &b, &w);
      tree2.update(0, 1, n, u, u, a, b, w);
    } else if (t == 3) {
      int u, a, b, w;
      scanf("%d %d %d %d", &u, &a, &b, &w);
      tree2.update(0, 1, n, a, b, u, u, w);
    }
  }
  
  priority_queue< pair<long long, int> > pq;
  pq.push({0, s});
  memset(dist, -1, sizeof dist);
  
  while (pq.size()) {
    int u = pq.top().second;
    long long d = -pq.top().first;
    pq.pop();
    
    if (dist[u] != -1) continue;
    dist[u] = d;
    
    for (int i=0; i<edge[u].size(); i++) {
      int v = edge[u][i];
      int w = weight[u][i];
      
      if (dist[v] != -1) continue;
      pq.push({-d - w, v});
    }
  }
  
  printf("%lld", dist[1]);
  for (int i=2; i<=n; i++) printf(" %lld", dist[i]); printf("\n");
  
  return 0;
}