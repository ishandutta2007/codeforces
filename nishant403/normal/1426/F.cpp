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

const int MOD = 1e9+7;

void solve()
{
   int n;
    cin >> n;
    
   string s;
    cin >> s;
    
   vi dp(3,0);
   vi dp2(3,0);
    
    int o = 1;
    
   f(i,n) 
   {
       if(s[i] == 'a') dp[0] = (dp[0] + o)%MOD;
       else if(s[i] == 'b') dp[1] = (dp[1] + dp[0])%MOD;
       else if(s[i] == 'c') dp[2] = (dp[2] + dp[1])%MOD;
       else
       {
          dp2 = dp; 
          f(j,3)  dp[j] = (dp[j]*3)%MOD;
          dp[2] = (dp[2] + dp2[1])%MOD;
          dp[1] = (dp[1] + dp2[0])%MOD;
          dp[0] = (dp[0] + o)%MOD;
           
          o = (o*3)%MOD;
       }
       
   }
    
   cout << dp[2];
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}