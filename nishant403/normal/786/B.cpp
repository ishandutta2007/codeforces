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
#define all(x) x.begin(),x.end()

const int N = 1e6 + 10;

int n,q,s;

int vis[N];
vector<pii> g[N];

const int inf = 1e18;

int dis[N];

void dfs(int node,int ss,int se)
{
    if(ss == se)
    {
        g[n + node].pb({0,ss});
        g[ss].pb({0,5*n + node});
        return;
    }
    else
    {
        g[n + node].pb({0,n + (node*2)});
        g[n + node].pb({0,n + (node*2 + 1)});
        g[5*n + node*2].pb({0,5*n + node});
        g[5*n + node*2 + 1].pb({0,5*n + node});
    }
    
    int mid = (ss + se)/2;
    
    dfs(node*2 , ss , mid);
    dfs(node*2 + 1, mid + 1, se);
}

void dfs2(int node,int ss,int se,int l,int r,int v,int w,bool flag)
{
    if(ss > r || se < l) return;
    
    if(l <= ss && se <= r)
    {
        if(flag) g[node + 5*n].pb({w,v});
        else g[v].pb({w,node + n});
        return;
    }
    
    int mid = (ss + se)/2;
    
    dfs2(node*2,ss,mid,l,r,v,w,flag);
    dfs2(node*2+1,mid+1,se,l,r,v,w,flag);
}

signed main()
{
    fast;
    
    f(i,N) dis[i] = inf;
    
    cin >> n >> q >> s;
    
    dfs(1,1,n);
    
    int t,u,v,w,l,r;
    
    while(q--)
    {
        cin >> t;
        
        if(t == 1)
        {
            cin >> u >> v >> w;
            g[u].pb({w,v});
        }
        else if(t == 2)
        {
            cin >> v >> l >> r >> w;
            dfs2(1,1,n,l,r,v,w,0);
        }
        else
        {
            cin >> v >> l >> r >> w;
            dfs2(1,1,n,l,r,v,w,1);
        }
    }
    
    priority_queue<pii,vector<pii>,greater<pii> > PQ;
    PQ.push({0,s});
    dis[s] = 0;
    
   while(!PQ.empty())
   {
      auto x = PQ.top();  PQ.pop();
       
      if(vis[x.S] == 1) continue;
      vis[x.S] = 1;
      
      for(auto z : g[x.S])
      {
          if(dis[z.S] > dis[x.S] + z.F)
          {
              dis[z.S] = dis[x.S] + z.F;
              PQ.push({dis[z.S],z.S});
          }
      }
   }
    
   for(int i=1;i<=n;i++)
       if(dis[i] == inf) dis[i] = -1;
       
   for(int i=1;i<=n;i++) cout << dis[i] << ' ';
}