#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn =  2e5 + 7;
const int INF = 1e9 + 7;
 
int n, m, r;
int dp[67][67][67], a[67][67], d[67][67];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>r;
  for(int i = 0; i <= 60; i++) {
    for(int j = 0; j <= 60; j++) {
      for(int k = 0; k <= 60; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
 
  for(int t = 1; t <= m; t++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
          cin>>a[i][j];
      }
    }
    for(int k = 1; k <= n; k++) {
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        }
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        dp[i][j][0] = min(dp[i][j][0], a[i][j]);
      }
    }
  }
 
  for(int t = 1; t <= n; t++) {
    for(int k = 1; k <= n; k++) {
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          dp[i][j][t] = min(dp[i][j][t], dp[i][k][t - 1] + dp[k][j][0]);
        }
      }
    }
  }
 
  int s, t, k;
  for(int i = 1; i <= r; i++) {
      cin>>s>>t>>k;
   cout<<dp[s][t][min(k, n)]<<endl;
  }
}