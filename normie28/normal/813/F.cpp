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
#define N 100005
int n,m;
struct node{
	int x,y;
};
struct rlt{
	int fa,rel;
};
struct meg{
	int x,y,t;
}a[N];
vector<node>d[N<<2],e[N<<2];
int f[N],g[N],siz[N],ans[N];
rlt getrel(int x)
{
	if(!f[x]) return (rlt){x,0};
	rlt lt=getrel(f[x]);
	return (rlt){lt.fa,lt.rel^g[x]};
}
void Build(int i,int l,int r,int ql,int qr,int yl,int yr)
{
	if(ql==l&&qr==r)
	{
		e[i].push_back((node){yl,yr});
		return ;
	}
	int mid=(l+r)>>1;
	if(qr<=mid) Build(i<<1,l,mid,ql,qr,yl,yr);
	else if(ql>mid) Build(i<<1|1,mid+1,r,ql,qr,yl,yr);
	else Build(i<<1,l,mid,ql,mid,yl,yr),Build(i<<1|1,mid+1,r,mid+1,qr,yl,yr);
}
void dfs(int x,int l,int r,int u)
{
	rlt xf,yf;
	for(int i=0;i<e[x].size();i++)
	{
		xf=getrel(e[x][i].x),yf=getrel(e[x][i].y);
		if(xf.fa==yf.fa)
		{
			if(xf.rel==yf.rel)
				u|=1;
		}
		else
		{
			if(siz[xf.fa]<siz[yf.fa]) swap(xf,yf);
			siz[xf.fa]+=siz[yf.fa];
			f[yf.fa]=xf.fa;
			g[yf.fa]=xf.rel^yf.rel^1;
			d[x].push_back((node){xf.fa,yf.fa});
		}
	}
	if(l==r) ans[l]=u;
	else
	{
		int mid=(l+r)>>1;
		dfs(x<<1,l,mid,u);
		dfs(x<<1|1,mid+1,r,u);
	}
	for(int i=d[x].size()-1;i>=0;i--)
	{
		siz[d[x][i].x]-=siz[d[x][i].y];
		f[d[x][i].y]=g[d[x][i].y]=0;
	}
}
bool cmp(meg a,meg b)
{
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y<b.y;
	return a.t<b.t;
}
int main()
{
	fio;
	cin>>n>>m;
    for(int i=1;i<=m;i++)
    	cin>>a[i].x>>a[i].y,a[i].t=i;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;)
    	if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y)
    		Build(1,1,m,a[i].t,a[i+1].t-1,a[i].x,a[i].y),i+=2;
    	else Build(1,1,m,a[i].t,m,a[i].x,a[i].y),i++;
    for(int i=1;i<=n;i++)
    	siz[i]=1;
    dfs(1,1,m,0);
    for(int i=1;i<=m;i++)
    	if (ans[i])
    		cout<<"NO\n";
		else
    		cout<<"YES\n";
}