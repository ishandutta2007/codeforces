#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;
const int X = 11;
const ll MOD = (int)1e9 + 7;

vector<int>T[N];
ll dp[N][3][X];
int k, x, m;

ll current_dp[2][3][X];

void dfs(int u, int par){
  int lower = 0;
  for(auto i : T[u])
    if(i != par){
      dfs(i, u);
      lower ++ ;
    }
  if(lower == 0){
    dp[u][0][0] = k-1;
    dp[u][1][1] = 1;
    dp[u][2][0] = m-k;
    return;
  }
  memset(current_dp, 0, sizeof current_dp);
  current_dp[0][0][0] = 1;
  current_dp[0][1][0] = 1;
  current_dp[0][2][0] = 1;
  ll tt;
  int cur = 1, las = 0;
  for(auto i : T[u]){
    if(i == par)
      continue;
    for(int lf = 0; lf <= x; lf ++ ){
      for(int rf = 0; rf + lf <= x; rf ++ ){
        // case 1:
          tt = dp[i][0][rf] + dp[i][1][rf] + dp[i][2][rf];
          tt %= MOD;
          tt *= current_dp[las][0][lf];
          tt %= MOD;
          current_dp[cur][0][lf + rf] += tt;
          current_dp[cur][0][lf + rf] %= MOD;
        // case 2:
          tt = dp[i][0][rf];
          tt *= current_dp[las][1][lf];
          tt %= MOD;
          current_dp[cur][1][lf + rf] += tt;
          current_dp[cur][1][lf + rf] %= MOD;
        // case 3:
          tt = dp[i][0][rf] + dp[i][2][rf];
          tt %= MOD;
          tt *= current_dp[las][2][lf];
          tt %= MOD;
          current_dp[cur][2][lf + rf] += tt;
          current_dp[cur][2][lf + rf] %= MOD;
      }
    }
    for(int i = 0;i < 3; i ++ ){
      for(int j = 0; j <= x;j ++ ){
        current_dp[las][i][j] = 0;
      }
    }
    cur = !cur;
    las = !las;
  }
  for(int j = 0; j <= x; j ++ ){
    dp[u][0][j] = current_dp[las][0][j] * (k - 1);
    dp[u][0][j] %= MOD;
    if(j > 0)
      dp[u][1][j] = current_dp[las][1][j-1];
    dp[u][2][j] = current_dp[las][2][j] * (m - k);
    dp[u][2][j] %= MOD;
  }
}

int main(){
  fastIO;
  int n;
  cin >> n >> m;
  int u, v; 
  for(int i = 1;i < n;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  cin >> k >> x;
  dfs(1, -1);
  ll ans = 0;
  for(int y = 0; y <= x; y ++ ){
    ans += dp[1][0][y] + dp[1][1][y] + dp[1][2][y];
    ans %= MOD;
  }
  cout << ans << "\n";
  return 0;
}