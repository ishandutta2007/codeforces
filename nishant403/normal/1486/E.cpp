#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 1e5 + 10;
const int inf = 1e9;

vector<pii> g[N];
int dp[N][51];
bool vis[N][51];

#define dat pair<int,pii> 

void solve()
{
   int n,m;
    cin >> n >> m;
    
   int u,v,w;
   
   f(i,m)
   {
       cin >> u >> v >> w;
       g[u].pb({v,w});
       g[v].pb({u,w});
   }
    
   for(int i=1;i<=n;i++)
       f(j,51) dp[i][j] = inf;
    
    
   priority_queue<dat,vector<dat>,greater<dat> > pq; 
   pq.push({0,{1,0}}); 
   dp[1][0] = 0;
    
   while(!pq.empty())
   {
       auto x = pq.top(); pq.pop();
       
       if(vis[x.S.F][x.S.S]) continue;
       
       vis[x.S.F][x.S.S] = 1;
       
       for(auto v : g[x.S.F])
       {
           if(x.S.S == 0)
           {
               if(!vis[v.F][v.S])
                if(dp[v.F][v.S] > x.F)
                {
                    dp[v.F][v.S] = x.F;
                    pq.push({x.F,{v.F,v.S}});
                }
           }
           else if(!vis[v.F][0])
           {
               int cst = x.F + ((x.S.S + v.S)*(x.S.S + v.S));
               
               if(dp[v.F][0] > cst)
               {
                   dp[v.F][0] = cst;
                   pq.push({cst,{v.F,0}});
               }
           }
       }
   }
    
   for(int i=1;i<=n;i++)
   {
       if(dp[i][0] == inf) cout << -1 << ' ';
       else cout << dp[i][0] << ' ';
   }
       
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}