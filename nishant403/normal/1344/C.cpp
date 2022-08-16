#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;
vi g[N];
vi gr[N];

int vis[N];
int all[N];

void dfs(int node,int par = -1)
{
    vis[node] = 1;
    
    for(auto x : g[node])
  //      if(x != par)
    {
        if(vis[x] == 1) 
        {
            cout << -1;
            exit(0);
        }
        
        if(vis[x] == 0) dfs(x,node);
    }
    
    vis[node] = 2;
}

int up[N];
int down[N];

int goup(int id)
{
    if(up[id] != -1) return up[id];
    
    up[id] = id;
    
    for(auto x : g[id])
        up[id] = min(up[id] , goup(x));
    
   return up[id];  
}

int godown(int id)
{
    if(down[id] != -1) return down[id];
    
    down[id] = id;
    
    for(auto x : gr[id])
        down[id] = min(down[id],godown(x));
    
    return down[id];
}

void solve()
{
  int n,m;
    cin >> n >> m;
   
  int u,v;
    
   f(i,m)
   {
       cin >> u >> v;
       g[u].pb(v);
       gr[v].pb(u);
   }
    
   f(i,n) if(vis[i] == 0) dfs(i); 
   
   f(i,n) up[i] = down[i] = -1;
    
   f(i,n) if(up[i] == -1) up[i] = goup(i);
   f(i,n) if(down[i] == -1) down[i] = godown(i);
        
   f(i,n) if(up[i] == i && down[i] == i) all[i] = 1;  
   
   int cnt = 0;
   f(i,n) if(all[i] == 1) cnt++;
       
       
   cout << cnt << '\n';
    
   f(i,n)
       if(all[i] == 1) cout << 'A';
       else cout << 'E';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}