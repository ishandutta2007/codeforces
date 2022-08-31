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
   int l,r,m;
    cin >> l >> r >> m;
    
   for(int i=l;i<=r;i++) 
   {
       //m' becomes multiple of i
       int add = (m % i);
       
       if(add == 0)
       {
           cout << i << ' ' << l << ' ' << l << '\n';
           return;
       }
       else
       {
           int mn = i - add; //add this
           int mx = add; //subtract this
           
           if(mn <= r-l)
           {
               cout << i << ' ' << l << ' ' << l + mn<< '\n';
               return;
           }
           
           if(mx <= r-l && m - add > 0)
           {
               cout << i << ' ' << l + mx <<  ' ' << l << '\n';
               return;
           }
       }    
   }
    
   assert( 1 == 0 ); 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}