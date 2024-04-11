#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, m;
vector<int> edges[N];

int dist[N][N];
void bfs(int u, int dist[]) {
  for (int i=0; i<n; i++) dist[i] = -1;
  queue<int> q;
  q.push(u);
  dist[u] = 0;
  
  while (q.size()) {
    int u = q.front();
    q.pop();
    
    for (int v: edges[u]) {
      if (dist[v] >= 0) continue;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
}

int ask(int u) {
  printf("%d\n", u+1);
  fflush(stdout);
  
  char s[10];
  int v;
  scanf("%s", s);
  
  if (s[0] == 'G') {
    scanf("%d", &v);
    --v;
    return v;
  }
  
  return -1;
}

vector<int> next_nodes(int u, int v, vector<int> &nodes) {
  vector<int> nxt;
  for (int i: nodes) {
    if (dist[i][v] >= dist[i][u]) {
      continue;
    }
    
    nxt.push_back(i);
  }
  
  return nxt;
}

int chooseU(vector<int> &nodes) {
  int ret = -1;
  int heavy = -1;
  
  set<int> snodes;
  for (int u: nodes) snodes.insert(u);
  
  for (int u: nodes) {
    int maks = 0;
    for (int v: edges[u]) {
      if (snodes.find(v) == snodes.end()) continue;
      
      maks = max(maks, (int) next_nodes(u, v, nodes).size());
    }
    
    if (heavy == -1 || maks < heavy) {
      ret = u;
      heavy = maks;
    }
  }
  
  return ret;
}

int initU;
void guess() {
  vector<int> nodes(n);
  iota(nodes.begin(), nodes.end(), 0);
  
  int u = initU;
  int v = ask(u);
  
  while (v != -1) {
    nodes = next_nodes(u, v, nodes);
    
    u = chooseU(nodes);
    v = ask(u);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i=0; i<m; i++) {
    int k;
    scanf("%d", &k);
    
    int u, v;
    for (int i=0; i<k; i++) {
      u = v;
      scanf("%d", &v);
      --v;
      
      if (i > 0) {
        edges[u].push_back(v);
        edges[v].push_back(u);
      }
    }
  }
  
  for (int i=0; i<n; i++) bfs(i, dist[i]);
  
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  initU = chooseU(v);
  
  for (int i=0; i<n; i++) guess();
  return 0;
}