#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;

#define fi first
#define se second
#define mp make_pair


#define int ll

const int N = 5005;
int dp[N][N];

int pf[N];

signed main(){
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i ++ ){
    cin >> pf[i];
    pf[i] += pf[i - 1];
  }
  for(int j = 1; j <= n; j ++ ){
    for(int t = 1;t <= k ; t ++ ){
      dp[j][t] = dp[j - 1][t];
      if(j >= m){
        dp[j][t] = max(dp[j][t], dp[j - m][t - 1] + pf[j] - pf[j - m]);
      }
    }
  }
  cout << dp[n][k];
  return 0;
}