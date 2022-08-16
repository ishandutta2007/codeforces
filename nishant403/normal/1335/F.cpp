#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e6+10;
vector<string> col,dir;

vi g[N];

int nex[N];
int vis[N];
int vis2[N];
pii res;

int n,m;

void clear()
{
    for(int i=1;i<=(n*m);i++) g[i].clear();
    for(int i=1;i<=(n*m);i++) vis[i] = vis2[i] = 0;
    res = {0,0};
}

int id(int i,int j)
{
    return (i*m) + j + 1;
}

int findcol(int idd)
{
    int i = (idd - 1)/m;
    int j = idd - (i*m) - 1;
    
    return (col[i][j]=='0');
}


vi cmp;

void dfs(int node)
{
    vis[node] = 1;
    
    for(auto x : g[node])
        if(vis[x] == 0) dfs(x);
    
    cmp.pb(node);
}

int head;

void dfs2(int node)
{
    
    vis2[node] = 1;
    
    if(vis2[nex[node]] == 0) dfs2(nex[node]);
    else if(vis2[nex[node]] == 1) head = node;
        
    vis2[node] = 2;
}

int dis[N];

void dfs3(int node)
{
    if(dis[node] != -1) return;
    
    if(node == head)
    {
        dis[node] = 0;
        return;
    }
    
    dfs3(nex[node]);
    
    dis[node] = 1 + dis[nex[node]];
}

void process()
{
    head = -1;
    
    for(auto x : cmp) if(vis2[x] == 0) dfs2(x);
    
    int len = 1;
    int cur = nex[head];
    
    while(cur != head)
    {
        cur = nex[cur];
        len++;
    }
    
    res.F+=len;
    
    for(auto x : cmp) dfs3(x);
    
    vector<bool> go(len,0);
    
    for(auto x : cmp) if(findcol(x)) go[dis[x]%len] = 1;
                                     
    f(i,len) res.S+=go[i];
}

void solve()
{
   clear();
    
   cin >> n >> m;
    
   for(int i=1;i<=(n*m);i++) dis[i] = -1;
    
   col.resize(n); dir.resize(n);
    
   f(i,n) cin >> col[i];
   f(i,n) cin >> dir[i];
    
   f(i,n) f(j,m) 
   {
       if(dir[i][j] == 'L') nex[id(i,j)] = id(i,j-1);
       else if(dir[i][j] == 'R') nex[id(i,j)] = id(i,j+1);
       else if(dir[i][j] == 'U') nex[id(i,j)] = id(i-1,j);
       else nex[id(i,j)] = id(i+1,j);
   }
   
   for(int i=1;i<=(n*m);i++)
       g[i].pb(nex[i]),g[nex[i]].pb(i);
     
   for(int i=1;i<=(n*m);i++)
       if(vis[i] == 0)
   {
       dfs(i);
       process();
       cmp.clear();   
   }
    
   cout << res.F <<" "<<res.S<<'\n';      
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}