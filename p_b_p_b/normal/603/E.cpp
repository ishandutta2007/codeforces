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

int n,m,cnt;
struct hh{int u,v,w,id;const bool operator < (const hh &x) const {return w<x.w;}}edge[sz];
bool del[sz];

namespace LCT
{
	int size[sz],s[sz],S[sz]; //  
	int mx[sz],pos[sz],w[sz]; // id
	int tag[sz];
	int ch[sz][2],fa[sz];
	#define ls ch[x][0]
	#define rs ch[x][1]
	void pushup(int x)
	{
		S[x]=S[ls]+S[rs]+s[x]+size[x];
		mx[x]=w[x],pos[x]=x-n;
		if (chkmax(mx[x],mx[ls])) pos[x]=pos[ls];
		if (chkmax(mx[x],mx[rs])) pos[x]=pos[rs];
	}
	void Rev(int x){tag[x]^=1,swap(ls,rs);}
	void pushdown(int x){if (!tag[x]) return;if (ls) Rev(ls);if (rs) Rev(rs);tag[x]=0;}
	int get(int x){return ch[fa[x]][1]==x;}
	int nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
	void Pushdown(int x){if (nroot(x)) Pushdown(fa[x]);pushdown(x);}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y],k=get(x),w=ch[x][!k];
		if (nroot(y)) ch[z][get(y)]=x;ch[x][!k]=y;ch[y][k]=w;
		if (w) fa[w]=y;fa[y]=x;fa[x]=z;
		pushup(y),pushup(x);
	}
	void splay(int x){Pushdown(x);for (int y;y=fa[x],nroot(x);rotate(x)) if (nroot(y)) rotate(get(x)==get(y)?y:x);}
	void access(int x){for (int y=0;x;x=fa[y=x]) splay(x),size[x]+=S[rs]-S[y],rs=y,pushup(x);}
	int findroot(int x){access(x),splay(x);while (ls) x=ls;return x;}
	void makeroot(int x){access(x),splay(x),Rev(x);}
	void cut(int x,int y){makeroot(x),access(y),splay(y);fa[x]=ch[y][0]=0;pushup(y);}
	void link(int x,int y){makeroot(x),access(y),splay(y),fa[x]=y;size[y]+=S[x],pushup(y);}
	void init(){rep(x,1,n) s[x]=S[x]=1,w[x]=-1e9,pushup(x);}
	int query(int x,int y){assert(findroot(x)==findroot(y));makeroot(x),access(y),splay(y);return pos[y];}
	priority_queue<hh>q;
	void addedge(int id)
	{
		int u=edge[id].u,v=edge[id].v,W=edge[id].w;
		pos[id+n]=id,mx[id+n]=w[id+n]=W;
		if (findroot(u)!=findroot(v)) { if ((S[u]&1)&&(S[v]&1)) cnt-=2; link(u,id+n),link(v,id+n);}
		else
		{
			int e=query(u,v);
			if (edge[e].w<=W) return;
			cut(e+n,edge[e].u),cut(e+n,edge[e].v);del[e]=1;
			link(id+n,u),link(id+n,v);
		}
		q.push(edge[id]);
	}
	void maintain()
	{
		if (cnt) return;
		while (q.size())
		{
			hh e=q.top();
			if (del[e.id]) { q.pop(); continue; }
			int u=e.u,v=e.v;
			makeroot(u),access(v),splay(v);
			if ((S[v]-S[ch[v][0]])&1) return;
			q.pop();cut(u,e.id+n);cut(v,e.id+n);
		}
	}
}
using namespace LCT;

int main()
{
	file();
	read(n,m);cnt=n;init();
	rep(t,1,m)
	{
		int x,y,z;read(x,y,z);
		edge[t]=(hh){x,y,z,t};
		addedge(t);
		maintain();
		if (cnt) puts("-1");
		else printf("%d\n",q.top().w);
	}
	return 0;
}