#include <bits/stdc++.h>
using namespace std;

//brute
  
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

const int N = 1e5 + 10;
int n,k;
int sum[N][41];
int a[N];
int res[N];
vi g[N];

void dfs(int node,int par = -1,int dep = 0)
{
    for(auto x : g[node])
        if(x != par)
    {
        dfs(x,node,dep + 1);
    
        for(int j=0;j<k+k-1;j++)
            sum[node][(j + 1)]^=sum[x][j];
        
        sum[node][0]^=sum[x][k+k-1];
    }
    
    sum[node][0]^=a[node];
}

int tmp[40];

void dfs2(int node,int par = -1)
{
     for(int j=k;j<k+k;j++) res[node]^=sum[node][j];
    
     for(auto x : g[node])
     {
         if(x == par) continue;
         
         for(int j=0;j<k+k;j++)
         {
             tmp[(j + 1)%(k + k)] ^= sum[node][j];
             tmp[(j + 1)%(k + k)] ^= sum[x][(j - 1 + k + k)%(k + k)];
         }
         
         for(int j=0;j<k+k;j++)
         {
             sum[x][j] ^= tmp[j];
             tmp[j]  = 0;
         }
         
         dfs2(x,node);
     }
}

void solve()
{
    cin >> n >> k;
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    for(int i=1;i<=n;i++) cin >> a[i];
    
    dfs(1);
    dfs2(1);
    
    for(int i=1;i<=n;i++)
    {
        if(res[i] == 0) cout << 0 << ' ';
        else cout << 1 << ' ';
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