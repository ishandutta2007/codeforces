#include <bits/stdc++.h>
using namespace std;
#define int long long 

int dp[1005][2010][4]={0};
int M = 998244353;

signed main()
{
   int n,k;
    cin >> n >> k;
    
    dp[1][1][0]=dp[1][2][1]=dp[1][2][2]=dp[1][1][3]=1;
    
    for(int i=2;i<=n;i++)
    {
      for(int j=1;j<=k;j++)
      {
         dp[i][j][0] = ( dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3] ) %M;
         dp[i][j][1] = ( dp[i-1][j-1][0] + dp[i-1][j][1]  + dp[i-1][j-1][3] ) %M;
          
          
         dp[i][j][2] = ( dp[i-1][j-1][0] +  dp[i-1][j][2] + dp[i-1][j-1][3] ) %M;
         dp[i][j][3] = ( dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][3] ) %M;

          if(j>1) { dp[i][j][1] += (dp[i-1][j-2][2]); dp[i][j][2]+=(dp[i-1][j-2][1] ); }
          
      } 
    }   
        
    cout << (dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%M;
}