#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
long long a[N];

vector<int> bits[60];

vector<int> nodes;
vector<int> edges[200];

int cycle(int u) {
  vector<int> par(nodes.size(), -1);
  vector<int> dist(nodes.size(), -1);
  
  queue<int> q;
  q.push(u);
  dist[u] = 0;
  par[u] = u;
  while (q.size()) {
    int u = q.front();
    q.pop();
    
    for (int v: edges[u]) {
      if (v == par[u]) continue;
      if (dist[v] != -1) return dist[u] + dist[v] + 1;
      
      dist[v] = dist[u] + 1;
      par[v] = u;
      q.push(v);
    }
  }
  
  return -1;
}

int find_shortest_cycle() {
  int ret = -1;
  for (int i = 0; i < nodes.size(); ++i) {
    int cyc = cycle(i);
    if (cyc == -1) continue;
    
    if (ret == -1 || cyc < ret) ret = cyc;
  }
  
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
    
    for (int j = 0; j < 60; ++j) {
      if (a[i] >> j & 1) {
        bits[j].push_back(i);
      }
    }
  }
  
  for (int i = 0; i < 60; ++i) if (bits[i].size() >= 3) return 0 * printf("3\n");

  for (int i = 0; i < 60; ++i) if (bits[i].size() == 2) for (int u: bits[i]) nodes.push_back(u);
  sort(nodes.begin(), nodes.end());
  nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
  
  set<pair<int, int>> es;
  for (int i = 0; i < 60; ++i) if (bits[i].size() == 2) {
    int u = lower_bound(nodes.begin(), nodes.end(), bits[i][0]) - nodes.begin();
    int v = lower_bound(nodes.begin(), nodes.end(), bits[i][1]) - nodes.begin();
    
    if (u > v) swap(u, v);
    if (es.find({u, v}) != es.end()) continue;
    es.insert({u, v});
    
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  
  printf("%d\n", find_shortest_cycle());
  return 0;
}