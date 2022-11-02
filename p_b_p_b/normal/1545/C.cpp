#include<bits/stdc++.h>
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
	#define sz 1010
	#define mod 998244353ll
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
	inline void print(int x)
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
		cerr<<clock()/1000.0<<'\n';
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
int a[sz][sz];
map<vector<int>,int>id;


namespace MATCH
{
int A[sz][sz];
int e[sz][sz];

int fa[sz];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int pre[sz],match[sz],tp[sz];
queue<int>q;
int vis[sz],T;
int lca(int x,int y) { for (++T;;swap(x,y)) if (x) { x=getfa(x); if (vis[x]==T) return x; vis[x]=T,x=pre[match[x]]; } }
void shrink(int x,int y,int l)
{
	while (getfa(x)!=l)
	{
		pre[x]=y,y=match[x];
		if (tp[y]==2) tp[y]=1,q.push(y);
		if (x==fa[x]) fa[x]=l;
		if (y==fa[y]) fa[y]=l;
		x=pre[y]; 
	}
}
int work(int s)
{
	while (q.size()) q.pop(); q.push(s);
	rep(i,1,n) fa[i]=i,pre[i]=0,tp[i]=0; 
	tp[s]=1;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		rep(v,1,n) if (e[x][v])
		{
			if (getfa(x)==getfa(v)||tp[v]==2) continue;
			if (!tp[v])
			{
				pre[v]=x;
				if (!match[v])
				{
					for (int cur=v;cur;swap(cur,match[pre[cur]])) match[cur]=pre[cur];
					match[0]=0;
					return 1;
				}
				tp[v]=2,tp[match[v]]=1,q.push(match[v]);
			}
			else { int l=lca(x,v); shrink(x,v,l),shrink(v,x,l); }
		}
	}
	return 0;
}

void WORK()
{
	n*=2;
	rep(i,1,n) rep(j,i+1,n) rep(k,1,n/2) if (a[i][k]==a[j][k]) e[i][j]=e[j][i]=1;
	int ans=0;
	rep(i,1,n) rep(j,i+1,n) if (!match[i]&&!match[j]&&e[i][j]) match[i]=j,match[j]=i,++ans;
	rep(i,1,n) ans+=(!match[i]&&work(i));
	assert(ans==n/2);
	static int A[sz][sz]; int K=0;
	rep(i,1,n) if (match[i]>i) 
	{
		++K;
		rep(j,1,n) A[K][j]=a[i][j],A[K+n/2][j]=a[match[i]][j];
	}
	rep(i,1,n) rep(j,1,n/2) a[i][j]=A[i][j];
	rep(i,1,n) match[i]=0; rep(i,1,n) rep(j,1,n) e[i][j]=0;
	n/=2;
}
}

namespace TwoSAT
{
	struct hh{int t,nxt;}edge[sz*sz<<2];
	int head[sz<<1],ecnt;
	void make_edge(int f,int t) { edge[++ecnt]=(hh){t,head[f]}; head[f]=ecnt; }
	int dfn[sz<<1],low[sz<<1],bel[sz<<1],in[sz<<1],T,cc;
	stack<int>s;
#define v edge[i].t
	void tarjan(int x)
	{
		s.push(x),in[x]=1,dfn[x]=low[x]=++cc;
		go(x)
			if (!dfn[v]) tarjan(v),chkmin(low[x],low[v]);
			else if (in[v]) chkmin(low[x],dfn[v]);
		if (dfn[x]==low[x])
		{
			++T; int y;
			do y=s.top(),s.pop(),bel[y]=T,in[y]=0; while (y!=x);
		}
	}
#undef v
	void clr(){rep(i,2,n<<1|1) head[i]=dfn[i]=low[i]=bel[i]=in[i]=0;cc=T=ecnt=0;while (s.size()) s.pop();}
	void work()
	{
		rep(i,1,n) rep(x,0,1) rep(j,i+1,n) rep(y,0,1)
		{
			int flg=0; rep(k,1,n) flg|=(a[i+x*n][k]==a[j+y*n][k]);
			if (flg) make_edge(i<<1|x,(j<<1|y)^1),make_edge(j<<1|y,(i<<1|x)^1);
		}
		rep(i,2,n<<1|1) if (!dfn[i]) tarjan(i);
		rep(i,1,n) if (bel[i<<1|1]<bel[i<<1]) rep(k,1,n) swap(a[i][k],a[i+n][k]);
		clr();
	}
}

int fa[sz];
int del[sz];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void merge(int x,int y){x=getfa(x),y=getfa(y),fa[x]=y,del[y]|=del[x];}

int V[sz],deg[sz];
void topo()
{
	queue<int>q; rep(i,1,n) if (!deg[i]) q.push(i);
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		del[x]=1;
		if (!--deg[V[x]]) q.push(V[x]);
	}
}

void work()
{
	read(n);
	rep(i,1,n*2) rep(j,1,n) read(a[i][j]);
	rep(i,1,n*2) { vector<int>V; rep(j,1,n) V.push_back(a[i][j]); id[V]=i; }
	MATCH::WORK();
	TwoSAT::work();
	rep(i,1,n) fa[i]=i,del[i]=0;
	rep(j,1,n)
	{
		static int id[sz];
		rep(i,1,n) id[a[i][j]]=i;
		rep(i,1,n) deg[i]=0;
		rep(i,1,n) V[i]=id[a[i+n][j]],++deg[V[i]];
		topo();
		rep(i,1,n) if (del[i]) del[getfa(i)]=1;
		rep(i,1,n) if (!del[getfa(i)]) merge(i,V[i]);
	}
	ll ans=1;
	rep(i,1,n) if (fa[i]==i&&!del[i]) ans=ans*2%mod;
	printf("%lld\n",ans);
	rep(i,1,n)
	{
		vector<int>V; rep(j,1,n) V.push_back(a[i][j]);
		printf("%d ",id[V]);
	}
	puts("");
	id.clear(); rep(i,1,n) fa[i]=del[i]=V[i]=deg[i]=0;
}

// clear!!!

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}