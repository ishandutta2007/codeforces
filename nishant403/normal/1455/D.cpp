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


void solve()
{
   int n,x;
    cin >> n >> x;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   int res = n + 1;
    
   if(is_sorted(a,a+n))
   {
       res = 0;
   }
    
   int temp = 0; 
    
   for(int i=0;i<n;i++)
   {
       if(a[i] <= x) continue;
       
       if(a[i] > x)
       {
           swap(x,a[i]);    
           temp++;
       }
       
       if(is_sorted(a,a+n))
       {
           res = min(res,temp);
       }
   }
   
    if(res == n + 1) res = -1;
    
    
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