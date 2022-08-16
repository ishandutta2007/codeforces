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
vector<pii> g[N];
int a[N][2];
pii pos[N][2];
int vis[N];

vi go[2];

void dfs(int node,int state = 0)
{
    vis[node] = 1;

    go[state].pb(node);
    
    for(auto x : g[node])
        if(vis[x.S] == 0) dfs(x.S,state^x.F);
}

void solve()
{
   int n;
    cin >> n;
    
   f(i,n) g[i].clear(),vis[i] = 0; 
    
   f(i,n) cin >> a[i][0];
   f(i,n) cin >> a[i][1];
    
   f(i,n) pos[i][0] = pos[i][1] = {-1,-1}; 
    
   int flag = 1; 
    
   f(i,n) 
   {
       if(pos[a[i][0]][0].F == -1) pos[a[i][0]][0] = {i,0};
       else if(pos[a[i][0]][1].F == -1) pos[a[i][0]][1] = {i,0};
       else flag = 0;
           
       if(pos[a[i][1]][0].F == -1) pos[a[i][1]][0] = {i,1};
       else if(pos[a[i][1]][1].F == -1) pos[a[i][1]][1] = {i,1};
       else flag = 0;
   }
           
   if(flag == 0)
   {
       cout << -1 << '\n';
       return;
   }
    
   f(i,n) if(pos[i][0].F != pos[i][1].F) 
   {
       if(pos[i][0].S == pos[i][1].S) 
       {
           g[pos[i][0].F].pb({1,pos[i][1].F});
           g[pos[i][1].F].pb({1,pos[i][0].F});
       }
       else
       {  
          g[pos[i][0].F].pb({0,pos[i][1].F});
          g[pos[i][1].F].pb({0,pos[i][0].F});
       }
   }
    
   vi ans; 
    
   f(i,n) if(vis[i] == 0)
   {
       dfs(i);
       
       if(go[0].size() < go[1].size())
           for(auto x : go[0]) ans.pb(x);   
       else
           for(auto x : go[1]) ans.pb(x);
           
       go[0].clear(); go[1].clear();    
   }
    
   cout << ans.size() << '\n';
    
   for(auto x : ans) cout << x << ' ';
   cout << '\n';
    
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}