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

const int N = 3e5 + 10;

vi g[N];
int a[N];

//find frequency of x in the range l to r
int get_fre(int x,int l,int r)
{
    if(x == -1) return 0;
    
    int rs = upper_bound(all(g[x]) , r) - upper_bound(all(g[x]), l - 1);
    
    
    
    return rs;
}

struct dat
{
	//Use required attributes
	pii best;
    pii seq;

	//Default Values
	dat()
    {
        best.F = best.S = -1;
        seq.F = seq.S = -1;
    }
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
        if(l.seq.F == -1) cur = r;
        else if(r.seq.F == -1) cur = l;
        else
        {
            
            cur.seq.F = l.seq.F;
            cur.seq.S = r.seq.S;

            int f1 = get_fre(l.best.F,cur.seq.F , cur.seq.S);
            int f2 = get_fre(r.best.F,cur.seq.F , cur.seq.S);

            if(f1 > f2) cur.best = { l.best.F , f1};
            else cur.best = {r.best.F , f2};
          }
	}
	
	void build(int node, int L, int R)
	{
		if(L==R)
		{
            st[node].seq = {L,L};
            st[node].best = {a[L],1};
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
    
	dat query(int l, int r)
	{
		return Query(1, 1, N, l, r);
	}
};

SegTree go;
    
//total n elements and k is frequency of most frequent 
int go2(int n,int k)
{
    if(n % 2 == 0)
    {
        if(k + k <= n) return 1;
        else return n - (n - k)*2;
    }
    else
    {
        if(k + k <= n + 1) return 1;
        else return n - (n - k)*2;
    }
}

void solve()
{
   int n,q;
    
   cin >> n >> q;
   
   for(int i=1;i<=n;i++) cin >> a[i];
   for(int i=1;i<=n;i++) g[a[i]].pb(i);
   
   go.init(n);
   go.build(1,1,n);
    
   while(q--)
   {
       int l,r;
       cin >> l >> r;
       
       auto res = go.query(l,r).best;
       cout << go2(r - l + 1 , res.S) << '\n';
   }
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}