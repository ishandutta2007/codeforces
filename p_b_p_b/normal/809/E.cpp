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
	#define mod 1000000007ll
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
		#ifndef ONLINE_JUDGE
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

int pri[sz],mu[sz],phi[sz],cnt;
bool npri[sz];
ll f[sz];
void init()
{
	mu[1]=phi[1]=1;
	#define x i*pri[j]
	rep(i,2,sz-1)
	{
		if (!npri[i]) pri[++cnt]=i,mu[i]=-1,phi[i]=i-1;
		for (int j=1;j<=cnt&&x<sz;j++)
		{
			npri[x]=1;
			if (i%pri[j]) mu[x]=-mu[i],phi[x]=(pri[j]-1)*phi[i];
			else { phi[x]=pri[j]*phi[i]; break; }
		}
	}
	#undef x
	rep(i,1,sz-1) for (int j=i;j<sz;j+=i) (f[j]+=1ll*i*mu[j/i]*inv(phi[i])%mod)%=mod;
}

int n;
int p[sz];
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

int fa[sz][30],dep[sz],dfn[sz],c;
void dfs(int x,int f)
{
	dep[x]=dep[fa[x][0]=f]+1;dfn[x]=++c;
	rep(i,1,20) fa[x][i]=fa[fa[x][i-1]][i-1];
	#define v edge[i].t
	go(x) if (v!=f) dfs(v,x);
	#undef v
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	drep(i,20,0)
		if (fa[x][i]&&dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if (x==y) return x;
	drep(i,20,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

namespace Solve
{
	int m;
	struct hhh{int id,p;}S[sz];
	struct hh{int t,nxt;}edge[sz<<1];
	int head[sz],ecnt;
	void make_edge(int f,int t)
	{
		edge[++ecnt]=(hh){t,head[f]};
		head[f]=ecnt;
		edge[++ecnt]=(hh){f,head[t]};
		head[t]=ecnt;
	}
	
	int st[sz],top;
	void insert(int x)
	{
		if (top<=1) return void(st[++top]=x);
		int lca=::lca(x,st[top]);
		if (lca==st[top]) return void(st[++top]=x);
		while (top>1)
		{
			int q=st[top-1],&p=st[top];
			if (dfn[q]==dfn[lca]) { make_edge(q,p); --top; break; }
			if (dfn[q]<dfn[lca]) { make_edge(lca,p); p=lca; break; }
			make_edge(p,q),--top;
		}
		st[++top]=x;
	}
	
	ll D[sz];
	#define v edge[i].t
	void dfs1(int x,int fa)
	{
		go(x) 
			if (v!=fa) 
				dfs1(v,x),(D[x]+=D[v])%=mod;
	}
	void dfs2(int x,int fa){go(x) if (v!=fa) dfs2(v,x);D[x]=D[x]*(dep[x]-dep[fa])%mod;}
	void dfs3(int x,int fa){(D[x]+=D[fa])%=mod;go(x) if (v!=fa) dfs3(v,x);}
	void del(int x,int fa){D[x]=0;go(x) if (v!=fa) del(v,x);head[x]=0;}
	#undef v
	
	ll solve()
	{
		bool flg=0;
		rep(i,1,m) flg|=(S[i].p==1);
		if (!flg) S[++m]=(hhh){0,1};
		sort(S+1,S+m+1,[](const hhh &x,const hhh &y){return dfn[x.p]<dfn[y.p];});
		rep(i,1,m) insert(S[i].p);
		while (top>1) make_edge(st[top],st[top-1]),--top;
		top=0;
		rep(i,1,m) (D[S[i].p]+=phi[S[i].id])%=mod;
		dfs1(1,0);D[1]=0;dfs2(1,0);dfs3(1,0);
		ll ret=0;
		rep(i,1,m) (ret+=phi[S[i].id]*D[S[i].p]%mod)%=mod;
		rep(i,1,m) S[i]=(hhh){0,0};
		del(1,0);
		ecnt=m=0;
		return ret;
	}
}

ll solve(int T)
{
	ll ret,S1=0,S2=0;
	for (int i=T;i<=n;i+=T) 
		Solve::S[++Solve::m]=(Solve::hhh){i,p[i]},
		(S1+=phi[i])%=mod,
		(S2+=1ll*(dep[p[i]]-1)*phi[i]%mod)%=mod;
	ret=S1*S2*2%mod;
	ll t=Solve::solve();
	ret=(ret-2ll*t+mod+mod)%mod;
	return ret*f[T]%mod;
}

int main()
{
	file();
	init();
	read(n);
	int x,y;
	rep(i,1,n) read(x),p[x]=i;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs(1,0);
	ll ans=0;
	rep(T,1,n) (ans+=solve(T)+mod)%=mod;
	cout<<ans*inv(1ll*n*(n-1)%mod)%mod;
	return 0;
}