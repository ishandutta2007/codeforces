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

const int N = 3e5 + 10;
vector<pii> g[N];
pii go[N];
int dp[N];

signed main()
{
    fast;
    
    int n,m;
    cin >> n >> m;
    
    int u,v,w;
    
    vector<pair<int,pii> > go2;
    
    f(i,m)
    {
        cin >> u >> v >> w;
        
        g[u].pb({w,i});
        go2.pb({w,{i,v}});
    }
    
    sort(go2.begin(),go2.end());
    reverse(go2.begin(),go2.end());
    
    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
    for(int i=1;i<=n;i++) reverse(g[i].begin(),g[i].end());
    for(int i=1;i<=n;i++) go[i] = {-1,0};
    
    int id;
    
    for(int i=0;i<m;i++)
    {
        v = go2[i].S.S;
        w = go2[i].F;
        id = go2[i].S.F;
        
        while(go[v].F < (int)g[v].size()-1 && w < g[v][go[v].F+1].F)
        {
            go[v].S = max(go[v].S,dp[g[v][go[v].F+1].S]);
            go[v].F++;
        }
        
        dp[id] = 1 + go[v].S;    
    }
    
    int res = 0;
    
    f(i,m) res = max(res,dp[i]);
    
    cout << res;
}