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
#define dat pii

const int N = 8e5 + 10;
const int inf = 1e18;

vector<pii> g[N];
vector<int> dis(N,inf);

signed main()
{
    fast;
    
    int n,m;
    cin >> n >> m;
    
    int u,v,w;
    
    f(i,m)
    {
       cin >> u >> v >> w;
       u--; v--;
        
       f(j,4) f(k,4) if(!(j & k))
       {
           int w1 = w; 
           if(k & 1) w1 -= w;
           if(k >> 1) w1 += w;
           g[u + (j*n)].pb({w1,v + n*(j|k)});
           
           int w2 = w;
           if(j & 1) w2 -=w;
           if(j >> 1) w2 += w;
           g[v + (k*n)].pb({w2,u + n*(j|k)});
       }
    }
        
    priority_queue<dat,vector<dat>,greater<dat> > pq;
    pq.push({0,0});
    
    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        
        if(x.F >= dis[x.S]) continue;
        dis[x.S] = x.F; 
        
        for(auto v : g[x.S])
        {
           if(dis[v.S] > x.F + v.F)      
               pq.push({x.F + v.F,v.S});
        }
    }
          
    f(i,n)
        if(i > 0) cout << dis[n+n+n+i] << ' '; 
}