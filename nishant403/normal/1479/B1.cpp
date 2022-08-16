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
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   int res = 0;
    
   int last = -1;
   int cnt = 0;
   vector<pii> go;
    
   f(i,n)
   {
       if(a[i] != last && cnt > 0)
       {
           go.pb({last,cnt});
           cnt = 0;
       }
       
       last = a[i];
       cnt++;
   }
    
   go.pb({a[n-1],cnt});
   
   int l1 = -1,l2 = -1; 
 
    int sz = go.size();
    
   f(i,sz) 
   {
       auto x = go[i];
       
       if(l1 == l2)
       {
           if(x.S > 1) l1 = l2 = x.F , res += 2;
           else res += 1,l1 = x.F;
       }
       else if(x.S > 1)
       {
           if(l1 != x.F) res++;
           if(l2 != x.F) res++;
           l1 = l2 = x.F;
       }
       else
       {
           if(l1 == x.F)
           {
               res++;
               l2 = x.F;
           }
           else if(l2 == x.F)
           {
               res++;
               l1 = x.F;
           }
           else if(i == sz - 1)
           {
               res++;
               break;
           }
           else if(go[i+1].F == l1)
           {
               res++;
               l1 = x.F;
           }
           else 
           {
               res++;
               l2 = x.F;
           }
       }
   }
    
   cout << res << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}