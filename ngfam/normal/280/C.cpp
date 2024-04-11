#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int f[N];
vector < int > adj[N];

void dfs(int u, int p = 0){
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    f[v] = f[u] + 1;
    dfs(v, u);
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
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  f[1] = 1;
  dfs(1);
  double answer = 0;
  for(int i = 1; i <= n; ++i){
    answer += (1.0 / f[i]);
  }
  cout << fixed << setprecision(10) << answer << endl;
  return 0;
}