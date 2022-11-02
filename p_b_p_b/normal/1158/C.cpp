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
	#define sz 505050
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

int n,N;
struct hh{int t,nxt;}edge[sz*40];
int head[sz<<3],ecnt;
int deg[sz<<3];
void make_edge(int f,int t){edge[++ecnt]=(hh){t,head[f]};head[f]=ecnt;++deg[t];}
int a[sz<<3],ans[sz],cc;
void topo()
{
	queue<int>q;
	rep(i,1,N) if (!deg[i]) q.push(i);
	while (!q.empty())
	{
		int x=q.front();q.pop();a[x]=++cc;
		#define v edge[i].t
		go(x) if (!--deg[v]) q.push(v);
		#undef v
	}
}

int id[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void build(int k,int l,int r)
{
	if (l==r) return (void)(id[k]=l);
	int mid=(l+r)>>1;
	build(lson),build(rson);id[k]=++N;
	make_edge(id[ls],id[k]),make_edge(id[rs],id[k]);
}
void link(int k,int l,int r,int x,int y,int t)
{
	if (x<=l&&r<=y) return make_edge(id[k],t);
	int mid=(l+r)>>1;
	if (x<=mid) link(lson,x,y,t);
	if (y>mid) link(rson,x,y,t);
}

void clear(){rep(i,1,N) deg[i]=head[i]=a[i]=ans[i]=0;cc=ecnt=N=0;}

void solve()
{
	read(n);
	N=n;build(1,1,n);
	int x;
	rep(i,1,n)
	{
		read(x);
		if (x==-1) continue;
		if (x-1>=i+1) link(1,1,n,i+1,x-1,i);
		if (x!=n+1) make_edge(i,x);
	}
	topo();
	if (cc!=N) return puts("-1"),clear();
	rep(i,1,n) ans[i]=a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) ans[i]=lower_bound(a+1,a+n+1,ans[i])-a;
	rep(i,1,n) printf("%d ",ans[i]);puts("");
	clear();
}

int main()
{
	file();
	int T;read(T);
	while (T--) solve();
}