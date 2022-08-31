#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
  int n,m;
  cin >> n >> m;
    
  int dp[n][2];
  
  vi flag(n,0);  
  
  int pos[n][2];  
    
  string ss[n];
    
  int last = 0;  
  
  f(i,n) cin >> ss[i];  
    
  f(i,n) pos[i][0] = 1213;  
    
  f(i,n)
  {
   string s = ss[n-i-1];
      
   for(int j=1;j<(int)s.length()-1;j++) if(s[j]=='1') { flag[i]=1; last = i; break; }
   for(int j=1;j<(int)s.length()-1;j++) if(s[j]=='1') pos[i][1] = j,pos[i][0] = min(pos[i][0],j);
  }
   
    
 if(last!=0)
 {
  if(flag[0] == 0) dp[0][0] = 0,dp[0][1] = 0;  
  else dp[0][0] = 2*pos[0][1],dp[0][1] = m+1;  
 }
 else
 {
     if(flag[0] == 0)  dp[0][0] = dp[0][1] = 0;
     else dp[0][0] = dp[0][1] = pos[0][1];  
 }
    
  for(int i=1;i<=last;i++)
  {
     
  if(i!=last)
  {
   if(flag[i]) 
   {
       dp[i][0] = min( dp[i-1][0] + (2*pos[i][1]) , dp[i-1][1] + m + 1 ) + 1;
       dp[i][1] = min( dp[i-1][1] + (m+1+m+1-2*pos[i][0]), dp[i-1][0] + m + 1 ) + 1;
   }
   else
   {
    dp[i][0] = dp[i-1][0]+1;   
    dp[i][1] = dp[i-1][1]+1;   
   }  
  }
  else
  {
   dp[i][0] = min( dp[i-1][0] + pos[i][1] + 1  ,dp[i-1][1] + m + 1 - pos[i][0] + 1);  
   dp[i][1] = min( dp[i-1][0] + pos[i][1] + 1, dp[i-1][1] + 1 + m + 1 - pos[i][0]);   
  }
      
  }
    
  cout << min(dp[last][0],dp[last][1]);  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}