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

int inter(pii a,pii b)
{
    if(a.S < b.F || b.S < a.F) return 0;
    
    return min(a.S,b.S) - max(a.F,b.F) + 1;   
}

void solve()
{
   int a,b;
    cin >> a >> b;
    
   int ans = 0;
   
   int l = 1;
   int r = b;
   int res = 0;
    
   while(l <= r)
   {
       int mid = (l + r)/2;
       
       if(a >= (mid - 1)*(mid + 1))
       {
           res = mid;
           l = mid + 1;
       }
       else r = mid - 1;
   }
       
   //sum of 1 , 2 , ... , mid - 1
   ans += ((res-1)*res)/2; 
   
   l = res + 2;
   r = b + 1;
   int n = a;
    
   for (int i = 1, la; i <= n; i = la + 1) 
   {
        la = n / (n / i);
        //n / x yields the same value for i <= x <= la.
        ans += inter({l,r},{i,la})*(n/i);
    } 
    
   cout << ans << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}