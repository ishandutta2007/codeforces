#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

int process(vi & a)
{
   int n = a.size();
   vector<int> dp(n,0);
   
   int tot = 0; 
   f(i,n) tot+=a[i];
   
   int res = tot;
   
   int cur = 0;
   
   f(i,n)
   {
       cur+=a[i];
       
       if(i > 0) 
       {
           if(a[i] == 0) dp[i] = min(cur,dp[i-1] + 1);
           else dp[i] = min(cur,dp[i-1]);
       }
       
       res = min(res,dp[i] + tot - cur);
   }
    
   return res;
}

void solve()
{
   int n,k;
    cin >> n >> k;
    
   string s;
    cin >> s;
    
   int one = 0; 
    
   f(i,n) one+=(s[i]=='1');
    
   vi go(k,0);
   vi go2[k];
    
   f(i,n) go[i%k]+=(s[i]=='1');
   f(i,n) go2[i%k].pb(s[i]=='1');
    
   int res = n;
    
   f(i,k) res = min(res,process(go2[i]) + one - go[i]);
   
   cout << res << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}