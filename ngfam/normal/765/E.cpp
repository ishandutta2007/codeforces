#include <bits/stdc++.h>

using namespace std;

const int N = 223456;

int n, found;
int depth[N];
int f[N];
vector < int > adj[N];

void dfs(int u, int p){
  if(u == p){
    depth[u] = 1;
  }
  else{
    depth[u] = depth[p] + 1;
  }
  f[u] = depth[u];
  int same = -1, curr = -1;
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    dfs(v, u);
    f[u] = max(f[u], f[v]);
    if(found != 0){
      return;
    }
    if(same == -1){
      same = f[v];
    }
    if(same == f[v]){
      continue;
    }
    if(u == p){
      if(curr == -1){
        curr = f[v];
      }
      if(curr == f[v]){
        continue;
      }
    }
    found = -u;
    return;
  }
  if(u == p){
    if(same == -1){
      same = 1;
    }
    if(curr == -1){
      curr = 1;
    }
    found = same + curr - 2;
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i < n; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  if(found < 0){
    int u = -found;
    found = 0;
    dfs(u, u);
    if(found < 0){
      puts("-1");
      return 0;
    }
  }
  while(found % 2 == 0){
    found = (found) / 2;
  }
  cout << found;
  return 0;
}