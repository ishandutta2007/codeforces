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
set<int> g[N];
vector<pair<pii,pii> > res;
set<pii> ed;

int dfs(int node,int par = -1)
{
    vector<int> to_remove,t2; 
    g[node].erase(par);
    
    for(auto x : g[node])
    {
        int gg = dfs(x,node);
        
        if(gg != -1) 
        {
            res.pb({{x,node},{-1,-1}});
            t2.pb(x);
        }
        else to_remove.pb(x);
    }
    
    for(auto x : t2) g[node].erase(x);
    
    for(auto x : to_remove)
    {
        if(g[node].size() <= 2) break;
        
        g[node].erase(x);
        
        res.pb({{node,x},{-1,-1}});
    }
    
    if(par != -1 && (int)g[node].size() == 2) return node;
    else return -1;
}

vector<int> g2[N];
int vis2[N];

void solve()
{
   int n;
   cin >> n;
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       
       ed.insert({min(u,v),max(u,v)});
       
       g[u].insert(v);
       g[v].insert(u);
   }
       
   dfs(1); 
    
   for(auto x : res)
       ed.erase({min(x.F.F,x.F.S),max(x.F.F,x.F.S)});
    
   for(auto x : ed)
       g2[x.F].pb(x.S),g2[x.S].pb(x.F);
    
   vector<vi> ss; 
    
   for(int i=1;i<=n;i++)
   {
       if(vis2[i]) continue;
       
       queue<int> q;
       q.push(i);
       vis2[i] = 1;
       
       vector<int> ids;
       
       while(!q.empty())
       {
           auto x = q.front(); q.pop();
        
           ids.pb(x);
           
           for(auto z : g2[x])
               if(!vis2[z]) 
           {
               q.push(z);
               vis2[z] = 1;
           }
       }
       
       vector<int> gg;
       
       for(auto x : ids)
       {
           if(g2[x].size() == 1)
           {
               gg.pb(x);
           }
       }
       
       if(gg.empty())
       {
           gg.pb(ids[0]);
           gg.pb(ids[0]);
       }
       
       ss.pb(gg);
   }
    
    
   for(int i=1;i<ss.size();i++)
   {
       res[i-1].S.F = ss[i-1][1];
       res[i-1].S.S = ss[i][0];
   }
    
   cout << res.size() << '\n';
   for(auto x : res) cout << x.F.F << ' ' << x.F.S << ' ' << x.S.F << ' ' << x.S.S << '\n';
    
   for(int i=1;i<=n;i++) g[i].clear(); 
   for(int i=1;i<=n;i++) vis2[i] = 0;
   for(int i=1;i<=n;i++) g2[i].clear();
   res.clear();
   ed.clear();
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}