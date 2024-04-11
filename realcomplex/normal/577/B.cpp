#include <bits/stdc++.h>

using namespace std;

bool dp[1005][1005];

int main(){
  int n,m;
  scanf("%i %i",&n,&m);
  if(n>m){//Dirhilet's principle
    printf("YES\n");
    exit(0);
  }
  int k;
  cin >> k;
  dp[1][k%m] = true;
  for(int i = 2;i<=n;i++){
    scanf("%i",&k);
    dp[i][k%m] = true;
    for(int j = 0;j<m;j++){
      if(dp[i-1][j]==true)
        dp[i][j] = true,dp[i][(j+k)%m] = true;
    }
  }
  if(dp[n][0]==true)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}