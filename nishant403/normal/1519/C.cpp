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

const int N = 2e5 + 10;
vector<int> g[N];

void solve()
{
   int n;
    cin >> n;
    
   pii a[n];
    f(i,n) cin >> a[i].F;
    f(i,n) cin >> a[i].S;
    
   f(i,n) g[a[i].F].pb(a[i].S);
    
   for(int i=1;i<=n;i++) sort(all(g[i]));
   for(int i=1;i<=n;i++) reverse(all(g[i]));
    
   for(int i=1;i<=n;i++)
     for(int j=1;j<g[i].size();j++) g[i][j] += g[i][j-1];
       
   vector<pii> sz;
    
   for(int i=1;i<=n;i++) sz.pb({g[i].size(),i});
   sort(all(sz));
   reverse(all(sz));
    
   for(int i=1;i<=n;i++)
   {
       while(!sz.empty() && sz.back().F < i) sz.pop_back();
       
       int res = 0;
       
       for(auto x : sz)
       {
           int tot = x.F;
           int reject = (x.F % i);
           
           res += g[x.S][tot - reject - 1];
       }
       
       cout << res << ' ';
   }
    
   cout << '\n'; 
    
   for(int i=1;i<=n;i++) g[i].clear();
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}