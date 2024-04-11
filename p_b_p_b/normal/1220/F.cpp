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
	#define sz 402020
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

int n;
int a[sz];

int mx[sz<<2],tag[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void pushup(int k){mx[k]=max(mx[ls],mx[rs]);}
void Add(int k,int w){tag[k]+=w,mx[k]+=w;}
void pushdown(int k){Add(ls,tag[k]),Add(rs,tag[k]),tag[k]=0;}
void add(int k,int l,int r,int x,int y,int w)
{
	if (y<x) return;
	if (x<=l&&r<=y) return Add(k,w);
	pushdown(k);
	int mid=(l+r)>>1;
	if (x<=mid) add(lson,x,y,w);
	if (y>mid) add(rson,x,y,w);
	pushup(k);
}
int query(int k,int l,int r,int x)
{
	if (l==r) return mx[k];
	pushdown(k);
	int mid=(l+r)>>1;
	if (x<=mid) return query(lson,x);
	return query(rson,x);
}
void build(int k,int l,int r)
{
	mx[k]=-1e9;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(lson),build(rson);
}
void debug(int k,int l,int r)
{
	if (l==r) return (void)(printf("%d ",mx[k]));
	int mid=(l+r)>>1;pushdown(k);
	debug(lson),debug(rson);
}

int L[sz],R[sz];
void init()
{
	a[0]=a[n+n+1]=-1e9;
	stack<int>s;
	rep(i,1,n+n+1)
	{
		while (!s.empty()&&a[s.top()]>=a[i]) R[s.top()]=i,s.pop();
		s.push(i);
	}
	s.pop();
	drep(i,n+n,0)
	{
		while (!s.empty()&&a[s.top()]>=a[i]) L[s.top()]=i,s.pop();
		s.push(i);
	}
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(a[i]),a[i+n]=a[i];
	build(1,1,n+n);
	init();
	rep(i,1,n)
	{
		add(1,1,n+n,i,i,1e9);
		if (L[i]==0) add(1,1,n+n,i,i,1);
		else add(1,1,n+n,i,i,query(1,1,n+n,L[i])+1);
		add(1,1,n+n,L[i]+1,i-1,1);
//		debug(1,1,n+n),puts("");
	}
	int ans=mx[1],pos=0;
//	debug(1,1,n+n),puts("");
	rep(i,n+1,n+n)
	{
		int p=0;
		add(1,1,n+n,i,i,1e9),add(1,1,n+n,L[i]+1,i-1,1),add(1,1,n+n,i-n,R[i-n]-1,-1),add(1,1,n+n,i-n,i-n,-1e9);
		if (L[i]<=i-n) add(1,1,n+n,i,i,1);
		else add(1,1,n+n,i,i,p=query(1,1,n+n,L[i])+1);
		pos=chkmin(ans,mx[1])?i-n:pos;
	}
	cout<<ans<<' '<<pos;
	return 0;
}