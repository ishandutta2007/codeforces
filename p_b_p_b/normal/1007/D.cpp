//  
#include<bits/stdc++.h>
//clock_t t=clock();
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
	#define sz 452020
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
//	inline void chktime()
//	{
//		#ifdef NTFOrz
//		cout<<(clock()-t)/1000.0<<'\n';
//		#endif
//	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;
#define v edge[i].t

namespace Two_Sat
{
	#define S sz*20
	struct hh{int t,nxt;}edge[S<<1];
	int head[S],ecnt;
	void make_edge(int f,int t)
	{
		if (!f||!t) return;
		edge[++ecnt]=(hh){t,head[f]};
		head[f]=ecnt;
	}
	stack<int>s;
	int in[S];
	int dfn[S],low[S],bel[S],cc,T;
	void tarjan(int x)
	{
		dfn[x]=low[x]=++cc;in[x]=1;s.push(x);
		go(x) 
		{
			if (!dfn[v]) tarjan(v),chkmin(low[x],low[v]);
			else if (in[v]) chkmin(low[x],dfn[v]);
		}
		if (dfn[x]==low[x])
		{
			++T;int y;
			do
			{
				y=s.top();s.pop();in[y]=0;
				bel[y]=T;
			}while (y!=x);
		}
	}
}

int tp;

namespace WorkChain
{
	int n,m;
	struct hh{int id,l,r;const bool operator < (const hh &a) const {return l==a.l?r<a.r:l<a.l;}}a[sz];
	int tr1[sz],tr2[sz];
	void work(int x,int id){while (x) Two_Sat::make_edge(id,tr1[x]),Two_Sat::make_edge(tr2[x],id^1),x-=(x&-x);}
	void add(int x,int id){while (x<=n) ++tp,Two_Sat::make_edge(tp,tr1[x]),Two_Sat::make_edge(tp,id^1),tr1[x]=tp,++tp,Two_Sat::make_edge(tr2[x],tp),Two_Sat::make_edge(id,tp),tr2[x]=tp,x+=(x&-x);}
	int pre[sz],suf1[sz],suf2[sz];
	void work()
	{
		sort(a+1,a+m+1);
		rep(i,1,n) tr1[i]=tr2[i]=0; rep(i,1,m+1) suf1[i]=suf2[i]=0;
		int K=0;
		drep(i,m,1) if (a[i].l==1) { K=i; break; } else 
		{
			work(a[i].r-1,a[i].id);
			add(a[i].l,a[i].id);
		} 
		rep(i,1,K) suf1[i]=++tp,Two_Sat::make_edge(tp,a[i].id^1),suf2[i]=++tp,Two_Sat::make_edge(a[i].id,tp);
		rep(i,1,K) Two_Sat::make_edge(suf1[i],suf1[i+1]),Two_Sat::make_edge(suf2[i+1],suf2[i]);
		rep(i,1,K) Two_Sat::make_edge(a[i].id,suf1[i+1]),Two_Sat::make_edge(suf2[i+1],a[i].id^1);
		rep(i,K+1,m) { int p=upper_bound(a+1,a+K+1,(hh){0,1,a[i].l})-a; Two_Sat::make_edge(a[i].id,suf1[p]),Two_Sat::make_edge(suf2[p],a[i].id^1); } 
	}
}

int n,m;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

int size[sz],son[sz],top[sz],dep[sz],fa[sz];
void dfs1(int x,int f)
{
	fa[x]=f,dep[x]=dep[f]+1,size[x]=1;
	go(x) if (v!=f) 
	{
		dfs1(v,x);
		size[x]+=size[v];
		if (size[v]>size[son[x]]) son[x]=v;
	}
}
void dfs2(int x,int fa,int tp)
{
	top[x]=tp;
	if (son[x]) dfs2(son[x],x,tp);
	go(x) if (v!=fa&&v!=son[x]) dfs2(v,x,v);
}
int lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
typedef WorkChain::hh hhh;
vector<hhh>V1[sz],V2[sz];
void add(int x,int y,int id)
{
	while (top[x]!=top[y])
	{
		if (x!=top[x]) V1[top[x]].push_back((hhh){id,1,dep[x]-dep[top[x]]+1});
		V2[top[x]].push_back((hhh){id,1,2});
		x=fa[top[x]];
	}
	if (x!=y) V1[top[x]].push_back((hhh){id,dep[y]-dep[top[x]]+1,dep[x]-dep[top[x]]+1});
}

int main()
{
	file();
	read(n);
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs1(1,0),dfs2(1,0,1);
	read(m);tp=m<<1|1;
	rep(i,1,m)
	{
		int x1,y1,x2,y2;
		read(x1,y1,x2,y2);
		int l1=lca(x1,y1),l2=lca(x2,y2);
		add(x1,l1,i<<1),add(y1,l1,i<<1);
		add(x2,l2,i<<1|1),add(y2,l2,i<<1|1);
	}
	rep(i,1,n) if (!son[i])
	{
		int x=top[i];
		WorkChain::n=dep[i]-dep[x]+1,WorkChain::m=V1[x].size();
		rep(k,0,(int)V1[x].size()-1) WorkChain::a[k+1]=V1[x][k];
		WorkChain::work();
		WorkChain::n=2,WorkChain::m=V2[x].size();
		rep(k,0,(int)V2[x].size()-1) WorkChain::a[k+1]=V2[x][k];
		WorkChain::work();
	}
	rep(i,2,tp) if (!Two_Sat::dfn[i]) Two_Sat::tarjan(i);
	rep(i,1,m) if (Two_Sat::bel[i<<1]==Two_Sat::bel[i<<1|1]) return puts("NO"),0;
	puts("YES");
	rep(i,1,m) puts(Two_Sat::bel[i<<1]<Two_Sat::bel[i<<1|1]?"1":"2");
	return 0;
}