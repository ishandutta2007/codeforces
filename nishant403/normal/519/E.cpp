#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
 
const int N = 1e5+10;
const int LN = 17;
 
vi graph[N];
int par[N][LN],dep[N];
int sz[N];
 
void dfs(int node,int p=-1)
{
    par[node][0] = p;
    
    sz[node] = 1;
    
    if(p==-1) dep[node] = 0;
    else dep[node] = dep[p] + 1;
    
    for(auto x : graph[node]) if(x!=p)
    {
        dfs(x,node);
        sz[node] += sz[x];
    }
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

int find(int cur,int up)
{
    for(int i=LN-1;i>=0;i--)
        if((up >> i) & 1) cur = par[cur][i];
        
    return cur;
}
    
 
void solve()
{
  memset(par,-1,sizeof(par));
    
  int n,q,l,r;
  cin >> n;
    
  for(int i=2;i<=n;i++)
  {
    cin >> l >> r;
    graph[l].pb(r);
    graph[r].pb(l);
  }
    
  dfs(1); 
    
  for(int i=1;i<LN;i++)
      for(int j=1;j<=n;j++)
        if(par[j][i-1] != -1)  
           par[j][i] = par[par[j][i-1]][i-1];    
         
  cin >> q;    
      
  while(q--)
  {
   cin >> l >> r;
      
   int lc = lca(l,r);   
   int dd = dep[l] + dep[r] - 2*dep[lc];
      
   if(dd % 2 == 1) cout << 0 << '\n';
   else if(l == r) cout << n << '\n';
   else
   {
       int mid = -1;
       
       if(dep[l] - dep[lc] < dep[r] - dep[lc]) swap(l,r);
       
       int mid_node = find(l,dd/2); 
       
       if(mid_node == lc)
       {
           int down_l = find(l,dd/2 - 1);
           int down_r = find(r,dd/2 - 1);
           cout << n - sz[down_l] - sz[down_r] << '\n';
       }
       else
       {
           int one_node_down = find(l,(dd/2) - 1);
           cout << sz[mid_node] - sz[one_node_down] << '\n';
       }
   }
  }
    
}
 
signed main()
{
    fast;
    solve();
}