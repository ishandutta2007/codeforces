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

const int N = 1e5 + 10;
vector<pair<int,int> > g[N];
pair<pii,int> info[N];

//subtree size , 2*sum of edges , result

bool cmp(pii & x,pii & y)
{
    return (x.S*y.F) < (y.S*x.F);
}

void dfs(int node,int par = -1)
{
    info[node].F.F = 1;
    
    vector<pii> go;
    
    for(auto x : g[node])
    {
        if(x.F == par) continue;
        
        dfs(x.F,node);
    
        info[node].F.F += info[x.F].F.F;
        
        info[x.F].F.S += 2*x.S;
        
        info[node].F.S += info[x.F].F.S;
        
        info[node].S += info[x.F].S + (x.S*info[x.F].F.F);
        
        go.pb(info[x.F].F);
    }
    
    if(go.empty()) return;
    
    sort(all(go),cmp);
    
    int ss = 0;
     
    for(auto x : go)
    {
        info[node].S += x.F*ss;
        ss += x.S;
    }
}

void solve()
{
   int n;
   cin >> n;
    
   int u,v,w;
  
   f(i,n-1)
   {
       cin >> u >> v >> w;
       g[u].push_back({v,w});
       g[v].push_back({u,w});
   }
    
   dfs(1); 
    
   cout << precise(6) << info[1].S/(double)(n-1);
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}