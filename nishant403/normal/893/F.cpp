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
const int inf = 1e9 + 100;

vi g[N];
int dep[N];
int sz[N];
int ord[N];
int tin[N],tout[N],timer = 0;
int a[N];
int n,r,q;

vector<pii> seg[4*N];

void build(int node,int ss,int se)
{
    if(ss == se)
    {
        seg[node].pb({dep[ord[ss]],a[ord[ss]]});
        return;
    }
    
    int mid = (ss + se)/2;
    
    build(node*2+1,ss,mid);
    build(node*2+2,mid+1,se);
    
    for(auto z : seg[node*2+1]) 
        seg[node].pb(z);
    for(auto z : seg[node*2+2]) 
        seg[node].pb(z);
    
    sort(all(seg[node]));
    
    for(int i=1;i<seg[node].size();i++)
        seg[node][i].S = min(seg[node][i].S,seg[node][i-1].S);
}

void dfs(int node,int par = -1,int dis = 0)
{
    ord[timer] = node;
    
    tin[node] = timer++;
    
    sz[node] = 1;
    dep[node] = dis;
    
    for(auto x : g[node])
        if(x != par)
    {
        dfs(x,node,dis + 1);
        sz[node]+=sz[x];
    }
    
    tout[node] = timer - 1;
}

int query(int node,int ss,int se,int l,int r,int d)
{
    if(ss > r || se < l) return inf;
    
    if(l <= ss && se <= r)
    {
        if(seg[node][0].F > d) return inf;
        
        return (*(--upper_bound(all(seg[node]),pii{d+1,-1}))).S;
    }
    
    int mid = (ss + se)/2;
    
    return min(query(node*2+1,ss,mid,l,r,d),query(node*2+2,mid+1,se,l,r,d));
}

void solve()
{
   cin >> n >> r;
    
   for(int i=1;i<=n;i++) cin >> a[i];
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   dfs(r); 
   build(0,0,n-1); 
    
   int last = 0;
   int x,k;
    
   cin >> q; 
    
   while(q--)
   {
       cin >> x >> k;
       
       x = (x + last)%n + 1;
       k = (k + last)%n ;
      
       last = query(0,0,n-1,tin[x],tout[x],k + dep[x]);
       cout << last << '\n';
   }
}

signed main()
{
    fast;
    solve();
}