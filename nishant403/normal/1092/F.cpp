#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;
vi g[N];
int a[N];
int sum[N];
int res = 0;
int value = 0;
int tot = 0;

void dfs(int node,int par = -1,int dis = 0)
{
    value+=(a[node]*dis);
    
    sum[node] = a[node];
    
    for(auto x : g[node])
        if(x != par) 
    {
        dfs(x,node,dis+1);
        sum[node]+=sum[x];
    }
}

void dfs2(int node,int par = -1)
{
    res = max(res,value);
    
    for(auto x : g[node])
    {
        if(x == par) continue;
    
        value+=tot - sum[x] - sum[x]; 
        
        dfs2(x,node);
       
        value-=tot - sum[x] - sum[x];
    }
}

signed main()
{
    fast;
  
    int n;
    cin >> n;
    
    f(i,n) cin >> a[i];
    f(i,n) tot+=a[i];
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    dfs(1);
    dfs2(1);
    
    cout << res;
}