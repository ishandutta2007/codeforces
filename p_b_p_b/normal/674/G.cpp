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
	#define sz 151010
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

int n,m,p;
int a[sz];

int tag[sz<<2];
pii V[15];
struct hh
{
	int ans[6],cnt[6];
	hh(){rep(i,0,5) ans[i]=cnt[i]=0;}
	void all(int w,int len){ans[1]=w,cnt[1]=len;rep(i,2,5) ans[i]=cnt[i]=0;}
	void print()
	{
		rep(i,1,5) V[i]=MP(-cnt[i],ans[i]);
		sort(V+1,V+5+1);
		printf("%d ",100/p);
		rep(i,1,100/p) printf("%d ",V[i].sec);
		puts("");
	}
}tr[sz<<2];
hh merge(hh x,hh y)
{
	hh ret;
	rep(i,1,5) rep(j,1,5) if (x.ans[i]==y.ans[j]) y.cnt[j]+=x.cnt[i],x.cnt[i]=-1,x.ans[i]=0;
	rep(i,1,5) V[i*2-1]=MP(y.cnt[i],y.ans[i]),V[i*2]=MP(x.cnt[i],x.ans[i]);
//	sort(V.begin(),V.end(),[](const pii &x,const pii &y){return x.sec<y.sec;});
//	drep(i,8,0) if (V[i].sec==V[i+1].sec) V[i].fir+=V[i+1].fir,V[i+1]=MP(0,0);
	sort(V+1,V+10+1);
	rep(i,1,5) rep(j,i+1,10) V[j].fir-=max(V[i].fir,0);
	rep(i,6,10) if (V[i].fir>=0) ret.ans[i-5]=V[i].sec,ret.cnt[i-5]=V[i].fir;
	return ret;
}
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void Tag(int k,int l,int r,int w){tag[k]=w;tr[k].all(w,r-l+1);}
void pushdown(int k,int l,int r){if (tag[k]==-1) return;int mid=(l+r)>>1;Tag(lson,tag[k]),Tag(rson,tag[k]),tag[k]=-1;}
void pushup(int k){tr[k]=merge(tr[ls],tr[rs]);}
void modify(int k,int l,int r,int x,int y,int w)
{
	if (x<=l&&r<=y) return Tag(k,l,r,w);
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	if (x<=mid) modify(lson,x,y,w);
	if (y>mid) modify(rson,x,y,w);
	pushup(k);
}
hh query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return tr[k];
	int mid=(l+r)>>1;hh ret;
	pushdown(k,l,r);
	if (x<=mid) ret=merge(ret,query(lson,x,y));
	if (y>mid) ret=merge(ret,query(rson,x,y));
	return ret;
}
void build(int k,int l,int r)
{
	tag[k]=-1;
	if (l==r) return tr[k].all(a[l],1);
	int mid=(l+r)>>1;
	build(lson),build(rson);
	pushup(k);
}

int main()
{
	file();
	read(n,m,p);
	rep(i,1,n) read(a[i]);
	build(1,1,n);
	while (m--)
	{
		int x,y,z,o;read(o,x,y);
		if (o==1) read(z),modify(1,1,n,x,y,z);
		else query(1,1,n,x,y).print();
	}
	return 0;
}