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
vector<pii> g[N];
int cnt[N];
int par[N];

void dfs(int node,int p = -1)
{
    par[node] = p;
    
    bool leaf = true;
    
    for(auto x : g[node])
    {
        if(x.F == p) continue;
        
        leaf = false;
        dfs(x.F,node);
        cnt[node]+=cnt[x.F];
    }
    
    if(leaf) cnt[node] = 1;
}
    

void solve()
{
   int n,s;
    cin >> n >> s;
    
   int u,v,w;
    
   f(i,n-1)
   {
       cin >> u >> v >> w;
       g[u].pb({v,w});
       g[v].pb({u,w});
   }
    
   dfs(1); 
    
   int res = 0;
    
   priority_queue<pair<int,pii> > pq;
    
   int sum = 0; 
    
   for(int i=1;i<=n;i++)
   {
      for(auto x : g[i])
      {
          if(par[x.F] != i) continue;
          int use = cnt[x.F];
          sum+=(use*x.S);
          pq.push({(x.S - x.S/2)*use,{use,x.S}});
      }
   }
    
   while(sum > s)
   {
       auto x = pq.top(); pq.pop();
       res++;
       sum-=x.F;
       x.S.S = x.S.S/2;
       x.F = (x.S.S - x.S.S/2)*x.S.F;
       if(x.S.S > 0) pq.push(x);
   }
    
   cout << res << '\n'; 
    
   for(int i=1;i<=n;i++) g[i].clear(),cnt[i] = 0; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}