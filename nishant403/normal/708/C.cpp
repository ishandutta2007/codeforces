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

struct dat
{
	//Use required attributes
	int mn;

	//Default Values
	dat() : mn(0) {};
};

struct SegTree
{
	int N;
	vector<dat> st;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
	}

	//Write reqd merge functions
	void merge(dat &cur, dat &l, dat &r) 
	{
		cur.mn = max(l.mn, r.mn);
	}
	
	dat Query(int node, int L, int R, int i, int j)
	{
		if(j<L || i>R)
			return dat();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		dat left=Query(node*2, L, M, i, j);
		dat right=Query(node*2 + 1, M + 1, R, i, j);
		dat cur;
		merge(cur, left, right);
		return cur;
	}

	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(L == R)
		{
            st[node].mn = val;
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}
    
	dat query(int l, int r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(int pos, int val)
	{
		pUpdate(1, 1, N, pos, val);
	}
};

const int N = 4e5 + 10;
vi g[N];
int sz[N];

void dfs(int node,int par = -1)
{
    sz[node] = 1;
    
    for(auto x : g[node])
    {
        if(x != par)
        {
            dfs(x,node);
            sz[node] += sz[x];
        }
    }
}

int cen = -1;
int n;

int dfs2(int node,int par = -1)
{
    for(auto x : g[node])
    {
        if(x == par) continue;
        else if(sz[x] > (n/2)) return dfs2(x,node);
    }
    
    return node;
}

SegTree go;

int tin[N];
int tout[N];
int timer = 1;

void dfs3(int node,int par = -1)
{
    tin[node] = timer++;
    
    sz[node] = 1;
    
    for(auto x : g[node])
        if(x != par)
    {
        dfs3(x,node);
        sz[node] += sz[x];
    }
    
    if(sz[node] <= (n/2)) go.update(tin[node],sz[node]);
    
    tout[node] = timer - 1;
}

int ans[N];

void dfs4(int node,int par = -1)
{
    for(auto x : g[node])
        if(x != par)
    {
        int vv = go.query(tin[node],tin[node]).mn;
        
        int nv = n - sz[x];
        
        if(nv <= (n/2)) go.update(tin[node],nv);
        else go.update(tin[node],0);
        
        dfs4(x,node);
        
        go.update(tin[node],vv);
    }
     
    int ss = go.query(1,tin[node] - 1).mn;
    ss = max(ss, go.query(tout[node] + 1,n).mn);
    
    int par_size = n - sz[node];
    
    if(ss >= par_size - (n/2)) ans[node] = 1;
}

void solve()
{
   cin >> n;
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   dfs(1); 
    
   cen = dfs2(1);
  
   go.init(n);
    
   dfs3(cen); 
    
   dfs4(cen); 
    
   for(int i=1;i<=n;i++)
       cout << ans[i] << ' ';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}