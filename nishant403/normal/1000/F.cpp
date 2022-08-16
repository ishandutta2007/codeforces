#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

struct dat
{
	//Use required attributes
	int mn;
    int idd;

	//Default Values
	dat() : mn(1e9) {};
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
		cur.mn = min(l.mn, r.mn);
        
        if(cur.mn == l.mn) cur.idd = l.idd;
        else cur.idd = r.idd;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = 1e9;
            st[node].idd = L;
			return;
		}
        
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
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

const int N = 5e5 + 1000;

int a[N];
vector<pii> qq[N];
vector<int> occ[N];
int res[N];
int n;

signed main()
{
    fast;
    
    cin >> n;
    f(i,n) cin >> a[i];
    
    int q;
    cin >> q;
    
    int l,r;
    
    f(i,N-1) occ[i].pb(-1);
    
    f(i,q)
    {
        cin >> l >> r;
        qq[r].pb({l,i});
    }
    
    SegTree go;
    go.init(n);
    go.build(1,1,n);
        
    f(i,n)
    {
        int zz = occ[a[i]].back();
        if(zz != -1) go.update(zz,1e9);
        go.update(i,occ[a[i]].back());
        
        occ[a[i]].pb(i);
        
        for(auto x : qq[i])
        {
            auto z = go.query(x.F,i);
            
            if(z.mn < x.F) res[x.S] = a[z.idd];
        }
    }
    
    f(i,q) cout << res[i] << '\n';
}