#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
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
	int sm;

	//Default Values
	dat() : sm(0) {};
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
        cur.sm = l.sm + r.sm;
	}
	
	int pQuery(int node, int L, int R, int start,int sum)
	{
        if(st[node].sm <= sum) return R;
        
        if(L == R) return L - 1;
        
		int M = (L + R)/2;
		
        if(st[node*2].sm <= sum)
        {
            return pQuery(node*2 + 1 , M + 1 , R, start , sum - st[node*2].sm);
        }
        
        return pQuery(node*2 , L, M,start,sum);
        
	}	

	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(L == R)
		{
            st[node].sm += val;
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	int pQuery(int l, int sum)
	{
		return pQuery(1, 1, N, l, sum);
	}

	void update(int pos, int val)
	{
		pUpdate(1, 1, N, pos, val);
	}
};

const int N = 1e5 + 10;

vi pos[N];
int n;
int a[N];
int res[N];
vector<int> q[N];

signed main()
{
    fast;
    
    cin >> n;
    
    f(i,n) cin >> a[i];
    f(i,n) q[1].pb(i);
    
    SegTree go;
    go.init(n);
    
    f(i,n) pos[a[i]].pb(i);
    f(i,n) reverse(all(pos[i]));
    f(i,n) if(pos[i].size() > 0) go.update(pos[i].back(),1);
      
    f(i,n)
    {
        for(auto x : q[i])
        {
            res[x]++;
            int nex = go.pQuery(i,x) + 1;
            q[nex].pb(x);
        }
        
        go.update(i,-1);
        pos[a[i]].pop_back();
        
        if(pos[a[i]].size() > 0) go.update(pos[a[i]].back() , 1);
    }
    
    f(i,n) cout << res[i] << ' ';
}