#include <bits/stdc++.h>

using namespace std;

const int N = 500050;

int n, m, q;
int lab[N];
int best[N];
int level[N];
int done[N];
vector < int > adj[N];
vector < int > lst;

int far(int u, int p, int d = 0){
  int answer = u;
  level[u] = d;
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    int x = far(v, u, level[u] + 1);
    if(level[x] > level[answer]){
      answer = x;
    }
  }
  return answer;
}

int fin(int u){
  if(lab[u] < 0){
    return u;
  }
  return lab[u] = fin(lab[u]);
}

void join(int u, int v){
  u = fin(u); v = fin(v);
  if(u == v){
    return;
  }
  if(lab[u] > lab[v]){
    swap(u, v);
  }
  lab[u] += lab[v];
  lab[v] = u;
  best[u] = max(max(best[u], best[v]), (best[u] + 1) / 2 + (best[v] + 1) / 2 + 1);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  memset(lab, -1, sizeof lab);
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 1; i <= m; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    join(u, v);
  }
  for(int u = 1; u <= n; ++u){
    if(done[fin(u)]){
      continue;
    }
    done[fin(u)] = 1;
    int x = far(u, 0);
    best[fin(u)] = level[far(x, 0)];
  }
  while(q--){
    int t, u, v;
    scanf("%d", &t);
    if(t == 1){
      scanf("%d", &u);
      printf("%d\n", best[fin(u)]);
    }
    else{
      scanf("%d%d", &u, &v);
      join(u, v);
    }
  }
  return 0;
}