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

const int N = 4e5 + 10;
int cnt = 0;
vector<pii> g[N];
int a[N][4];
int n;

void norm(int & x,int & y)
{
    int gc = __gcd(x,y);
    x /= gc;
    y /= gc;
}

map<pii,int> mp;

void add(int u,int v,int w,int x,int id)
{
    //case 1 : 
    pii g1 = {v*(w + x),x*u};
    pii g2 = {v*w,x*(u+v)};
    
    norm(g1.F,g1.S);
    norm(g2.F,g2.S);
    
    if(mp.find(g1) == mp.end()) mp[g1] = ++cnt;
    if(mp.find(g2) == mp.end()) mp[g2] = ++cnt;
    
    int id1 = mp[g1];
    int id2 = mp[g2];
    
    g[id1].pb({id2,id});
    g[id2].pb({id1,id});
}

vector<pii> res;
int vis[N];

int dfs(int node,int par = -1,int ii = -1)
{
    if(ii != -1) vis[ii] = 1;
    
    int ls = -1;
    
    while(!g[node].empty())
    {
        auto x = g[node].back(); g[node].pop_back();
        
        if(vis[x.S]) continue;
        
        int idd = dfs(x.F,node,x.S);
        
        if(idd == -1) continue;
        
        if(ls == -1) ls = idd;
        else 
        {
            res.pb({ls,idd});
            ls = -1;
        }

    }
    
    
    if(par == -1) return -1;
    
    if(ii != -1)
    {
        if(ls == -1) return ii;
        else 
        {
            res.pb({ii,ls});
            return -1;
        }
    }
    
    return ls;
}

void solve()
{
    cin >> n;
  
    f(i,n) f(j,4) cin >> a[i][j];
    
    f(i,n) add(a[i][0],a[i][1],a[i][2],a[i][3],i + 1);
    
    for(int i=1;i<=cnt;i++)
    {
        dfs(i);
    }
    
    
    cout << res.size() <<'\n';
    for(auto x : res) cout << x.F << ' ' << x.S << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}