#include <bits/stdc++.h>

using namespace std;

const int N =  100010;

int n;
long long a[N];
long long sub[N];
long long ins[N];
vector < int > adj[N];

void dfs(int u, int p = 0){
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    dfs(v, u);
    sub[u] = max(sub[u], sub[v]);
    ins[u] = max(ins[u], ins[v]);
  }
  a[u] += ins[u] - sub[u];
  ins[u] += max(0LL, -a[u]);
  sub[u] += max(0LL, a[u]);
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
  for(int i = 1; i <= n; ++i){
    scanf("%lld", a + i);
  }
  dfs(1);
  cout << ins[1] + sub[1];
  return 0;
}