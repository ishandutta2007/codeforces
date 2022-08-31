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

struct dat
{
	//Use required attributes
	int sum;

	//Default Values
	dat() : sum(0) {};
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
        cur.sum = l.sum + r.sum;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
        
		st[node].sum = lazy[node]*(R-L+1);
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

	dat pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
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
			lazy[node] = val;
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
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	dat query(int pos)
	{
		return pQuery(1, 1, N, pos);
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


void solve()
{
   int n,q;
    cin >> n >> q;
    
   string s,t;
    cin >> s >> t;
    
   pii a[q];
    f(i,q) cin >> a[i].F >> a[i].S;
  
    swap(s,t);
    reverse(a,a+q);
    
    SegTree one;
    one.init(n+4);
        
   f(i,n) 
       if(s[i] == '1') one.update(i+1,1);
    
   f(i,q)
   {
       int ones = one.query(a[i].F,a[i].S).sum;
       int zeros = a[i].S - a[i].F + 1 - ones;
       
       if(ones == zeros) 
       {
           cout << "NO\n";
           return;
       }
       
       //otherwise turns all into one thing
       if(ones > zeros)
       {
           one.update(a[i].F,a[i].S,1);
       }
       else one.update(a[i].F,a[i].S,0);
       
   }
    
   int flag = 1;
    
   f(i,n) 
   {
       int vv = one.query(i+1).sum;
       if(vv != (t[i] - '0')) flag = 0;
   }
    
   if(flag) cout <<"YES\n"; 
   else cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}