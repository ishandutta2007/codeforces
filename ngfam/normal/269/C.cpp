#include <bits/stdc++.h>

using namespace std;

const int N = 250100;

int n, m;
int answer[N], f[N];
vector < int > adj[N];
pair < pair < int, int >, int > edge[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; ++i){
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edge[i] = make_pair(make_pair(u, v), w);
    adj[u].push_back(i);
    adj[v].push_back(i);
    f[u] += w;
    f[v] += w;
  }
  for(int i = 1; i <= n; ++i){
    f[i] /= 2;
  }
  memset(answer, -1, sizeof answer);
  queue < int > bfs;
  bfs.push(1);
  while(!bfs.empty()){
    int u = bfs.front();
    bfs.pop();
    for(int j : adj[u]){
      if(answer[j] != -1){
        continue;
      }
      int v = edge[j].first.first ^ edge[j].first.second ^ u;
      int w = edge[j].second;
      if(u == edge[j].first.first){
        answer[j] = 0;
      }
      else{
        answer[j] = 1;
      }
      f[v] -= w;
      if(v != n && f[v] == 0){
        bfs.push(v);
      }
    }
  }
  for(int i = 1; i <= m; ++i){
    printf("%d\n", answer[i]);
  }
  return 0;
}