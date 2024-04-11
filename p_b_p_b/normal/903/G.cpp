#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 202020
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
	templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
	templ inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	char __sr[1<<21],__z[20];int __C=-1,__zz=0;
	inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
	inline void print(register int x)
	{
		if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
		while(__z[++__zz]=x%10+48,x/=10);
		while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
	}
	void file()
	{
		#ifdef NTFOrz
		freopen("a.in","r",stdin);
		#endif
	}
	inline void chktime()
	{
		#ifndef ONLINE_JUDGE
		cout<<(clock()-t)/1000.0<<'\n';
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r

int n,m,Q;
ll a[sz],b[sz],w[sz];

namespace SGT1
{
	ll tr[sz<<2],tag[sz<<2];
	void pushup(int k){tr[k]=min(tr[ls],tr[rs]);}
	void Tag(int k,ll w){tr[k]+=w,tag[k]+=w;}
	void pushdown(int k){ll &w=tag[k];Tag(ls,w),Tag(rs,w);w=0;}
	void modify(int k,int l,int r,int x,int y,ll w)
	{
		if (x<=l&&r<=y) return Tag(k,w);
		int mid=(l+r)>>1; pushdown(k);
		if (x<=mid) modify(lson,x,y,w);
		if (y>mid) modify(rson,x,y,w);
		pushup(k);
	}
	ll query(int k,int l,int r,int x,int y)
	{
		if (x<=l&&r<=y) return tr[k];
		pushdown(k);
		int mid=(l+r)>>1; ll ret=1e18;
		if (x<=mid) chkmin(ret,query(lson,x,y));
		if (y>mid) chkmin(ret,query(rson,x,y));
		return ret;
	}
}
struct hh{int a,b;ll w;const bool operator < (const hh &x) const {return b>x.b;}}e[sz];
void init()
{
	read(n,m,Q);
	drep(i,n-1,1) read(b[i],a[i+1]); b[n]=1e15; a[1]=1e15;
	rep(i,1,n) SGT1::modify(1,1,n,i,i,a[i]);
	int x,y,z;
	rep(i,1,m) read(x,y,z),e[i]=(hh){n-y+1,n-x+1,z};
	sort(e+1,e+m+1);
	rep(i,1,m)
	{
		int A=e[i].a,B=e[i].b; ll W=e[i].w;
		chkmin(W,SGT1::query(1,1,n,1,A));
		w[B]+=W,SGT1::modify(1,1,n,1,A,-W);
	}
}

struct hhh
{
	ll mn,fl;
	hhh(ll x=0,ll y=0){mn=x,fl=y;}
	const hhh operator + (const hhh &a) const {return hhh(min(mn,max(0ll,a.mn-fl)),a.fl+min(fl,a.mn));}
}tr[sz<<2];
void pushup(int k){tr[k]=tr[ls]+tr[rs];}
void modify(int k,int l,int r,int x)
{
	if (l==r) return tr[k]=hhh(1e18,w[l])+hhh(b[l],0),void();
	int mid=(l+r)>>1;
	if (x<=mid) modify(lson,x);
	else modify(rson,x);
	pushup(k);
}

int main()
{
	file();
	init();
	rep(i,1,n) modify(1,1,n,i);
	printf("%lld\n",tr[1].fl);
	int x,y;
	while (Q--) read(x,y),x=n-x,b[x]=y,modify(1,1,n,x),printf("%lld\n",tr[1].fl);
	return 0;
}