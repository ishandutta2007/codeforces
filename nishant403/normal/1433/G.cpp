#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e3 + 10;
const int inf = 1e9 + 1000;

int dis[N][N];
vector<pii> g[N];

void solve()
{
   int n,m,k;
    cin >> n >> m >> k;
    
    int u,v,w;
    
    f(i,m)
    {
       cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j] = inf;
    
    for(int i=1;i<=n;i++)
    {
        vector<bool> vis(n+1,0);
        priority_queue<pii,vector<pii>,greater<pii> > pq;
        pq.push({0,i});
        
        while(!pq.empty())
        {
            auto x = pq.top(); pq.pop();
            if(vis[x.S]) continue;
            vis[x.S] = 1;
            dis[i][x.S] = x.F;
            
            for(auto v : g[x.S])
            {
                if(dis[i][v.F] > v.S + x.F)
                {
                    dis[i][v.F] = v.S + x.F;
                    pq.push({dis[i][v.F],v.F});
                }
            }
        }
    }
    
    pii go[k];
    f(i,k) cin >> go[i].F >> go[i].S;
    
    vector<int> ds(k,0);
    f(i,k) ds[i] = dis[go[i].F][go[i].S];
    
    int res = 0;
    f(i,k) res+=ds[i];
    
    for(int i=1;i<=n;i++) for(auto x : g[i])
    {
        int temp = 0;
        
        f(v,k) temp+=min(ds[v],min(dis[go[v].F][i] + dis[x.F][go[v].S],dis[go[v].S][i] + dis[x.F][go[v].F])); 
        
        res = min(res,temp);
    }
    
    cout << res << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}