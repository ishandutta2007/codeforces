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

const int N = 1e5 + 10;
vector<int> g[N];
vector<pair<int,pii> > ed;
int vis[N];
vector<int> topo;

int ord[N];
int tim = 0;

int flag = 1;

void dfs(int node)
{
    vis[node] = 1;
    
    for(auto x : g[node])
    {
        if(vis[x] == 0) dfs(x);
        else if(vis[x] == 1) flag = 0;
    }
    
    vis[node] = 2;
    
    ord[node] = tim++;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    
    int u,v,w;
    
    f(i,m)
    {
        cin >> u >> v >> w;
        ed.pb({w,{u,v}});
    }
    
    int l = 0;
    int r = 1e9;
    int res = r;
    
    vector<int> ans;
    
    while(l <= r)
    {
        int mid = (l + r)/2;
        
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            vis[i] = 0;
        }
        
        flag = 1;
        tim = 0;
        
        for(auto x : ed)
            if(x.F > mid) g[x.S.F].pb(x.S.S);
        
        for(int i=1;i<=n;i++)
            if(!vis[i]) dfs(i);
            
        if(flag == 1)
        {
            ans.clear();
            
            f(i,m)
            {
                if(ed[i].F <= mid && ord[ed[i].S.F] < ord[ed[i].S.S])
                {
                    ans.pb(i);
                }
            }
            
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout << res << ' ' << ans.size() << '\n';
    for(auto x : ans) cout << x + 1 << ' ';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}