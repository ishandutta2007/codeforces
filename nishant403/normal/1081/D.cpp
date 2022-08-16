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

const int N = 1e5+10;

map<int,int> g[N],tree[N],spc;
vi dsu(N,0),dp(N,0);

int n,m,k,u,v,w,b,ans = 0;
 
int par(int x)
{
 while(x!=dsu[x])
 {
  dsu[x] = dsu[dsu[x]];   
  x = dsu[x];   
 }
    
 return x;   
}

void unite(int aa,int bb)
{
 dsu[par(aa)] = par(bb);  
}

void getmst()
{
    priority_queue<pair<int,pii> > edges;
    
    f(i,N)
        for(auto x : g[i]) edges.push({-x.S,{i,x.F}});   
       
    while(!edges.empty())
    {
       auto z = edges.top();
       edges.pop();
        
       if(par(z.S.F)!=par(z.S.S)) 
       {
         unite(z.S.S,z.S.F);  
         tree[z.S.S][z.S.F] = -z.F;
         tree[z.S.F][z.S.S] = -z.F;
       }
    }
    
}


void dfs(int node,int p)
{
  dp[node]+=spc[node];
    
  for(auto z : tree[node])
  {
    if(z.F!=p)  
    {
     dfs(z.F,node);
     dp[node]+=dp[z.F];
     
        if(dp[z.F] != k && dp[z.F] != 0) ans=max(ans,z.S);
           
    }
  }
}

void solve()
{
    cin >> n >> m >> k;
    
    vi special(k);
    
    f(i,n+1) spc[i] = 0;
    
    f(i,k) 
    {
        cin >> b;
        spc[b] = 1;
    }
    
    f(i,n+1) dsu[i] = i;
    
    f(i,m)
    {
        cin >> u >> v >> w;
        
        if(g[u].find(v) == g[u].end())
        {
            g[u][v] = w;
            g[v][u] = w;
        }
        else 
        {
          if(g[u][v] > w)
          {
            g[u][v] = w;
            g[v][u] = w;
          }
        }
    }
    
    getmst();
    
    dfs(1,-1);
    
    f(i,k) cout << ans << " ";
    
}

signed main()
{
    fast;
    solve();
}