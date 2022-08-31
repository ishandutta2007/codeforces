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
#define f(i,n) for(int i=1;i<=n;i++)
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

const int N = 1e5 + 10;
vi g[N];
int deg[N];
int val[N];

void solve()
{
   int n;
    cin >> n;
    
   f(i,n) cin >> val[i];
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
       deg[u]++;
       deg[v]++;
   }
    
   int res = 0;
   
   f(i,n) res+=val[i]; 
    
   vector<int> go;
   f(i,n) f(j,deg[i]-1) go.pb(val[i]);
   sort(go.begin(),go.end());
   reverse(go.begin(),go.end());
    
   cout << res << ' ';
    
    for(auto x : go)
    {
        res+=x;
        cout << res << ' ';
    }
    cout << '\n';
    
    f(i,n) deg[i] = 0;
   f(i,n) g[i].clear(); 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}