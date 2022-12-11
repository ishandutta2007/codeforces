#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 4010;
const int N = 2005;
const int inf = (int)2e9;
int dp[M][N];
int pp[M];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0 ; i <= n + m; i ++ ){
    for(int j = 0 ; j <= n; j ++ ){
      dp[i][j]=-inf;
    }
  }
  for(int i = 0 ; i <= n + m ; i ++){
    dp[i][0]=0;
  }
  vector<int> ag(n);
  vector<int> cost(n);
  for(auto &x : ag){
    cin >> x;
  }
  for(auto &x : cost){
    cin >> x;
  }
  for(int i = 1; i <= n + m ; i ++ )
    cin >> pp[i];
  reverse(ag.begin(), ag.end());
  reverse(cost.begin(), cost.end());
  for(int i = 0 ; i < n; i ++ ){
    for(int x = n; x >= 0; x -- ){
      if(dp[ag[i]][x]==-inf) continue;
      dp[ag[i]][x + 1] = max(dp[ag[i]][x + 1], dp[ag[i]][x] - cost[i] + pp[ag[i]]);
    }
    for(int j = ag[i]; j < n + m ; j ++ ){
      for(int x = 0; x <= n; x ++ ){
        if(dp[j][x]==-inf)break;
        dp[j + 1][x / 2] = max(dp[j + 1][x / 2], dp[j][x] + (x/2) * pp[j + 1]);
      }
    }
  }
  int ans = 0;
  for(int i = 0 ; i <= n + m ; i ++ ){
    for(int j = 0 ; j <= 1; j ++ ){
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << "\n";
  return 0;
}