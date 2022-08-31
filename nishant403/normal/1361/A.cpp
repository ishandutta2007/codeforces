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

const int N = 5e5 + 10;
vi g[N];
int a[N];
int nex[N];

void solve()
{
   int n,m,u,v;
    cin >> n >> m;
    
   f(i,m)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   f(i,n) cin >> a[i+1];
    
   int flag = 1;
    
   for(int i=1;i<=n;i++)
       for(auto x : g[i]) if(a[x] == a[i]) flag = 0;
      
   pii res[n];
   f(i,n) res[i] = {a[i+1],i+1};
   sort(res,res+n);
    
   for(int i=1;i<=n;i++) nex[i] = 1; 
    
   f(i,n) 
   {
     if(nex[res[i].S] != res[i].F)
     {
         flag = 0;
         break;
     }
      
     for(auto x : g[res[i].S])
         if(nex[x] == res[i].F) nex[x]++;
   } 
   
   if(flag == 0)
   {
       cout << -1;
       return;
   } 
    
   f(i,n) cout <<res[i].S << ' ';
}

signed main()
{
    fast;
    
    solve();
}