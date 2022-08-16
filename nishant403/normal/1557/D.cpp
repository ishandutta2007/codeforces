#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

struct dat
{
	//Use required attributes
	int mx;
    int nex;

	//Default Values
	dat() : mx(0),nex(-1) {};
};

struct SegTree
{
	int N;
	vector<dat> st,lazy;
	vector<bool> cLazy;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		lazy.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
	}

	//Write reqd merge functions
	void merge(dat &cur, dat &l, dat &r) 
	{
        if(l.mx > r.mx)
        {
            cur.mx = l.mx;
            cur.nex = l.nex;
        }
        else
        {
            cur.mx = r.mx;
            cur.nex = r.nex;
        }
    }
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
            merge(lazy[node*2],lazy[node*2],lazy[node]);
            merge(lazy[node*2+1],lazy[node*2+1],lazy[node]);
            
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
		}
        
        merge(st[node],st[node],lazy[node]);
        
        lazy[node].mx = 0;
		cLazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mx = 0;
            st[node].nex = -1;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	dat Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
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

	void Update(int node, int L, int R, int i, int j, int a,int b)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
        
		if(i<=L && R<=j)
		{
            if(lazy[node].mx < a)
            {
                cLazy[node] = 1;
                lazy[node].mx = a;
                lazy[node].nex = b;
                propagate(node, L, R);
            }
            
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, a,b);
		Update(node*2 + 1, M + 1, R, i, j, a,b);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	dat query(int l, int r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(int l, int r, int a,int b)
	{
		Update(1, 1, N, l, r, a,b);
	}
};

const int N =  3e5 + 100;

vector<pii> ranges[N];
pii dp[N];

void solve()
{
   int n,m;
   cin >> n >> m;
    
   int u,v,w;
    
   vector<int> go; 
    
   f(i,m)
   {
       cin >> u >> v >> w;
       ranges[u].pb({v,w});
       go.pb(v);
       go.pb(w);
   }
    
   sort(all(go));
    
   for(int i=1;i<=n;i++)
   {
       for(auto & z : ranges[i])
       {
           z.F = lower_bound(all(go),z.F) - go.begin() + 1;
           z.S = lower_bound(all(go),z.S) - go.begin() + 1;
       }
   }
    
   SegTree seg;
   seg.init(m+m);
   seg.build(1,1,m+m); 
   
   for(int i=n;i>=1;i--)
   {
       dp[i] = {1,-1};
       
       for(auto z : ranges[i])
       {
           auto vv = seg.query(z.F,z.S);
           vv.mx++;
           
           if(vv.mx > dp[i].F)
           {
               dp[i] = {vv.mx,vv.nex};
           }
       }
       
       for(auto z : ranges[i])
       {
           seg.update(z.F,z.S,dp[i].F,i);
       }
   }
    
   pii answer = {-1,-1};
   int id = -1; 
   
    for(int i=1;i<=n;i++)
    {
        answer = max(answer,dp[i]);
        if(answer == dp[i]) id = i;
    }
    
    cout << n - answer.F << '\n';
    
    vector<bool> vis(n+1,0);
    
    while(id != -1)
    {
        vis[id] = 1;
        id = dp[id].S;
    }
    
    for(int i=1;i<=n;i++)
        if(vis[i] == 0) cout << i << ' ';
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}