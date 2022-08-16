#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
 
int n,m,k;
const int M = 998244353;

void solve()
{
cin >> n >> m >> k;
    
int dp[n+1][k+1];
    
memset(dp,0,sizeof(dp));
    
dp[1][0] = m;    
    
for(int i=2;i<=n;i++)
for(int j=0;j<=k;j++)
{
  dp[i][j] += dp[i-1][j] ;
  dp[i][j]%=M;  
    
if(j>0)  dp[i][j] +=((m-1)*dp[i-1][j-1])%M;     
   
  dp[i][j]%=M;  
   
}
    
    
    
cout << dp[n][k];

}
 
signed main()
{
    fast;
    solve();
}