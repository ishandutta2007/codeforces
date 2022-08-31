#include <bits/stdc++.h>
using namespace std;

#define int long long 

int dp[101][2];
int M = 1e9+7;

//second parameter if whether we are done with max or not 
//1 if done 
//0 if not done

signed main()
{
    memset(dp,0,sizeof(dp));
    
 int n,k,d;
   
    cin >> n >> k >> d;
  
  dp[0][0] = 1
      ;  
    
for(int i=1;i<=n;i++)    
{
  for(int j=1;j<=min(k,i);j++)
  {
     if(j<d) dp[i][0] = (dp[i][0] + dp[i-j][0])%M;
      
     else dp[i][1] = (dp[i][1] + dp[i-j][0])%M;
      
     dp[i][1] = (dp[i][1] + dp[i-j][1])%M;  
      
  }
    
}
    
    cout << dp[n][1];
    
}