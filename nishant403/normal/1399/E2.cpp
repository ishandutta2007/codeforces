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
vector<pair<int,pii> > g[N];
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
    
   int u,v,w,c;
    
   f(i,n-1)
   {
       cin >> u >> v >> w >> c;
       g[u].pb({v,{w,c}});
       g[v].pb({u,{w,c}});
   }
    
   dfs(1); 
    
   int res = 0;
    
   priority_queue<pair<int,pii> > pq1,pq2;
    
   int sum = 0; 
    
   for(int i=1;i<=n;i++)
   {
      for(auto x : g[i])
      {
          if(par[x.F] != i) continue;
          int use = cnt[x.F];
          sum+=(use*x.S.F);
          
          if(x.S.S == 1) pq1.push({(x.S.F - x.S.F/2)*use,{use,x.S.F}});
          else pq2.push({(x.S.F - x.S.F/2)*use,{use,x.S.F}});
      }
   }
    
   while(sum > s)
   {
       int a1 = 0;
       int a2 = 0;
       int b1 = 0;
       
       if(pq2.size() > 0) b1 = pq2.top().F;
       if(pq1.size() > 0) a1 = pq1.top().F;
       
       if(pq1.size() > 1)
       {
               auto x = pq1.top(); pq1.pop();
               a2 = pq1.top().F;
               pq1.push(x);
       }
       
       //one more way for a2
       if(pq1.size() > 0)
       {
           int use = pq1.top().S.F;
           int wt = pq1.top().S.S;
           wt/=2;
           wt-=wt/2;
           a2 = max(a2 , use*wt);
       }
       
       if(sum - a1 > s && b1 > a1 + a2)
       {
           auto x = pq2.top(); pq2.pop();
           res+=2;
           sum-=x.F;
           x.S.S = x.S.S/2;
           x.F = (x.S.S - x.S.S/2)*x.S.F;
           if(x.S.S > 0) pq2.push(x);
       }
       else
       {  
           auto x = pq1.top(); pq1.pop();
           res++;
           sum-=x.F;
           x.S.S = x.S.S/2;
           x.F = (x.S.S - x.S.S/2)*x.S.F;
           if(x.S.S > 0) pq1.push(x);
       }
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