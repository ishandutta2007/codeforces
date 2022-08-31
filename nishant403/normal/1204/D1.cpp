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
  string s;
  cin >> s;
    
  int on = 0,ze = 0;
  int n =s.length();
    
  int dp[n];
    
  dp[0] = 1;
    
  if(s[0] == '1') on++;
  else ze++;
    
  for(int i=1;i<n;i++)
  {
      if(s[i] == '0') { dp[i] = ze+1; ze=max(ze,dp[i]); }
      else {
          dp[i] = max(ze,on)+1; on = max(on,dp[i]);   
      }
      
      dp[i] = max(dp[i],dp[i-1]);
  }
    
  string t;
  t = s;
    
  f(i,n)
  {
      
    if(t[i] == '1')  
    {
          
     int flag=1; 
        
     t[i] ='0';
        
     int ndp[n];
        
     ndp[0] = 1;   
        
      
      ze = on = 0;
        
     if(t[0] == '1') on++;
     else ze++;
          
         
      for(int j=1;j<n;j++)
  {
      if(t[j] == '0') { ndp[j] = ze+1; ze=max(ze,ndp[j]); }
      else {
          ndp[j] = max(ze,on)+1; on = max(on,ndp[j]);   
      }
      
      ndp[j] = max(ndp[j],ndp[j-1]);
            
      if(ndp[j] != dp[j]) {flag=0; break; }
          
  }  
        
     if(!flag) t[i] = '1';   
    } 
  }
      
  cout << t;  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}