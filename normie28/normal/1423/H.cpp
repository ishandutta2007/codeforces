/*
khoi orz, go check out his algo
-normie-
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "test.inp"
#define FILE_OUT "test.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define ll long long
#define pi 3.1415926535897
//------START-----------//
int n,m,k,decomp[30],t,t1,i,j,res;
struct dsu_save {
    int v, rnkv, u, rnku, szu, szv;

    dsu_save() {}

    dsu_save(int _v, int _rnkv, int _szv, int _u, int _rnku, int _szu)
        : v(_v), rnkv(_rnkv), u(_u), rnku(_rnku), szu(_szu), szv(_szv) {}
};

struct dsu_with_rollbacks {
    vector<int> p, rnk, sz;
    int comps;
    stack<dsu_save> op;

    dsu_with_rollbacks() {}

    dsu_with_rollbacks(int n) {
        p.resize(n);
        rnk.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            rnk[i] = 0;
            sz[i]=1;
        }
        comps = n;
    }

    int find_set(int v) {
        return (v == p[v]) ? v : find_set(p[v]);
    }

    bool unite(int v, int u) {
        v = find_set(v);
        u = find_set(u);
        if (v == u)
            return false;
        comps--;
        if (rnk[v] > rnk[u])
            swap(v, u);
        op.push(dsu_save(v, rnk[v], sz[v],  u, rnk[u], sz[u]));
        p[v] = u;
        if (rnk[u] == rnk[v])
            rnk[u]++;
        sz[u]+= sz[v];
        sz[v]=0;
        return true;
    }

	int find_size (int v)
	{
//		cout<<"find_size() "<<v<<endl;
//		debug();
//		cout<<find_set(v)<<' '<<sz[find_set(v)]<<endl;
		return sz[find_set(v)];
	}
    void rollback() {
        if (op.empty())
            return;
        dsu_save x = op.top();
        op.pop();
        comps++;
        p[x.v] = x.v;
        rnk[x.v] = x.rnkv;
        sz[x.v] = x.szv;
        p[x.u] = x.u;
        rnk[x.u] = x.rnku;
        sz[x.u] = x.szu;
    }
    void debug ()
    {
  //  	for (int g : p) cout<<g<<' '; cout<<endl;
  //  	for (int g : sz) cout<<g<<' '; cout<<endl;
  //  	for (int g : rnk) cout<<g<<' '; cout<<endl;
	}
};

struct query {
    int v, u;
    int typ;
    bool united;
    int res = 0;
    query(int _v, int _u, int _typ) : v(_v), u(_u), typ(_typ) {
    }
};

struct QueryTree {
    vector<vector<query>> t;
    dsu_with_rollbacks dsu;
    int T;

    QueryTree() {}

    QueryTree(int _T, int n) : T(_T) {
        dsu = dsu_with_rollbacks(n);
        t.resize(4 * T + 4);
    }

    void add_to_tree(int v, int l, int r, int ul, int ur, query& q) {
        if (ul > ur)
            return;
        if (l == ul && r == ur) {
            t[v].push_back(q);
            return;
        }
        int mid = (l + r) / 2;
        add_to_tree(2 * v, l, mid, ul, min(ur, mid), q);
        add_to_tree(2 * v + 1, mid + 1, r, max(ul, mid + 1), ur, q);
    }

    void add_query(query q, int l, int r) {
    //	cout<<"add_query "<<l<<' '<<r<<' '<<q.u<<' '<<q.v<<' '<<q.typ<<endl;
        add_to_tree(1, 0, T - 1, l, r, q);
    }

    void dfs(int v, int l, int r, vector<int>& ans) {
    //	cout<<l<<' '<<r<<endl;
        for (query& q : t[v]) {
        	if (q.typ)
        	{
            q.united = dsu.unite(q.v, q.u);
        }
            else 
            {
        }
        }
        
        for (query& q : t[v]) {
        	if (q.typ)
        	{
        }
            else 
            {
            q.res=dsu.find_size(q.v);
            ans.push_back(q.res);
  //          	cout<<l<<' ';
  //          	cout<<q.v<<' '<<q.res<<endl;
        }
        }
  //      	cout<<"debug "<<l<<' '<<r<<endl;
        	dsu.debug();
        if (l == r) 
        {
		}
        else {
            int mid = (l + r) / 2;
            dfs(2 * v, l, mid, ans);
            dfs(2 * v + 1, mid + 1, r, ans);
        }
        for (query q : t[v]) {
            if (q.united)
                dsu.rollback();
        }
    }

    vector<int> solve() {
        vector<int> ans;
        dfs(1, 0, T - 1, ans);
        return ans;
    }
};
vector<pair<int,query>> buc[500001];
//------END-----------//
int main()
{
 //   ofile;
    fio;
    cin>>n>>m>>k; t=1;
    QueryTree st(m+1,n);
    for (i=1;i<=m;i++)
    {
    	int typ;
    	cin>>typ;
    	if (typ==1)
    	{
    		int u,v;
    		cin>>u>>v;
    		u--;
    		v--;
    		buc[t].push_back({i-1,query(u,v,1)});
		}
		else if (typ==2)
		{
			int v;
			cin>>v;
			v--;
			st.add_query(query(v,v,0),i-1,i-1);
		}
		else if (typ==3)
		{
			t++;
			if (t-k>=1) for (auto q : buc[t-k]) st.add_query(q.se,q.fi,i-1);
		}
	}
	for (i=max(1,(t-k+1));i<=t;i++) for (auto q : buc[i]) st.add_query(q.se,q.fi,m);
	auto res=st.solve();
	for (int g : res) cout<<g<<endl;
	
}