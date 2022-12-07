#include <bits/stdc++.h>

using namespace std;

const int N = 100010, K = 20;

int n, q;
int depth[N];
int jump[N][K];
vector < int > adj[N];

void dfs(int u, int p = 0){
  jump[u][0] = p;
  for(int i = 1; i < 20; ++i){
    jump[u][i] = jump[jump[u][i - 1]][i - 1];
  }
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

int lca(int u, int v){
  if(depth[u] < depth[v]){
    swap(u, v);
  }
  for(int i = 19; i >= 0; --i){
    if(jump[u][i] != 0 && depth[jump[u][i]] >= depth[v]){
      u = jump[u][i];
    }
  }
  if(u == v){
    return u;
  }
  for(int i = 19; i >= 0; --i){
    if(jump[u][i] != jump[v][i]){
      u = jump[u][i];
      v = jump[v][i];
    }
  }
  return jump[u][0];
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &q);
  for(int i = 2; i <= n; ++i){
    int x; scanf("%d", &x);
    adj[x].push_back(i);
    adj[i].push_back(x);
  }
  dfs(1);
  while(q--){
    vector < int > read;
    for(int i = 1; i <= 3; ++i){
      int x;
      scanf("%d", &x);
     // cout << "f " << x << endl;
      read.push_back(x);
    }
    sort(read.begin(), read.end());
    int ans = 0;
    do{
      int u = lca(read[0], read[1]);
      int v = lca(read[0], read[2]);
      if(u == v){
        int x = lca(read[1], read[2]);
        ans = max(ans, depth[read[0]] - depth[u] + 1 + depth[x] - depth[u]);
      }
      else{
        ans = max(ans, depth[read[0]] - max(depth[v], depth[u]) + 1);
      }
    }
    while(next_permutation(read.begin(), read.end()));
    printf("%d\n", ans);
  }
  return 0;
}