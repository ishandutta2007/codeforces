#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 3005;
vector<int> T[N];
ll dp[N][N];
ll s[N][N];
int dep[N][N];
int pp[N][N];

void dfs(int u, int par, int root){
  s[root][u] = 1;
  pp[root][u] = par;
  for(auto x : T[u]){
    if(x == par) continue;
    dep[root][x] = dep[root][u] + 1;
    dfs(x,u,root);
    s[root][u] += s[root][x];
  }
}

vector<pii> pr[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int u, v;
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  for(int i = 1; i <= n; i ++ ){
    dfs(i,-1,i);
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      pr[dep[i][j]].push_back(mp(i,j));
    }
  }
  for(int i = 1; i < n; i ++ ){
    for(auto x : pr[i]){
      dp[x.fi][x.se] = s[x.fi][x.se] * s[x.se][x.fi] + max(dp[pp[x.se][x.fi]][x.se], dp[x.fi][pp[x.fi][x.se]]);
    }
  }
  ll res = 0;
  for(int i = 1; i <= n; i ++ )
    for(int j = 1 ; j <= n; j ++ ) 
      res = max(res, dp[i][j]);
  cout << res;
  return 0;
}