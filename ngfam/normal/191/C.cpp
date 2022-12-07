#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int f[N];
int add[N];
int edge[N];
int high[N];
int answer[N];
int jump[N][20];
vector < int > adj[N];
vector < int > solve[N];
pair < int, int > lst[N];

void pre_dfs(int u, int p = 0){
  if(p != 0){
    jump[u][0] = p;
    for(int i = 1; i < 20; ++i){
      jump[u][i] = jump[jump[u][i - 1]][i - 1];
    }
  }
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    high[v] = high[u] + 1;
    pre_dfs(v, u);
  }
}

int lca(int u, int v){
  if(high[u] < high[v]){
    swap(u, v);
  }
  for(int i = 19; i >= 0; --i){
    int x = jump[u][i];
    if(x != 0 && high[x] >= high[v]){
      u = x;
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

void dfs(int u, int p = 0){
  for(int x : solve[u]){
    if(x == u){
      continue;
    }
    ++f[u];
    --add[x];
  }
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    dfs(v, u);
    f[u] += f[v] + add[u];
    add[u] = 0;
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i < n; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    lst[i] = make_pair(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  pre_dfs(1);
  for(int i = 1; i < n; ++i){
    int u = lst[i].first, v = lst[i].second;
    if(u == jump[v][0]){
      edge[v] = i;
    }
    else{
      edge[u] = i;
    }
  }
  scanf("%d", &m);
  for(int i = 1; i <= m; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    int x = lca(u, v);
    solve[u].push_back(x);
    solve[v].push_back(x);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; ++i){
    answer[edge[i]] += f[i];
  }
  for(int i = 1; i < n; ++i){
    printf("%d ", answer[i]);
  }
  return 0;
}