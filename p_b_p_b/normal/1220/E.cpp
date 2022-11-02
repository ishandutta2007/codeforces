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

int n,s;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
set<pii>ss;
void make_edge(int f,int t)
{
	if (f>t) swap(f,t);
	if (ss.find(MP(f,t))!=ss.end()) return;
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
	ss.insert(MP(f,t));
}
ll w[sz];
int type[sz];

namespace Build
{
	int n,m,s;
	struct hh{int t,nxt;}edge[sz<<1];
	int head[sz],ecnt;
	void make_edge(int f,int t)
	{
		edge[++ecnt]=(hh){t,head[f]};
		head[f]=ecnt;
		edge[++ecnt]=(hh){f,head[t]};
		head[t]=ecnt;
	}
	ll w[sz];
	#define v edge[i].t
	int dfn[sz],low[sz],in[sz],T,bel[sz],cnt,size[sz];
	stack<int>ss;
	void dfs(int x,int fa)
	{
		dfn[x]=low[x]=++T;in[x]=1;ss.push(x);
		go(x) if (v!=fa)
		{
			if (!dfn[v])
			{
				dfs(v,x);
				chkmin(low[x],low[v]);
//				if (low[v]>dfn[x])
//				{
//					++cnt;int y;
//					do
//					{
//						y=ss.top();
//						bel[y]=cnt;::w[cnt]+=w[y];
//						ss.pop();in[y]=0;
//					}while (y!=v);
//				}
			}
			else if (in[v]) chkmin(low[x],dfn[v]);
		}
		if (low[x]>dfn[fa])
		{
			++cnt;int y;
					do
					{
						y=ss.top();
						bel[y]=cnt;::w[cnt]+=w[y];++size[cnt];
						ss.pop();in[y]=0;
					}while (y!=x);
		}
	}
	void work()
	{
		read(n,m);
		rep(i,1,n) read(w[i]);
		int x,y;
		rep(i,1,m) read(x,y),make_edge(x,y);
		read(s);
		dfs(s,0);
		rep(x,1,n) if (dfn[x]) go(x) if (bel[v]!=bel[x]) ::make_edge(bel[x],bel[v]);
		rep(i,1,cnt) if (size[i]>1) ::type[i]=1;
		::n=cnt;::s=bel[s];
	}
	#undef v
}

ll dp1[sz],dp2[sz];
#define v edge[i].t
void dfs2(int x,int fa){go(x) if (v!=fa) dfs2(v,x),type[x]|=type[v];}
void dfs(int x,int fa)
{
	if (!type[x]) dp2[x]=-1e18;
	go(x) if (v!=fa) dfs(v,x);
	go(x) if (v!=fa&&type[v]) dp2[x]+=dp2[v];
	go(x) if (v!=fa)
	{
		if (!type[v]) chkmax(dp1[x],max(dp2[x],0ll)+dp1[v]);
		else chkmax(dp1[x],max(dp2[x]-dp2[v],0ll)+dp1[v]);
	}
	dp2[x]+=w[x],dp1[x]+=w[x];
	chkmax(dp1[x],dp2[x]);
}
#undef v

int main()
{
	file();
	Build::work();
	dfs2(s,0);dfs(s,0);
	cout<<dp1[s];
	return 0;
}