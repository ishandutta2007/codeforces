#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int MOD = 998244353;
int dp[N][2][3];
int cur[2][3];
vector<int> T[N];

void add(int &a, int b){
  a += b;
  if(a >= MOD)
    a -= MOD;
}

int mult(int a, int b){ 
  return (a * 1ll * b) % MOD;
}

void dfs(int u, int par){
  dp[u][0][0]=1;
  dp[u][1][1]=1;
  dp[u][0][1]=1;
  for(auto nd : T[u]){
    if(nd == par) continue;
    dfs(nd,u);
    for(int i = 0 ; i < 2; i ++ )
      for(int j = 0 ; j < 3; j ++ )
        cur[i][j]=0;
    for(int x = 0; x < 2; x ++ ){
      for(int y = 0; y < 3; y ++ ){
        for(int pick = 0 ; pick < 2; pick ++ ){
          for(int sz =0 ; sz < 3; sz ++ ){
            // can we cut?
            if(sz != 1){
              add(cur[x][y],mult(dp[u][x][y],dp[nd][pick][sz]));
            }
            // can we keep?
            if(x && pick) continue;
            if(!y) continue; 
            if(y && !sz) continue;
            add(cur[x][min(2,y+sz)],mult(dp[u][x][y],dp[nd][pick][sz]));
          }
        }
      }
    }
    for(int x = 0; x < 2; x ++ ){
      for(int y = 0; y < 3; y ++ ){
        dp[u][x][y]=cur[x][y];
      }
    }
  }
}

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
  dfs(1,-1);
  int res = MOD-1;
  add(res,dp[1][0][0]);
  add(res,dp[1][0][2]);
  add(res,dp[1][1][2]);
  cout << res; 
  return 0;
}