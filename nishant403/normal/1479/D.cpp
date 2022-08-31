#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const ll inf = 1e18;
const int N = 3e5 + 100;

vi g[N];
int val[N],dep[N],n,q;
pair<int,int> seg_lca[4*N];
int timer2 = 0;
int pos[N];
ll mp[N];

int ct=0;
int root[N], lc[22*N], rc[22*N];
ll st[22*N];

int build(int L, int R)
{
	int node = ++ct;
	if(L==R) return node;
	int M = (L+R)/2;
	lc[node] = build(L, M);
	rc[node] = build(M+1, R);
	return node;
}

int update(int onode, int L, int R, int pos,ll val)
{
	int node = ++ct;
    
	if(L==R)
	{
		st[node] = st[onode]^val;
		return node;
	}
    
	int M = (L+R)/2;
    
	lc[node] = lc[onode];
	rc[node] = rc[onode];
    
	if(pos <= M) lc[node] = update(lc[onode], L, M, pos,val);
	else rc[node] = update(rc[onode], M+1, R, pos , val);
	
    st[node] = st[lc[node]]^st[rc[node]];
	
    return node;
}

ll query(int nodeu,int nodev,int L,int R,int x,int y,int ext)
{
    if(L > y || R < x) return -1;
    
    if(x <= L && R <= y)
    {
        ll xr = st[nodeu]^st[nodev];
        if(ext >= L && ext <= R) xr^=mp[ext];
    
        if(xr == 0) return -1;
        else if(L == R) return L; 
    }
    
	int M = (L+R)/2;
    
    int v1 = query(lc[nodeu],lc[nodev],L,M,x,y,ext);
    
    if(v1 != -1) return v1;
    
    return query(rc[nodeu],rc[nodev],M+1,R,x,y,ext);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll getRand(ll l, ll r)
{
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int lca(int u,int v)
{
    int l = pos[u];
    int r = pos[v];
    if(l > r) swap(l,r);
    
    pair<int,int> res = {N,N};
    
    for(l+=n+n-1,r+=n+n;l<r;l>>=1,r>>=1)
    {
        if(l&1) res = min(res,seg_lca[l++]);
        if(r&1) res = min(res,seg_lca[--r]);
    }
    
    return res.S;
}

void dfs(int node,int par = 0)
{
    root[node] = update(root[par],1,n,val[node],mp[val[node]]);
    
    dep[node] = dep[par] + 1;
    
    seg_lca[timer2+n+n-1] = {dep[node],node};
    pos[node] = timer2++;
    
    for(auto x : g[node])
       if(x != par) 
    {
        dfs(x,node);
        seg_lca[timer2+n+n-1] = {dep[node],node};
        timer2++;
    }
}

signed main()
{
    fast;
    
    cin >> n >> q;
    
    root[0] = build(1,n);
    
    for(int i=1;i<=n;i++) cin >> val[i];
    
    for(int i=1;i<=n;i++) mp[i] = getRand(1,1e18);
    
    int u,v,L,R;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    dfs(1);
    
    for(int i=n+n-2;i>0;i--)
        seg_lca[i] = min(seg_lca[i<<1],seg_lca[(i<<1)^1]);
    
    int l,r;
    
    while(q--)
    {
        cin >> u >> v >> l >> r;
        cout << query(root[u],root[v],1,n,l,r,val[lca(u,v)]) << '\n';
    }    
}