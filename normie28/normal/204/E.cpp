/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 

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
#define pow pw
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
const int MaxN=1<<18;
 
int N,K,n,len;
string s;
int _s[MaxN];
int from[MaxN],used[MaxN],limit[MaxN];
int x[MaxN<<1],y[MaxN<<1],sum[MaxN],wv[MaxN],sa[MaxN],eqc[MaxN],h[MaxN];
void build_sa()
{
	int m=N+255;
	for (int i=1;i<=m;++i) sum[i]=0;
	for (int i=1;i<=n;++i) sum[x[i]]++;
	for (int i=1;i<=m;++i) sum[i]+=sum[i-1];
	for (int i=n;i>=1;--i) sa[sum[x[i]]--]=i;
	for (int j=1,p=1;p<n;j*=2,m=p)
	{
		p=0;
		for (int i=n-j+1;i<=n;++i) y[++p]=i;
		for (int i=1;i<=n;++i) if (sa[i]>j) y[++p]=sa[i]-j;
		for (int i=1;i<=n;++i) wv[i]=x[y[i]];
		for (int i=1;i<=m;++i) sum[i]=0;
		for (int i=1;i<=n;++i) sum[wv[i]]++;
		for (int i=1;i<=m;++i) sum[i]+=sum[i-1];
		for (int i=n;i>=1;--i) sa[sum[wv[i]]--]=y[i];
		for (int i=1;i<=n;++i) y[i]=x[i];
		p=x[sa[1]]=1;
		for (int i=2;i<=n;++i)
		{
			if (!(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j])) ++p; 
			x[sa[i]]=p;
		}
	}
}
 
int pow[20],lg[MaxN];
int RMQ[MaxN][20];
 
void build_height()
{
	for (int i=1;i<=n;++i) eqc[sa[i]]=i;
	int k=0;
	for (int i=1;i<=n;++i)
	{
		if (k) --k;
		while (x[i+k]==x[sa[eqc[i]-1]+k]) ++k;
		h[eqc[i]]=k;
	}
}
 
void build_RMQ()
{
	for (int i=pow[0]=1;i<20;++i) pow[i]=pow[i-1]<<1;
	for (int i=2;i<=n;++i) lg[i]=lg[i/2]+1;
	for (int i=1;i<=n;++i) RMQ[i][0]=h[i];
	for (int k=1;k<20;++k)
		for (int i=1;i<=n;++i)
		{
			RMQ[i][k]=RMQ[i][k-1];
			if (i+pow[k-1]<=n) RMQ[i][k]=min(RMQ[i][k],RMQ[i+pow[k-1]][k-1]);
		}
}
 
int get_RMQ(int L,int R)
{
	if (L>R) return limit[sa[L-1]];
	int x=lg[R-L+1];
	return min(RMQ[L][x],RMQ[R-pow[x]+1][x]);
}
 
void init()
{
	cin>>N>>K;
	for (int i=1;i<=N;++i)
	{
	    cin>>s;
	    len=s.length();
	    s=" "+s;
		for (int p=1;p<=len;++p)
		{
			x[++n]=s[p];
			from[n]=i;
			limit[n]=len-p+1;
		}
		x[++n]=i+255;
	}
	for (int i=1;i<=n;++i) _s[i]=x[i];
	build_sa();
	for (int i=1;i<=n;++i) x[i]=_s[i];
	build_height();
	build_RMQ();
}
 
int up[MaxN],gv[MaxN];
long long res[MaxN];
int tree[MaxN<<1];
 
void add(int k,int L,int R,int x,int y,int d)
{
	if (L==x&&R==y)
	{
		tree[k]=max(tree[k],d);
		return;
	}
	int mid=(L+R)>>1;
	if (y<=mid)
		add(k<<1,L,mid,x,y,d);
	else if (x>mid)
		add(k<<1|1,mid+1,R,x,y,d);
	else
	{
		add(k<<1,L,mid,x,mid,d);
		add(k<<1|1,mid+1,R,mid+1,y,d);
	}
}
 
int get(int x)
{
	int p=0;
	for (int k=x+MaxN-1;k;k>>=1)
		p=max(p,tree[k]);
	return p;
}
 
void work()
{
	int now=1;
	int j=1;
	used[from[sa[1]]]=1;
	for (int i=1;i<=n;++i)
	{
		while (now<K)
		{
			++j;
			if (j>n) break;
			if (!(used[from[sa[j]]]++)) ++now;
		}
		if (j>n) break;
		int p=get_RMQ(i+1,j);
		add(1,1,MaxN,i,j,p);
		up[j+1]=max(up[j+1],p);
		if (!--used[from[sa[i]]]) --now;
	}
	for (int i=1;i<=n;++i)
		gv[i]=get(i);
	int p=0;
	for (int i=1;i<=n;++i)
	{
		p=min(max(p,up[i]),h[i]);
		gv[i]=max(gv[i],p);
	}
	for (int i=1;i<=n;++i)
		res[from[sa[i]]]+=gv[i];
	for (int i=1;i<=N;++i)
        cout<<res[i]<<' ';
}
 
int main()
{
    fio;
	init();
	work();
}