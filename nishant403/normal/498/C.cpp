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

const int inf = 1e9;

struct fe
{
    int u , v , cap , f = 0;
    fe(int u,int v,int c) : u(u) , v(v) , cap(c){}
};

struct Dinic
{
     int n , m = 0;
     vector < fe > e ;
     vector < vector<int> > g;
     vector< int > ptr , lev;
     queue < int > q;
     int s , t;
     Dinic(int s,int t, int n): s(s) , t(t) , n(n)
     {
        g.resize(n+1);
        ptr.resize(n+1);
        lev.resize(n+1);
     }
     
     void add_edge(int u, int v,int cap)
     {
         e.pb({u,v,cap});
         e.pb({v,u,0LL});
         g[u].pb(m);m++;
         g[v].pb(m);m++;
     }
     
     bool bfs()
     {
        
         while(!q.empty())
         {
             int p = q.front();
             q.pop();
             for(auto id : g[p])
             {
                 if( e[id].cap != e[id].f && lev[e[id].v] == -1)
                 {
                    lev[e[id].v] = lev[p] + 1;
                    q.push(e[id].v);
                 }
             }
         }
         return lev[t] != -1;
     }
     
     int dfs(int u,int cur)
     {
         if(u == t) return cur;
         for(int &cid = ptr[u] ; cid < (int)g[u].size() ; cid++ )
         {
             int id = g[u][cid] ; 
             int v  = e[id].v ;
             if( lev[u] == lev[v] -1 && e[id].f != e[id].cap)
             {
                 int x = dfs(v,min(e[id].cap-e[id].f,cur));
                 if(x!=0)
                 {
                     e[id].f += x;
                     e[id^1].f -= x; 
                     return x;
                 }
             }
         }
         return 0;
     }
     
     int maxflow()
     {
         int ff = 0;
         while(1)
         {
             fill(lev.begin() , lev.end() , -1);
             lev[s] = 0;
             q.push(s);
             if(!bfs()) return ff;
             fill(ptr.begin(), ptr.end(), 0);
             while(auto x = dfs(s,inf))
                ff+= x;
         }
         
     }
};

const int N = 105;

map<int,set<pii> > mp;
pii ed[N];
int a[N];
int n,m;

signed main()
{
    fast;
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++) cin >> a[i];
    
    for(int i=1;i<=m;i++)
    {
        cin >> ed[i].F >> ed[i].S;
        if(ed[i].F % 2 == 0) swap(ed[i].F,ed[i].S);
    }
    
    for(int i=1;i<=n;i++)
    {
        int temp = a[i];
        
        for(int j=2;(j*j) <= temp;j++)
        {
            if(temp % j == 0)
            {
                int cn = 0;
                
                while(temp % j == 0) 
                {
                    temp/=j;
                    cn++;
                }
                
                mp[j].insert({i,cn});
            }
        }
        
        if(temp > 1) mp[temp].insert({i,1});
    }
    
    int res = 0;
    
    for(auto x : mp)
    {
        Dinic go(n+1,n+2,n+5);
        
        for(auto y : x.S) 
        {
            if(y.F % 2 == 1) go.add_edge(n+1,y.F,y.S);
            else go.add_edge(y.F,n+2,y.S);
        }
        
        for(int i=1;i<=m;i++) go.add_edge(ed[i].F , ed[i].S , 100000);
        
        res+=go.maxflow();
    }
    
    cout << res;
}