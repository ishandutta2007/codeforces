#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#endif
struct dsu
{
	int n,par[300100],h[300100],sz[300100];
	dsu (int n)
	{
		for (int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	
	void reset (int n)
	{
		for (int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	int get_par(int x)
	{
		if (par[par[x]]==par[x]) return par[x];
		else return par[x]=get_par(par[x]);
	}
	int check_same(int a, int b)
	{
		return (get_par(a)==get_par(b));
	}
	int add_edge(int a, int b)
	{
		int ha=get_par(a),hb=get_par(b);
		if (ha!=hb)
		{
			if (h[ha]<h[hb])
			{
				par[ha]=hb;
				sz[hb]+=sz[ha];
			}
			else
			if (h[ha]>h[hb])
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
			}
			else
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
				h[ha]++;
			}
			return 1;
		}
		else return 0;
	}
};
dsu gr(300001);


typedef int int_t; // Element type
int_t star[1000001];
struct SegTree
{
    int_t lazy[4000004],val[4000004]; //Contains the current value of each node, as well as the lazy propagation amount stored.
    int_t tree_n;
    void resetK (int_t node, int_t l, int_t r) // Resets the tree nodes. 
    {
        if (l==r) 
        {
            lazy[node]=0;
            val[node]=star[l];
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            lazy[node]=0;
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
    }
    void reset(int_t n)
    {
        resetK(1,1,n);
        tree_n=n;
    }
    void flusha(int_t node, int_t l, int_t r)
    {
        lazy[node<<1]+=lazy[node];
        lazy[(node<<1)+1]+=lazy[node];
        int_t mid=(l+r)/2;
        val[node<<1]+=lazy[node]*(mid-l+1);
        val[(node<<1)+1]+=lazy[node]*(r-(mid+1)+1);
        lazy[node]=0;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff)
    {
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            lazy[node]+=diff;
            val[node]+=diff*(r-l+1);
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diff);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diff);
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
    	if (l>r) return;
        updateK(1,1,tree_n,l,r,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 0;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            return val[node];
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            int_t aa; aa=getK(node<<1,l,mid,tar_l,tar_r);
            int_t bb; bb=getK((node<<1)+1,mid+1,r,tar_l,tar_r);
            return aa+bb;
        }
        
    }
    int_t get(int_t l, int_t r)
    {
    	if (l>r) return 0;
        return getK(1,1,tree_n,l,r);
    }
};
SegTree st;

vector<pii(int)> gt[300001];
int n,m,i,j,k,t,t1,u,v,a,b;
int eu[500001];
int ev[500001];
int ew[500001];
int ex[500001];
int par[300001][20];
int dep[300001],dep2[300001],l[300001],r[300001];
void dfs(int x, int p)
{
    t++;
    // cout<<"dfs "<<x<<' '<<p<<' '<<t<<endl;
    l[x]=t;

    // cout<<x<<endl;
    // cout<<par[x][0]<<' ';
    for (int i=1;i<20;i++)
    {
        par[x][i]=par[par[x][i-1]][i-1];
        // cout<<par[x][i]<<' ';
    }
    for (auto g : gt[x]) if (g.fi-p)
    {
        dep[g.fi]=dep[x]+1;
        dep2[g.fi]=dep2[x]^ew[g.se];
        par[g.fi][0]=x;
        dfs(g.fi,x);
    }
    r[x]=t;
    // cout<<endl;
}
int lca(int u, int v)
{
    // cout<<"lca "<<u<<' '<<v<<endl;
    for (int i=19;i>=0;i--) if (dep[par[u][i]]>=dep[v])
    {
        u=par[u][i];
    }
    for (int i=19;i>=0;i--) if (dep[par[v][i]]>=dep[u])
    {
        v=par[v][i];
    }
    // cout<<"lca "<<u<<' '<<v<<endl;

    if (u==v) return u;
    for (int i=19;i>=0;i--) if (par[u][i]-par[v][i])
    {
        u=par[u][i];
        v=par[v][i];
    }
    // cout<<"lca "<<u<<' '<<v<<endl;

    return par[u][0];
}
int main()
{
	fio;
    cin>>n>>m;
    gr.reset(n);
    for (i=1;i<=m;i++)
    {
        cin>>eu[i]>>ev[i]>>ew[i];
        if (gr.add_edge(eu[i],ev[i]))
        {
            ex[i]=1;
            //  cout<<i<<' '<<eu[i]<<' '<<ev[i]<<endl;
            gt[eu[i]].push_back({ev[i],i});
            gt[ev[i]].push_back({eu[i],i});
        }
        else ex[i]=0;
    }

    for (i=1;i<=n;i++) if (!l[i])
    {
        par[i][0]=i;
        dfs(i,i);
    }

    for (i=1;i<=n;i++) 
    {
        //  cout<<par[i][0]<<' '<<l[i]<<' '<<r[i]<<endl;
    }
    // cout<<endl;
    t=0;
    st.reset(n);
    
    // cout<<endl;


    for (i=1;i<=m;i++) if (!ex[i])
    {
    // cout<<endl;
        if (!(dep2[eu[i]]^dep2[ev[i]]^ew[i])) continue;
        a=lca(eu[i],ev[i]);
        b=st.get(l[eu[i]],l[eu[i]]);
        b+=st.get(l[ev[i]],l[ev[i]]);
        b-=2*st.get(l[a],l[a]);
        // cout<<i<<' '<<eu[i]<<' '<<ev[i]<<' '<<a<<endl;
        if (!b)
        {
            ex[i]=1;
            u=eu[i];
            while(u-a)
            {
                st.update(l[u],r[u],1);
                u=par[u][0];
            }
            u=ev[i];
            while(u-a)
            {
                st.update(l[u],r[u],1);
                u=par[u][0];
            }
        }
    }
    for (i=1;i<=m;i++)
    {
        if (ex[i]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}
// Normie28