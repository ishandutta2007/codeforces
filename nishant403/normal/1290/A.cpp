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
#define f(i,n) for(int i=0;i<n;i++)
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

const int N = 5000;
int a[N];

void solve()
{
   int n,m,k;
   cin >> n >> m >> k;
      
   f(i,n) cin >> a[i];
   
   int good = min(m-1,k);
   int bad = m-1 - good; 
    
   vector<int> dp(n,1e9+10); 
    
   for(int front = 0;front<=bad;front++)
   {
       //range : [front,n-1-bad-front] jetla b
       
       for(int ffront = 0;ffront <=good;ffront++)
       {
          int first = front + ffront;
          int last = n-1-(bad-front)-(good-ffront);         
          dp[ffront] = min(dp[ffront],max(a[last],a[first]));
       }
       
   }
    
   int res = 0;
    
   f(i,good+1) res=max(res,dp[i]);
    
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