/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
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
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
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
const int N=1e5+5;
ll ans;
int n,m,k,tot,root,now,sn;
int sz[N],a[N];
bool vis[N],vst[N];
int head[N];
struct edge{
	int next,to,w;
	void add(int u,int v,int sz)
	{
		next=head[u];
		head[u]=tot;
		to=v;
		w=sz;
	}
}e[N<<1];
struct point{
	int deep,dis;
}p[N];
struct node{
	int f[N];
	void insert(int x)
	{
		if(x==0) return;
		for(int i=x;i<=n+1;i+=i&(-i))
			f[i]++;
		return;
	}
	void erase(int x)
	{
		if(x==0) return;
		for(int i=x;i<=n+1;i+=i&(-i))
			f[i]--;
		return;
	}
	int get_sum(int x)
	{
		if(x==0) return 0;
		int sum=0;
		for(int i=x;i>=1;i&=(i-1))
			sum+=f[i];
		return sum;
	}
}s;
bool cmp(int x,int y)
{
	return p[x].dis<p[y].dis;
}
void dfs_root(int u,int S)
{
	vis[u]=true;
	sz[u]=1;
	int v,ws=0;
	for(int i=head[u];i;i=e[i].next)
	{
		v=e[i].to;
		if(vis[v] || vst[v]) continue;
		dfs_root(v,S);
		sz[u]+=sz[v];
		ws=max(ws,sz[v]);
	}
	ws=max(ws,S-sz[u]);
	if(ws<now)
	{
		root=u;
		now=ws;
	}
	return;
}
void dfs(int u)
{
	vis[u]=true;
	int v;
	for(int i=head[u];i;i=e[i].next)
	{
		v=e[i].to;
		if(vis[v] || vst[v]) continue;
		a[++tot]=v;
		p[v].deep=p[u].deep+1;
		p[v].dis=p[u].dis+e[i].w;
		dfs(v);
	}
	return;
}
ll calc(int u,int ds,int dep)
{
	tot=1;
	a[1]=u,p[u].deep=dep,p[u].dis=ds;
	memset(vis,false,sizeof vis);
	dfs(u);
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		s.insert(p[a[i]].deep+1);
	int l=1,r=tot;
	ll ss=0;
	while(l<r)
	{
		if(p[a[l]].dis+p[a[r]].dis<=k)
		{
			s.erase(p[a[l]].deep+1);
			ss+=s.get_sum(m-p[a[l]].deep+1);
			l++;
		}
		else
		{
			s.erase(p[a[r]].deep+1);
			r--;
		}
	}
	s.erase(p[a[l]].deep+1);
	return ss;
}
void work(int u)
{
	ans+=calc(u,0,0);
	vst[u]=true;
	int v;
	for(int i=head[u];i;i=e[i].next)
	{
		v=e[i].to;
		if(vst[v]) continue;
		ans-=calc(v,e[i].w,1);
		memset(vis,false,sizeof vis);
		now=sz[v];
		dfs_root(v,sz[v]);
		work(root);
	}
	return;
}
int main()
{
    fio;
    cin>>n>>m>>k;
	int y,z;
	for(int x=2;x<=n;x++)
	{
        cin>>y>>z;
		e[++tot].add(x,y,z);
		e[++tot].add(y,x,z);
	}
	now=n;
	dfs_root(1,n);
	work(root);
    cout<<ans;
}