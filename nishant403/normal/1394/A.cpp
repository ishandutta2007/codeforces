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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


void solve()
{
   int n,d,m;
    cin >> n >> d >> m;
    
   int a[n];
    f(i,n) cin >> a[i];
   sort(a,a+n);
   reverse(a,a+n);
    
   vector<int> x,y;
   x.pb(0);
   y.pb(0);
    
   f(i,n) if(a[i] <= m) x.pb(a[i]);
          else y.pb(a[i]);
   
   for(int i=1;i<x.size();i++) x[i] += x[i-1];
   for(int i=1;i<y.size();i++) y[i] += y[i-1];
       
   int res = 0;
    
   for(int i=0;i<x.size();i++)
   {
       int temp = x[i];
       
       int rem = (n - i  + d)/(d + 1);
       
       temp += y[ min((int)y.size() - 1,rem)];
       
       res = max(res,temp);
   }
    
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