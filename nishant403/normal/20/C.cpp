#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define pll pair<ll,ll>
#define S second
#define F first

const ll N = 1e5 + 5;
const ll inf = 9999999999999;
vector<ll> vis(N,0),parent(N,-1),dis(N,inf);
vector<pair<ll,ll> > graph[N];

void shortest_path(ll n)
{
 dis[1]=0;
 parent[1]=-1;
    
 priority_queue<pll,vector<pll> ,greater<pll> > P;
   
    P.push({0,1});
    while(!P.empty())
    {
     auto x = P.top();
        P.pop();
        
      if(vis[x.second]) continue;
       vis[x.second]=1; 
        
      for(auto z : graph[x.S])
      {
          if(vis[z.F]) continue;
          
       if(dis[z.F] > dis[x.S] + z.S)
       {
        dis[z.F]=dis[x.S]+z.S;   
        parent[z.F]=x.S;
        P.push({dis[z.F],z.F});   
       }
          
      }
        
        
    }
}

int main()
{
 ll n,m,a,b,w;
 cin >> n >> m;
    
 for(int i=0;i<m;i++)
 {
  cin >> a >> b >> w;
     graph[a].pb({b,w});
     graph[b].pb({a,w});
 }
   shortest_path(n);
    
 vector<ll> path;
    
  ll x = n;
    
    while(x!= -1)
    {
      path.push_back(x);  
      x=parent[x];  
        
    }
    if(path.size() == 1) cout << -1;
    else
    {
     for(int g = path.size()-1;g>=0;g--) cout << path[g] << " ";   
        
        
        
    }
}