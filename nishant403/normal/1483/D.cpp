#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 605;
const int inf = 1e18;

int dis[N][N];
vector<pii> g[N];

vector<pii> qq[N]; 

int dp[N];

vector<pair<int,pii> > ed;
vector<int> mark;

void solve()
{
    int n,m;
    cin >> n >> m;
    
    int u,v,w;
    
    f(i,n) f(j,n) dis[i][j] = inf;
    f(i,n) dis[i][i] = 0;
    
    f(i,m)
    {
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
        
        ed.pb({w,{u,v}});
        mark.pb(0);
        
        dis[u][v] = min(dis[u][v] , w);
        dis[v][u] = dis[u][v];
    }
    
    for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dis[i][k] < inf && dis[k][j] < inf)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
        }
    }
}
    
    int q;
    cin >> q;
    
    f(i,q)
    {
        cin >> u >> v >> w;
        qq[u].pb({v,w});
        qq[v].pb({u,w});
    }
       
    f(u,n)
    {
        f(i,n)  dp[i] = -inf;
        
        for(auto x : qq[u])
        {
            f(j,n)
            {
                if(dis[j][x.F] == inf) continue;
                
                dp[j] = max(dp[j] , x.S - dis[j][x.F]);
            }
        }
        
        
        for(int i=0;i<m;i++)
        {
            int val = ed[i].F + dis[ed[i].S.F][u];
            
            if(dis[ed[i].S.F][u] == inf) continue;
            if(dp[ed[i].S.S] == -inf) continue;
            
            if(val <= dp[ed[i].S.S]) mark[i] = 1;
        }
    }
    
    int res = 0;
    
    f(i,m) res += mark[i-1];
    
    cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}