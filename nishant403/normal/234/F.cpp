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

const int N = 203;
const int A = 4e4+3;

int dp[N][A][2],h[N],p[N],n,a,b;

void solve()
{
   cin >> n >> a >> b;
    
   f(i,n) cin >> h[i];
    
   p[0] = 0;
    
   f(i,n) p[i] = p[i-1] + h[i];
     
   f(i,n+1)
       f(j,a+1) dp[i-1][j-1][0] = dp[i-1][j-1][1] = 1e9;
      
  dp[0][a][0] = 0;
  dp[0][a][1] = 0;
      
  f(i,n)
  {
     for(int j=0;j<=a;j++)
     {
       if(j+h[i] <= a) 
           dp[i][j][0] = dp[i-1][j+h[i]][0];
      
       if(p[i]-(a-j) <= b) 
           dp[i][j][1] = dp[i-1][j][1];
         
       if(j+h[i] <= a) 
           dp[i][j][0] = min(dp[i][j][0],dp[i-1][j+h[i]][1] + min(h[i],h[i-1]));
           
       if(p[i]-(a-j) <= b)
           dp[i][j][1] = min(dp[i][j][1],dp[i-1][j][0] + min(h[i],h[i-1]));   
     }
  }
    
  int ans = 1e9; 
       
  f(j,a+1) 
  {
      if(dp[n][j-1][0] != -1) ans = min(ans,dp[n][j-1][0]);
      if(dp[n][j-1][1] != -1) ans = min(ans,dp[n][j-1][1]);   
  }
      
  if(ans == 1e9) cout << -1;  
  else cout << ans;    
}

signed main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}