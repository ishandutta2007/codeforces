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

inline void I(int &a)
{
  cin >> a;
}

const int N = 1e5+10;
const int LN = 17;

vi g[N];
vi t[N];
int n;
int val;
int q;
int sz[N];
int used[N];
vi graph[N];
int par[N][LN],dep[N];
int parent[N];
int ans[N];

//lca finding
void dfs(int node,int p=-1)
{
    par[node][0] = p;
    
    if(p==-1) dep[node] = 0;
    else dep[node] = dep[p] + 1;
    
    for(auto x : g[node]) if(x!=p) dfs(x,node);
}

//get subtree size
void dfs1(int node,int par = -1)
{
    sz[node] = 1;
    
    for(auto x : g[node])
    if((!used[x]) && x != par)
    {
        dfs1(x,node);
        sz[node]+=sz[x];
    }
}

//find centroid from sizes
int dfs2(int node,int par = -1)
{
     for(auto x : g[node])
         if(x!=par && (!used[x]) && sz[x]>(val/2)) return dfs2(x,node);
         
     return node;
}

int decompose(int node,int par = -1)
{
    dfs1(node);
    val = sz[node];
    int centroid = dfs2(node);
 
    if(par != -1) t[centroid].pb(par),t[par].pb(centroid);
    
    used[centroid] = 1;
    
    for(auto x : g[centroid])
        if(!used[x]) decompose(x,centroid);
        
    return centroid;
}

void dfs3(int node,int par = -1)
{
    parent[node] = par;
    for(auto x : t[node])
        if(x!=par) dfs3(x,node);
}

int lca(int a,int b)
{
 if(dep[a] > dep[b]) swap(a,b);  
 
 int z = dep[b] - dep[a];
   
 for(int i=LN-1;i>=0;i--) if(1LL<<i & z) b = par[b][i];   
     
 if(a==b) return a;    
     
 for(int i=LN-1;i>=0;i--) if(par[a][i] != par[b][i]) a=par[a][i],b=par[b][i];  
 
 return par[a][0];  
}

int dist(int u,int v)
{
    int x = lca(u,v);
    return dep[u] + dep[v] - 2*dep[x];
}

int root;

void update(int node)
{
   int x = node;
    
   ans[node] = 0;
    
   while(x != root)
   {
       x=parent[x];
       ans[x] = min(ans[x],dist(node,x));
   }
}
                    
int query(int node)
{
    int res = ans[node];
      
    int x = node;
    
    while(x!=root)
    {
        x=parent[x];
        res=min(res,ans[x]+dist(x,node));
    }
                    
   return res;                 
}                       

void solve()
{
   I(n); I(q);
    
   int u,v;
    
   f(i,n-1)
   {
       I(u); I(v);
       g[u].pb(v);
       g[v].pb(u);
   }
    
   dfs(1); 
   root = decompose(1);
   dfs3(root);
 
   for(int i=1;i<LN;i++)
      for(int j=1;j<=n;j++)
        if(par[j][i-1] != -1)  
           par[j][i] = par[par[j][i-1]][i-1];    
 
    
   for(int i=1;i<=n;i++) ans[i] = 1e9;
    
   update(1); 
    
   while(q--)
   {
     I(u); I(v);
     if(u==1) update(v);
     else cout << query(v) << '\n';
   }
   
}

signed main()
{
    fast;
    solve();
}