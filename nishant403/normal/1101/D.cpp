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
int spf[N];

void pre()
{
    for(int i=2;i<N;i++)
    {
        if(spf[i] == 0)
        {
            for(int j=i;j<N;j+=i)
            {
                spf[j] = i;
            }
        }
    }
}

vi g[N];

int dp[N];
int vis[N];
int a[N];
int n;
int res = 0;
   
vector<pii> ed[N];

void dfs(int node,int par = -1)
{
    vis[node] = 1;
    
    dp[node] = 1;
    
    vector<int> vals;
    
    for(auto x : g[node])
    {
        if(x == par) continue;
        dfs(x,node);
        vals.pb(dp[x]);
    }
    
    sort(all(vals));
    reverse(all(vals));
    
    if(vals.size() > 0) dp[node] = 1 + vals[0];
    
    res = max(res , dp[node]);
    
    if(vals.size() > 1)
        res = max(res , 1 + vals[0] + vals[1]);   
}

void solve()
{
    cin >> n;
    
    for(int i=1;i<=n;i++) 
    {
        cin >> a[i];
        if(a[i] > 1) res = 1;
    }
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        
        int num = __gcd(a[u],a[v]);
        
        while(num != 1)
        {
            int ss = spf[num];
            ed[ss].pb({u,v});
            while(num % ss == 0) num /= ss;
        }
    }
    
    for(int i=2;i<N;i++)
    {
        for(auto x : ed[i])
        {
            g[x.F].pb(x.S);
            g[x.S].pb(x.F);
        }
        
        for(auto x : ed[i])
            if(vis[x.F] == 0) dfs(x.F);
        
        for(auto x : ed[i])
        {
            vis[x.F] = vis[x.S] = 0;
            g[x.F].clear();
            g[x.S].clear();
        }
    }
    
    cout << res;
}

signed main()
{
    pre();
    
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}