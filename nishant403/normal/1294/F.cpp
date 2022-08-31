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

const int N = 2e5+10;
vi g[N];
pii dp1[N]; 
pii dp2[N]; 
pii dp3[N];
int v[3] = {0};
int ans = 0;
int n;

void dfs(int node,int par = -1)
{
    vector<pii> d;
    
    for(auto x : g[node])
    if(par != x)
    {
        dfs(x,node);
        d.pb({dp1[x].F+1,dp1[x].S});
    }
    
    d.pb({0,node});
       
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    
    dp1[node] = d[0];
    
    if(d.size() > 1) dp2[node] = d[1];
    
    if(d.size() >= 3)
    {
        if(d[0].F + d[1].F + d[2].F > ans)
        {
        ans = d[0].F+d[1].F+d[2].F;
        f(i,3) v[i] = d[i].S;    
        }
    }
}

void dfs2(int node,int par = -1)
{   
    if(par != -1 && dp3[node].F < dp3[par].F + 1)
       dp3[node] = {dp3[par].F + 1,dp3[par].S};
   
    pii mxx[2];
    mxx[0] = mxx[1] = {-1,-1};
    int go[2] = {-1,-1}; 
   
    for(auto x : g[node])
    {
        if(x == par) continue;
        if(dp1[x].F > mxx[0].F) mxx[0] = dp1[x],go[0]=x;
   
    }


    for(auto x : g[node])
    {
        if(x == par) continue;
    
        if(x != go[0] && dp1[x].F > mxx[1].F) mxx[1] = dp1[x],go[1] = x;
    }
    
    for(auto x : g[node])
    {
        if(x!=par)
        {
            if(go[0] != x && go[0] != -1)
            {
                dp3[x].F = mxx[0].F + 2;
                dp3[x].S = mxx[0].S;
            }
            else if(go[1] != -1 && go[1] != x)
            { 
                dp3[x].F = mxx[1].F + 2;
                dp3[x].S = mxx[1].S;
            }
            
            if(par != -1 && dp3[x].F < dp3[node].F + 1)
            {
                dp3[x].F = dp3[node].F+1,dp3[x].S = dp3[node].S;
            }
            else if(dp3[x].F < 1) 
            {
                dp3[x] = {1,1};
            }
            
            dfs2(x,node);
        }
    }
}

void solve()
{
   cin >> n;
    
   int a,b;
    
   f(i,n-1)
   {
       cin >> a >> b;
       g[a].pb(b);
       g[b].pb(a);
   }
    
   f(i,n+5) dp1[i] = {-1,-1}; 
   f(i,n+5) dp2[i] = {-1,-1}; 
   f(i,n+5) dp3[i] = {-1,-1}; 
    
   dfs(1);
   dfs2(1);
    
   for(int i=1;i<=n;i++)
   {
       int node = i;
       
       if(dp1[i].F == -1) continue;
       if(dp2[i].F == -1) continue;
       if(dp3[i].F == -1) continue;
       
       if(ans < dp1[i].F + dp2[i].F + dp3[i].F)
       {         
           ans = dp1[node].F + dp2[node].F + dp3[node].F;
           v[0] = dp1[node].S;
           v[1] = dp2[node].S;
           v[2] = dp3[node].S;
       }
   }
    
   cout << ans << '\n';
   f(i,3) cout << v[i] <<" ";  
}

signed main()
{
    fast;
    solve();
}