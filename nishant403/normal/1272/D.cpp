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
  int n;
  cin >> n;
    
  int a[n];
    f(i,n) cin >> a[i];
    
  vi dp(n,1);
    
    for(int i=n-2;i>=0;i--)
    {
        if(a[i] < a[i+1])
             dp[i] = dp[i+1] + 1;
    }
    
    int ans = 0;
    
    f(i,n) ans= max(ans,dp[i]);
    
    vi ending(n,0);
    
    for(int i=n-1;i>=0;i--)
    {
     ending[i+dp[i]-1] = dp[i];   
    }
    
    for(int i=n-2;i>=0;i--)
    {
     ending[i] = max(ending[i],ending[i+1]-1);   
    }
    
    
    for(int i=1;i<n-1;i++)
    {
        if(a[i-1] < a[i+1]) ans=max(ans,ending[i-1] + dp[i+1]);
        
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