#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, k, most, curr, need = 1;
int done[N];
int cnt[N];
int answer[N];
int depth[N];
set < int > adj[N];
set < int > tree[N];
vector < int > result[N];

void dfs(int u){
  done[u] = 1;
  cnt[u] = 1;
  for(int v : adj[u]){
    if(done[v] == 1){
      continue;
    }
    tree[u].insert(v);
    dfs(v);
    cnt[u] += cnt[v];
  }
}

void add(){
  ++curr;
  if(curr > most){
    ++need;
    curr -= most;
  }
}

void solve(int u){
  add();
  result[need].push_back(u);
  for(int v : tree[u]){
    solve(v);
    add();
    result[need].push_back(u);
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  scanf("%d%d%d", &n, &m, &k);
  most = (2 * n + k - 1) / k;
  for(int i = 1; i <= m; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].insert(v);
    adj[v].insert(u);
  }
  dfs(1);
  solve(1);
  for(int i = 1; i <= k; ++i){
    if(result[i].size() == 0){
      puts("1 1");
    }
    else{
      printf("%d ", int(result[i].size()));
      for(int v : result[i]){
        printf("%d ", v);
      }
      puts("");
    }
  }
  return 0;
}