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

const int inf = 2e9;

set<int> elm;
multiset<int> dif;

int qq()
{
    if(elm.size() <= 4) return 0;
    
    int mn = (*next(elm.begin()));
    int mx = (*prev(prev(elm.end())));
    int dd = (*prev(dif.end()));
   
    return mx - mn - dd;
}

void solve()
{
   int n,q;
    cin >> n >> q;
    
   int a[n];
    f(i,n) cin >> a[i];
   sort(a,a+n);
    
   int t,x; 
    
    f(i,n) elm.insert(a[i]);
    f(i,n-1) dif.insert(a[i+1] - a[i]);
    
    elm.insert(-1); //dummy elements 
    elm.insert(inf);
    
    cout << qq() << '\n';
    
   while(q--)
   {
       cin >> t >> x;
       
       if(t == 1)
       {
           auto more = (*elm.upper_bound(x));
           auto less = (*--elm.lower_bound(x));
           
           if(more < inf && less > 0)
               dif.erase(dif.find(more - less));
           
           if(less > 0) dif.insert(x - less);
           if(more < inf) dif.insert(more - x);
           
           elm.insert(x);
       }
       else
       {
           auto more = (*elm.upper_bound(x));
           auto less = (*--elm.lower_bound(x));
           
           if(less > 0)
               dif.erase(dif.find(x-less));
           
           if(more < inf)
               dif.erase(dif.find(more-x));
           
           if(less > 0 && more < inf) dif.insert(more - less);
         
           elm.erase(x);
       }
   
       cout << qq() << '\n';
    }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}