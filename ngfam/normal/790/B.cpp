#include <bits/stdc++.h>

using namespace std;

const int N = 300010, K = 15;

int n, k;
int cnt[N][K];
int level[N];
int par[N];
long long answer;
long long f[N][K];
long long calc[N];
vector < int > adj[N];

void dfs(int u, int p = 0){
  cnt[u][k] = 1;
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    par[v] = u;
    level[v] = level[u] + 1;
    dfs(v, u);
    for(int x = 1; x <= k; ++x){
      for(int y = 1; y <= k; ++y){
        int add = 0;
        if(x != k && k - x >= y + 1){
          add = -1;
        }
        if(x == k && y == k){
          add = 1;
        }
        if(cnt[v][y] > 0) calc[u] += f[u][x] * cnt[v][y] + cnt[u][x] * (f[v][y] + cnt[v][y] * add);
      }
    }
    cnt[u][1] += cnt[v][k];
    f[u][1] += f[v][k] + cnt[v][k];
    for(int x = 2; x <= k; ++x){
      f[u][x] += f[v][x - 1];
      cnt[u][x] += cnt[v][x - 1];
    }
  }
  answer += calc[u];
}

int lca(int u, int v){
  if(level[u] < level[v]){
    swap(u, v);
  }
  while(level[u] > level[v]){
    u = par[u];
  }
  while(u != v){
    u = par[u];
    v = par[v];
  }
  return u;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d%d", &n, &k);
  for(int i = 1; i < n; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cout << answer;
  return 0;
}