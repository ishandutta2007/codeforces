#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int inf = 1e16;

void solve()
{
   int n,m;
    cin >> n >> m;
    
   pair<int,pii> a[m+1];
   f(i,m) cin >> a[i].F >> a[i].S.F >> a[i].S.S;
   a[0] = {0,{1,1}};
    
   vi dp(m+1,-inf); 
   dp[0] = 0;
    
   int mxx = -inf; 
   int ptr = 0; 
    
   int r = n; 
    
   f(i,m)
   {
       while((a[i].F - a[ptr].F) >= r + r + 1)
       {
           mxx = max(mxx,dp[ptr]);
           ptr++;
       }
       
       dp[i] = max(dp[i],1 + mxx);
       
       for(int j=i-1;j>=0;j--)
       {
           if((a[i].F - a[j].F) >= r + r + 1) break;
           
           if(abs(a[i].S.F - a[j].S.F) + abs(a[i].S.S - a[j].S.S) <= a[i].F - a[j].F)
           {
               dp[i] = max(dp[i] , 1 + dp[j]);
           }
       }
   }
   
    
    
   int res = 0;
    f(i,m) res = max(res,dp[i]);
    
   cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}