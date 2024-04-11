#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, a[N], parent[N];
int answer = 1;
vector < int > adj[N];

void dfs(int u, int p){
  int current = 0;
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    ++current;
    while(current == a[u] || current == a[p]){
      ++current;
    }
    answer = max(answer, current);
    a[v] = current;
    dfs(v, u);
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  scanf("%d", &n);
  for(int i = 1; i < n; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  a[1] = 1;
  dfs(1, 0);
  printf("%d\n", answer);
  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  return 0;
}