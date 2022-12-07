#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const long long mod = 1e9 + 7;

int n;
int black[N];
long long f[N][2];
vector < int > adj[N];

void dfs(int u, int p){
  if(black[u] == 1){
    f[u][1] = 1;
  }
  else{
    f[u][0] = 1;
  }
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    dfs(v, u);
    if(black[u] == 1){
      f[u][1] = f[u][1] * (f[v][0] + f[v][1]);
      f[u][1] %= mod;
    }
    else{
      f[u][1] = (f[u][1] * (f[v][0] + f[v][1]));
      f[u][1] += (f[u][0] * f[v][1]);
      f[u][1] %= mod;
      if(u == 1){
      }
      f[u][0] = (f[u][0] * (f[v][0] + f[v][1])) % mod;
    }
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  scanf("%d", &n);
  for(int i = 2; i <= n; ++i){
    int val;
    scanf("%d", &val);
    ++val;
    adj[val].push_back(i);
    adj[i].push_back(val);
  }
  for(int i = 1; i <= n; ++i){
    scanf("%d", black + i);
  }
  dfs(1, 0);
  cout << f[1][1];
  return 0;
}