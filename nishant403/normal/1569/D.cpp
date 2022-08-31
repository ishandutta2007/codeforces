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
   int n,m,k;
   cin >> n >> m >> k;
    
   set<int> x,y;
   
   f(i,n)
   {
       int temp;
       cin >> temp;
       x.insert(temp);
   }
    
   f(i,m)
   {
       int temp;
       cin >> temp;
       y.insert(temp);
   }
    
   pii a[k];
    f(i,k) cin >> a[i].F >> a[i].S;
    
   vector<int> X,Y;
   for(auto v : x) X.pb(v);
   for(auto v : y) Y.pb(v);
    
   vector<pair<pii,int> > xx,yy;
    
   f(i,k)
   {
       if(x.find(a[i].F) != x.end() && y.find(a[i].S) != y.end()) ;
       else if(x.find(a[i].F) != x.end())
       {
           int y_end = lower_bound(all(Y),a[i].S) - Y.begin();
           int y_start = y_end - 1;
           int x_ind = lower_bound(all(X),a[i].F) - X.begin();
               
           xx.pb({{y_start,y_end},x_ind});
       }
       else 
       {
           int x_end = lower_bound(all(X),a[i].F) - X.begin();
           int x_start = x_end - 1;
           int y_ind = lower_bound(all(Y),a[i].S) - Y.begin();
               
           yy.pb({{x_start,x_end},y_ind});
       }
   }
    
   sort(all(xx));
   sort(all(yy));
    
   int res = 0;
   
   //case 1 : for xx;
   pii cur_range = {-1,-1};
   int cnt = 0;
   
   map<int,int> repeat;
    
   for(auto v : xx)
   {
       if(v.F != cur_range) 
       {
           cnt = 0;
           for(auto vv : repeat) res -= (vv.S*(vv.S - 1))/2;
           repeat.clear();
       }
       
       repeat[v.S]++;
       
       res += cnt;
       cur_range = v.F;
       cnt++;
   }
    
   for(auto vv : repeat) res -= (vv.S*(vv.S - 1))/2;
    
   //case 2 : for yy
   cur_range = {-1,-1};
   cnt = 0; 
   repeat.clear();
    
   for(auto v : yy)
   {
       if(v.F != cur_range)
       {
          cnt = 0;
          for(auto vv : repeat) res -= (vv.S*(vv.S - 1))/2;
          repeat.clear();
       }
       
       repeat[v.S]++;
       
       res += cnt;
       cur_range = v.F;
       cnt++;
   }
    
   for(auto vv : repeat) res -= (vv.S*(vv.S - 1))/2;
    
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