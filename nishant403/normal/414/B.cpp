#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int M = 1e9+7;
vector<int> divs[2001];
    
signed main()
{
 fast;
 int n,k;
  cin >> n >> k;
    
 for(int i=1;i<=n;i++)
   for(int j=1;j*j<=i;j++)         
    if(i%j==0) 
    {
     divs[i].pb(j);   
        if(j*j!=i) divs[i].pb(i/j);
    }
    
 int dp[n+1][k+1];   
    
 memset(dp,0,sizeof(dp));
  
for(int i=1;i<=n;i++) dp[i][1]=1;    
    
 int ans = 0; 
    
for(int i=2;i<=k;i++)  
{  
  for(int j=1;j<=n;j++)  
  {
   for(auto z : divs[j])   
      dp[j][i] = ( dp[j][i] + dp[z][i-1] ) %M;
      
  }   
}
    
 for(int i=1;i<=n;i++) ans=(ans + dp[i][k])%M;   
    
    cout << ans;
}