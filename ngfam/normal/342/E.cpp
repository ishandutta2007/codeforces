#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

set < int > adj[N];
vector < int > vec[2], gra[N];

int cnt[N], n, par[N], f[N], lv[N], jump[N][20], tt;

void dfs(int u, int p){
  for(int i = 1; i <= 19; ++i){
    if(jump[u][i - 1] == 0) break;
    jump[u][i] = jump[jump[u][i - 1]][i - 1];
  }
  for(int v : gra[u]){
    if(v == p) continue;
    lv[v] = lv[u] + 1;
    jump[v][0] = u;
    dfs(v, u);
  }
}

int lca(int u, int v){
  if(lv[u] < lv[v]) swap(u, v);
  for(int i = 19; i >= 0; --i){
    if(jump[u][i] == 0) continue;
    int father = jump[u][i];
    if(lv[father] >= lv[v]){
      u = father;
    }
  }
  if(u == v) return u;
  for(int i = 19; i >= 0; --i){
    int paru = jump[u][i];
    int parv = jump[v][i];
    if(paru == 0) continue;
    if(paru != parv){
      u = paru;
      v = parv;
    }
  }
  return jump[u][0];
}

int dist(int u, int v){
  int father = lca(u, v);
  return lv[u] + lv[v] - 2 * lv[father];
}

void pre_dfs(int u){
  cnt[u] = 1;
  for(int v : adj[u]){
    if(cnt[v] != 0) continue;
    pre_dfs(v);
    cnt[u] += cnt[v];
  }
}

int centroid(int u, int p, int r){
  for(int v : adj[u]){
    if(v == p) continue;
    if(cnt[v] * 2 >= cnt[r]){
      return centroid(v, u, r);
    }
  }
  return u;
}

void update(int u){
  int up = u;
  while(up != 0){
    f[up] = min(f[up], dist(up, u));
    up = par[up];
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d%d", &n, &tt);
  for(int i = 1; i < n; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].insert(v);
    adj[v].insert(u);
    gra[u].push_back(v);
    gra[v].push_back(u);
  }
  dfs(1, 0);
  pre_dfs(1);
  int cur = 1;
  vec[1].push_back(centroid(1, 0, 1));
  while(vec[cur].size()){
    int other = 1 ^ cur;
    vec[other].clear();
    memset(cnt, 0, sizeof cnt);
    for(int u : vec[cur]){
      for(int v : adj[u]){
        adj[v].erase(u);
        pre_dfs(v);
        int cen = centroid(v, 0, v);
        par[cen] = u;
        vec[other].push_back(cen);
      }
    }
    cur = other;
  }
  memset(f, 60, sizeof f);
  update(1);
  while(tt--){
    int type, u;
    scanf("%d%d", &type, &u);
    if(type == 1){
      update(u);
    }
    else{
      int ans = f[0], up = u;
      while(up != 0){
        ans = min(ans, f[up] + dist(up, u));
        up = par[up];
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}