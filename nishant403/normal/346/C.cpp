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
	dat() : mn(1e9) {};
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
	}

	//Write reqd merge functions
	void merge(dat &cur, dat &l, dat &r) 
	{
		cur.mn = min(l.mn, r.mn);
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
            st[node].mn = min(st[node].mn , val);
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

const int N = 1e6 + 10;
int rr[N];

void solve()
{
   int n;
   cin >> n;
    
   vector<int> a(n);
    f(i,n) cin >> a[i];
    
   sort(all(a)); 
   a.resize(unique(all(a)) - a.begin()); 
    
   int x,y;
   cin >> x >> y;
   swap(x,y);
    
   SegTree go;
   go.init(y-x+1);
    
   for(int i=1;i<=y-x+1;i++) rr[i] = i + 1;
    
   for(auto z : a) 
   {
       int st = ((x + z - 1) / z)*z;
       
       while(st <= y)
       {
           rr[st - x + 1] = max(rr[st - x + 1],st - x + 1 + z - 1);
           st += z;
       }
   } 
    
    
   go.update(y-x+1,0); 
    
   for(int i=y-x;i>=1;i--) 
       go.update(i,go.query(i+1,rr[i]).mn + 1);
   
   cout << go.query(1,1).mn;
}

signed main()
{
    fast;
    solve();
}