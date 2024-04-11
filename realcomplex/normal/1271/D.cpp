#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5005;
int dp[N][N];
int mx[N];

int a[N], b[N], c[N];
vector<int> T[N];


int main(){
  fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i] >> b[i] >> c[i];
  }
  int u, v;
  for(int i = 1; i <= n; i ++ )
    mx[i] = i;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u >> v;
    mx[v]=max(mx[v],u);
  }
  for(int i = 1; i <= n; i ++ ){
    T[mx[i]].push_back(c[i]);
  }
  for(int i = 1; i <= n; i ++ ){
    sort(T[i].begin(), T[i].end());
    reverse(T[i].begin(), T[i].end());
  }
  for(int i = 0 ; i <= n; i ++ ){
    for(int j = 0 ; j < N ; j ++ )
      dp[i][j] = -(int)1e9;
  }
  dp[0][k] = 0;
  int sum;
  for(int i = 0 ;i <= n; i ++ ){
    vector<pii> el;
    
    if(i > 0){
      for(int j = 0; j < N; j ++  ){
        if(dp[i][j] < 0) continue;
        sum = 0;
        for(int k = 0 ; k < T[i].size(); k ++ ){
          if(j - (k + 1) < 0) break;
          sum += T[i][k];
          dp[i][j - (k + 1)] = max(dp[i][j - (k + 1)], dp[i][j] + sum);
        }
      }
    }
    
    if(i < n){
      for(int j = 0 ; j < N ; j ++ ){
        if(dp[i][j] < 0) continue;
        if(j >= a[i + 1]){
          dp[i + 1][j + b[i + 1]] = max(dp[i + 1][j + b[i + 1]], dp[i][j]);
        }
      }
    }
  }
  int ret = -(int)1e9;
  for(int i = 0 ; i < N ; i ++ ){
    if(dp[n][i] > ret) {
      ret = dp[n][i];
    }
  
  }
  if(ret == -(int)1e9)cout << -1;
  else cout << ret << "\n";
  return 0;
}