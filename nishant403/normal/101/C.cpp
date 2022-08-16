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

void check(pii a,pii b)
{
     if(b.F == 0 && b.S == 0)
     {
         if(a.F == 0 && a.S == 0)
         {
             cout <<"YES\n";
             exit(0);
         }
         
         return;
     }
    
   int numy = (a.F*b.F) + (a.S*b.S);
   int deny = (b.F*b.F) + (b.S*b.S);
   int numx = (a.F*b.S) - (a.S*b.F);
   int denx = deny;
    
   if(numx % denx == 0 && numy % deny == 0)
   {
       cout <<"YES\n";
       exit(0);
   }
}

void solve()
{
   pii a[3];
    f(i,3) cin >> a[i].F >> a[i].S;
    
   f(i,4)
   {
       check({a[1].F - a[0].F, a[1].S - a[0].S} , a[2]);
       a[0].F*=-1;
       swap(a[0].F,a[0].S);
   }
    
   cout << "NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}