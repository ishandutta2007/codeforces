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

const int N = (1LL<<20) + 2;

int dp[N];

void solve()
{
  string s;
    cin >> s;
    
  int ans = 0;  
  int n = s.length(); 
     
  for(int i=0;i<n;i++)
  {
    int mask = 0;   
      
      for(int j=i;j<min(n,i+20);j++)
      {
        if((mask & (1LL<<s[j]-'a') ) > 0) break;         
        mask^=(1LL<<(s[j]-'a'));
        dp[mask] = (j-i+1);     
      }
  }
    
  for(int i=0;i<20;i++)
      for(int j=0;j<(1LL<<20);j++)
      if(j&(1LL<<i))
          dp[j] = max(dp[(1LL<<i)^j],dp[j]);
      
  for(int i=0;i<n;i++)
  {
      int mask = 0;
      
      for(int j=i;j<min(n,i+20);j++)
      {
        if((mask & (1LL<<(s[j]-'a')) ) > 0) break;         
        mask^=(1LL<<(s[j]-'a'));
         
        ans=max(ans,dp[mask^((1LL<<20)-1)]+(j-i+1));
      }
  }
      
    
  cout << ans;
 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}