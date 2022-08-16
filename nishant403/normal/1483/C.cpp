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
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

//ref : https://github.com/nishant403/Competitive-Coding/blob/master/Ashishgup%20library/Segment%20Tree.cpp

const int inf = 1e18;

struct dat
{
	//Use required attributes
	int mx;

	//Default Values
	dat() : mx(-inf) {};
};

struct SegTree
{
	int N;
	vector<dat> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(dat &cur, dat &l, dat &r) 
	{
		cur.mx = max(l.mx, r.mx);
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node]; 
		}
        
		st[node].mx += lazy[node];
        lazy[node] = 0;
		cLazy[node] = 0;
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

	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] += val;
            propagate(node, L, R);
            return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
        
		if(L == R)
		{
            st[node].mx = val;
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

	void update(int l, int r, int val)
	{
		Update(1, 1, N, l, r, val);
	}
};



const int N = 3e5 + 10;
int h[N],b[N];
int dp[N];
int n;

void solve()
{
   cin >> n;
    f(i,n) cin >> h[i];
    f(i,n) cin >> b[i];
    
    SegTree go;
    go.init(n);
    
    stack<pair<int,pii> > st;
    
    int mn = 1;
    
    f(i,n)
    {
        //add integer h[i] and update the segtree
        pair<int,pii> adder = {i,{i,i}};
        
        while(st.size() > 0 && h[st.top().F] > h[i])
        {
            auto x = st.top(); st.pop();
            go.update(max((int)1,x.S.F - 1),x.S.S - 1,-b[x.F]);
            
            adder.S.F = x.S.F;
        }
        
        st.push(adder);
        go.update(max((int)1,adder.S.F - 1),adder.S.S - 1,b[adder.F]);
        
        if(h[i] < h[mn]) mn = i;
        dp[i] = b[mn];
        
        dp[i] = max(dp[i], go.query(1, i - 1).mx);
        go.update(i,dp[i]);
        
    }
    
    cout << dp[n];
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}