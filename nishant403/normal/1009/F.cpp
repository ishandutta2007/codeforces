#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 1e6 + 10;

vi g[N];
int sz[N];

int res[N];
int ans[N];

void dfs(int node,int par = -1)
{
    sz[node] = 1;
    
    for(auto x : g[node])
    {
        if(x == par) continue;
        dfs(x,node);
        sz[node] += sz[x];
    }
}

vector<int> go[N];

void dfs2(int node,int par = -1)
{
    int longest = node;
    
    for(auto x : g[node])
        if(x != par) 
    {
        dfs2(x,node);
        
        if(longest == -1) longest = x;
        else if(go[x].size() > go[longest].size()) longest = x;
    }
    
    swap(go[node],go[longest]);
    go[node].pb(1);      
   
    int ss = go[node].size();
    
    ans[node] = ans[longest];
    
    if(go[node][ans[node]] == 1) ans[node] = ss - 1;
    
    for(auto x : g[node])
        if(x != par && x != longest)
    {
        int sz = go[x].size();
        
         f(i,sz)
         {
           go[node][ss-i-2] += go[x][sz-i-1];
             
           if(go[node][ss-i-2] >  go[node][ans[node]]) ans[node] = ss-i-2;
           else if(go[node][ss-i-2] == go[node][ans[node]]) ans[node] = max(ans[node],ss-i-2);
         }
    }
    
    res[node] = ss - 1 - ans[node];
}

void solve()
{
    int n;
    cin >> n;
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    dfs(1);
    dfs2(1);
    
    for(int i=1;i<=n;i++) cout << res[i]  << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}