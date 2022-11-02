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
	#define sz 122222
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
		#ifdef NTFOrz
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

int n,m;
int pos[sz],a[sz];
struct hh{int l,r,id;const bool operator < (const hh &x) const {return r<x.r;}}q[sz];

namespace SegmentTree
{
	int mn[sz<<2],cnt[sz<<2],add[sz<<2];// mn cnt summn=1 tagsum addmn
	ll sum[sz<<2],tag[sz<<2];
	#define ls k<<1
	#define rs k<<1|1
	#define lson ls,l,mid
	#define rson rs,mid+1,r
	void pushup(int k)
	{
		mn[k]=min(mn[ls],mn[rs]),sum[k]=sum[ls]+sum[rs];cnt[k]=0;
		if (mn[ls]==mn[k]) cnt[k]+=cnt[ls];
		if (mn[rs]==mn[k]) cnt[k]+=cnt[rs];
	}
	void Tag(int k,int w){tag[k]+=w;sum[k]+=cnt[k]*w;}
	void Add(int k,int w){mn[k]+=w,add[k]+=w;}
	void pushdown(int k){Add(ls,add[k]),Add(rs,add[k]);add[k]=0;if (mn[ls]==mn[k]) Tag(ls,tag[k]);if (mn[rs]==mn[k]) Tag(rs,tag[k]);tag[k]=0;}
	void Addmn(int k,int l,int r,int x,int y,int w)
	{
		if (x<=l&&r<=y) return Add(k,w);
		pushdown(k);
		int mid=(l+r)>>1;
		if (x<=mid) Addmn(lson,x,y,w);
		if (y>mid) Addmn(rson,x,y,w);
		pushup(k);
	}
	ll query(int k,int l,int r,int x,int y)
	{
		if (x<=l&&r<=y) return sum[k];
		pushdown(k);
		int mid=(l+r)>>1;ll ret=0;
		if (x<=mid) ret+=query(lson,x,y);
		if (y>mid) ret+=query(rson,x,y);
		return ret;
	}
	void build(int k,int l,int r)
	{
		mn[k]=1e9,cnt[k]=r-l+1;
		if (l==r) return;
		int mid=(l+r)>>1;
		build(lson),build(rson);
	}
	void Make(int k,int l,int r,int x)
	{
		if (l==r) return (void)(mn[k]=0,cnt[k]=1);
		int mid=(l+r)>>1;
		pushdown(k);
		if (x<=mid) Make(lson,x);
		else Make(rson,x);
		pushup(k);
	}
}
using namespace SegmentTree;

ll ans[sz];

int main()
{
	file();
	read(n);
	rep(i,1,n) read(a[i]),pos[a[i]]=i;
	read(m);
	int x,y;
	rep(i,1,m) read(x,y),q[i]=(hh){x,y,i};
	sort(q+1,q+m+1);int p=1;
	build(1,1,n);
	rep(i,1,n)
	{
		x=a[i];
		Make(1,1,n,i);
		Addmn(1,1,n,1,i,1);
		if (x!=1&&pos[x-1]<i) Addmn(1,1,n,1,pos[x-1],-1);
		if (x!=n&&pos[x+1]<i) Addmn(1,1,n,1,pos[x+1],-1);
		Tag(1,1);
		while (q[p].r==i) ans[q[p].id]=query(1,1,n,q[p].l,i),++p;
	}
	rep(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}