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
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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

int stt[270001];
struct seg {
	int val[270001];
	int lz[270001];
	void rs(int c, int l, int r) {
		lz[c]=0;
		if (l==r) {
			val[c]=stt[l];
		} 
		else {
			int mid=(l+r)/2;
			rs((c<<1),l,mid);
			rs((c<<1)+1,mid+1,r);
			val[c]=max(val[(c<<1)],val[(c<<1)+1]);
		}		
	}
	void fl(int c) {
		val[(c<<1)]+=lz[c];
		val[(c<<1)+1]+=lz[c];
		lz[(c<<1)]+=lz[c];
		lz[(c<<1)+1]+=lz[c];
		lz[c]=0;
	}

	void up(int c, int l, int r, int tl, int tr, int x) {
		if (l>tr || r<tl) return;
		if (l>=tl && r<=tr) {
			lz[c]+=x;
			val[c]+=x;
		}
		else {
			int mid=(l+r)/2;
			fl(c);
			up((c<<1),l,mid,tl,tr,x);
			up((c<<1)+1,mid+1,r,tl,tr,x);
			val[c]=max(val[(c<<1)],val[(c<<1)+1]);
		}
		// cout<<"iup "<<c<<' '<<l<<' '<<r<<' '<<tl<<' '<<tr<<' '<<x<<' '<<val[c]<<endl;
	}
	
	int get(int c, int l, int r, int tl, int tr) {
		if (l>tr || r<tl) return 0;
		if (l>=tl && r<=tr) {
			return val[c];
		}
		else {
			int mid=(l+r)/2;
			fl(c);
			int a= get((c<<1),l,mid,tl,tr);
			int b= get((c<<1)+1,mid+1,r,tl,tr);
			return max(a,b);
		}
	}
};
seg st;

vector<int> gt[100001];
vector<int> req[100001];
int n,m,i,j,k,t,t1,u,v,a,b;
int par[100001][20];
int dep[100001];
int tl[100001];
int tr[100001];
int qu[100001];
int qv[100001];
int res[100001];
int eul[100001];

pii(int) cha[100001];
void dfs(int x, int p) {
	par[x][0]=p;
	for (i=1;i<20;i++) {
		par[x][i]=par[par[x][i-1]][i-1];
	}
	dep[x]=dep[p]+1;
	t++;
	eul[t]=x;
	tl[x]=t;
	for (auto g : gt[x]) if (g-p) dfs(g,x); 
	tr[x]=t;
}
int lca(int u, int v) {
	int x;
	if (dep[u]>dep[v]) x=1; else if (dep[u]<dep[x]) x=-1; else x=0;
	for (i=19;i>=0;i--) if (dep[u]-(1<<i)>=dep[v]) u=par[u][i];
	for (i=19;i>=0;i--) if (dep[v]-(1<<i)>=dep[u]) v=par[v][i];
	if (u==v) return u;
	for (i=19;i>=0;i--) if (par[u][i]-par[v][i]) {
		u=par[u][i];
		v=par[v][i];
	}
	return par[u][0];
}
pii(int) get(int u, int v) {
	int x,y,d,cur;
	y=lca(u,v);
	d=dep[u]+dep[v]-2*dep[y];
	if (dep[u]>=dep[v]) {
		x=d/2; if (dep[u]==dep[v]) x--;
		cur=u;
		for (i=0;i<20;i++) if (x&(1<<i)) cur=par[cur][i];
		return {1,cur};
	} 
	else {
		x=d/2;
		cur=v;
		for (i=0;i<20;i++) if (x&(1<<i)) cur=par[cur][i];
		return {0,cur};
	}
	if (dep[u]>dep[v]) x=1; else if (dep[u]<dep[x]) x=-1; else x=0;
}

void proc(int x) {
	// cout<<"proc "<<x<<endl;
	int y,d,h;
	for (auto g : req[x]) {
		if (g>0) {
			h=g;
			y=1;
		} else {
			h=-g;
			y=0;
		}

		if (y-cha[h].fi) {
			d=st.get(1,1,n,tl[cha[h].se],tr[cha[h].se]);
			res[h]=max(res[h],d);
		}
		else {
			d=st.get(1,1,n,1,tl[cha[h].se]-1);
			res[h]=max(res[h],d);
			d=st.get(1,1,n,tr[cha[h].se]+1,n);
			res[h]=max(res[h],d);
		}
	}
	for (auto g : gt[x]) if (g-par[x][0]) {
		st.up(1,1,n,1,n,1);
		st.up(1,1,n,tl[g],tr[g],-2);
		proc(g);
		st.up(1,1,n,1,n,-1);
		st.up(1,1,n,tl[g],tr[g],2);
	}
	// cout<<"end "<<x<<endl;
}


int main()
{
	fio;
	cin>>n;
	for (i=1;i<n;i++) {
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	dfs(1,1);
	cin>>t;
	for (t1=1;t1<=t;t1++) {
		cin>>qu[t1]>>qv[t1];
		cha[t1]=get(qu[t1],qv[t1]);
		// cout<<t1<<' '<<cha[t1].fi<<' '<<cha[t1].se<<endl;
		req[qu[t1]].push_back(-t1);
		req[qv[t1]].push_back(t1);
	}
	for (i=1;i<=n;i++) {stt[i]=dep[eul[i]]-1;}
	
	st.rs(1,1,n);
	proc(1);
	for (t1=1;t1<=t;t1++) {
		cout<<res[t1]<<endl;
	}
}