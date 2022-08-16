#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5 + 10;
vi g[N];

struct FT
{
    int a[N+N];
    
    void add(int id,int val)
    {
        for(id++;id<N+N;id+=id&-id) a[id]+=val;
    }
    
    int sum(int id)
    {
        int res = 0;
        for(id++;id>0;id-=id&-id) res+=a[id];
        return res;
    }
};

int pos1[N];
int pos2[N];
int dis[N];
int dep[N];

bitset<N> vis;

void bfs()
{
    vis = 0;
    queue<pair<int,int> > q;
    q.push({1,0});
    
    dep[0] = -1;
    int tt = 1;
    
    int mxx = 0;
    
    while(!q.empty())
    {
        auto x = q.front(); q.pop();
     
        vis[x.F] = 1;
        pos1[x.F] = tt++;
        dep[x.F] = dep[x.S] + 1;
        dis[dep[x.F]] = max(dis[dep[x.F]],tt-1); 
        mxx = max(mxx,dep[x.F]);
        
        for(auto u : g[x.F])
            if(vis[u] == 0) q.push({u,x.F});
    }
    
    for(int j=mxx + 1;j<N;j++) dis[j] = dis[j-1];
}

int timer = 1;
int head = -1;
int id[N];
vector<int> chain;

void dfs(int node = 1,int par = -1)
{
    pos2[node] = timer++;
    
    if(node == 1)
    {
        for(auto x : g[node])
        {
            head++;
            chain.pb(timer);
            dfs(x,node);
            chain.back() = timer - chain.back();
        }
    }
    else
    {
        id[node] = head;
        
        for(auto x : g[node])
            if( x != par) dfs(x,node);
    }
}

signed main()
{
    fast;
    
    int n,q;
    cin >> n >> q;
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    int x,d;
    
    FT q1,q2;
    
    bfs();
    dfs();
    
    while(q--)
    {
        cin >> u >> v;
        
        if(u == 0)
        {
            cin >> x >> d;
            
            if(v == 1)
            {
            q1.add(1,x);
            q1.add(dis[d]+1,-x);
            continue;
            }
            
            int len = chain[id[v]];
            int pos = dep[v];
            
            q2.add(max(pos2[v] - d,pos2[v] - dep[v] + 1),x);
            q2.add(pos2[v] + min(d,len - pos) + 1, -x);
            
            int dd = d - dep[v];
            
            if(dd >= 0)
            {
            
            if(dd > 0)
            {
                q2.add(pos2[v] - dep[v] + 1,-x);
                q2.add(pos2[v] - dep[v] + 1 + min(dd,len), x);
            }
                
            q1.add(1,x);
            q1.add(dis[dd]+1,-x);
            
            }
            
        }
        else
        {
            cout << q1.sum(pos1[v]) + q2.sum(pos2[v]) << '\n';
        }
    }
}