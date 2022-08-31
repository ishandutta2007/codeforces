#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5 + 10;
vi g[N];
int sz[N];
int p[N];

void dfs(int node,int par = -1)
{
   sz[node] = 1;
   p[node] = par;
    
    for(auto x : g[node])
        if(x != par) 
    {
        dfs(x,node);
        sz[node]+=sz[x];
    }
}

void solve()
{
   int n;
    cin >> n;
    
   for(int i=1;i<=n;i++) g[i].clear();
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   dfs(1); 
    
   int ss = n+10;
   vi cen;
    
   for(int i=1;i<=n;i++)
   {
       int mx = 0;
       
       for(auto x : g[i])
       {
           if(p[i] == x) mx = max(mx,n-sz[i]);
           else mx = max(mx,sz[x]);
       }
       
       if(mx < ss)
       {
           cen.clear();
           ss = mx;
       }
       
       if(mx == ss) cen.pb(i);
   }
 
   if(cen.size() == 1)
   {
       cout << 1 << ' ' << g[1][0] << '\n';
       cout << 1 << ' ' << g[1][0] << '\n';
       return;
   }
    
   if(g[cen[0]].size() > 1)
   {
      if(g[cen[0]][0] == cen[1])
      {
          cout << cen[0] << ' ' << g[cen[0]][1] << '\n';
          cout << cen[1] << ' ' << g[cen[0]][1] << '\n';
      }
      else
      {
          cout << cen[0] << ' ' << g[cen[0]][0] << '\n';
          cout << cen[1] << ' ' << g[cen[0]][0] << '\n';
      }
   }
   else
   {
      if(g[cen[1]][0] == cen[0])
      {
          cout << cen[1] << ' ' << g[cen[1]][1] << '\n';
          cout << cen[0] << ' ' << g[cen[1]][1] << '\n';
      }
      else
      {
          cout << cen[1] << ' ' << g[cen[1]][0] << '\n';
          cout << cen[0] << ' ' << g[cen[1]][0] << '\n';
      }
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}