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
    
    map<int,int> last,dp,prev;
    
    int p = -1;
    
    f(i,n) last[a[i]] = i;
    
    for(auto x : last)
    { 	
    	prev[x.F] = p;
    	p = x.F;
    }
    
    int lis = 0;
    
    f(i,n)
    {
    	if(dp.find(a[i]) == dp.end())
    	{
    		   		
    		if(last[prev[a[i]]] < i) 
    		   dp[a[i]] = dp[prev[a[i]]] + 1;
    	    		  
    		else
    		   dp[a[i]] = 1;
    		   
    	   lis = max(lis,dp[a[i]]);
    	}
    	
    }
 
    int ans = last.size();
    
    ans-=lis;
    
    cout << ans-1 << "\n";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}