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
    #define sz 201001
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
    char __sr[1<<21],__z[20];int __C=-1,__Z=0;
    inline void __Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
    inline void print(register int x)
    {
    	if (__C>1<<20) __Ot(); if (x<0) __sr[++__C]='-',x=-x;
    	while (__z[++__Z]=x%10+48,x/=10);
    	while (__sr[++__C]=__z[__Z],--__Z);__sr[++__C]='\n';
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

int n,m,Q,N;
int val[sz];
multiset<int>s[sz];
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

namespace BuildTree
{
	struct hh{int t,nxt;}edge[sz<<1];
	int head[sz],ecnt;
	void make_edge(int f,int t)
	{
		edge[++ecnt]=(hh){t,head[f]};
		head[f]=ecnt;
		edge[++ecnt]=(hh){f,head[t]};
		head[t]=ecnt;
	}
	int dfn[sz],low[sz],cnt;
	stack<int>s;
	bool in[sz];
	void tarjan(int x,int fa)
	{
		dfn[x]=low[x]=++cnt;in[x]=1;s.push(x);
		#define v edge[i].t
		go(x) if (v!=fa)
		{
			if (!dfn[v]) 
			{
				tarjan(v,x),chkmin(low[x],low[v]);
				if (low[v]>=dfn[x])
				{
					++N;::make_edge(x,N);
					int y;
					do{y=s.top();s.pop();in[y]=0;::make_edge(y,N);}while (y!=v);
				}
			}
			else chkmin(low[x],dfn[v]);
		}
		#undef v
	}
	void init()
	{
		read(n,m,Q);N=n;
		rep(i,1,n) read(val[i]);
		int x,y;
		rep(i,1,m) read(x,y),make_edge(x,y);
		tarjan(1,0);
	}
}

int dfn[sz],pre[sz],top[sz],fa[sz],dep[sz],size[sz],son[sz],cnt;
#define v edge[i].t
void dfs1(int x,int fa)
{
	dep[x]=dep[::fa[x]=fa]+1;size[x]=1;
	if (x<=n&&x!=1) s[fa].insert(val[x]);
	go(x) if (v!=fa)
	{
		dfs1(v,x);
		size[x]+=size[v];
		if (size[v]>size[son[x]]) son[x]=v;
	}
	if (x>n) val[x]=*s[x].begin();
}
void dfs2(int x,int fa,int tp)
{
	top[pre[dfn[x]=++cnt]=x]=tp;
	if (son[x]) dfs2(son[x],x,tp);
	go(x) if (v!=fa&&v!=son[x]) dfs2(v,x,v);
}
#undef v

int mn[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void pushup(int k){mn[k]=min(mn[ls],mn[rs]);}
void modify(int k,int l,int r,int x,int y)
{
	if (l==r) return void(mn[k]=y);
	int mid=(l+r)>>1;
	if (x<=mid) modify(lson,x,y);
	else modify(rson,x,y);
	pushup(k);
}
int query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return mn[k];
	int mid=(l+r)>>1,ret=1e9;
	if (x<=mid) chkmin(ret,query(lson,x,y));
	if (y>mid) chkmin(ret,query(rson,x,y));
	return ret;
}
#undef ls
#undef rs
#undef lson
#undef rson

void modify(int x,int w)
{
	if (x==1) return void(modify(1,1,N,dfn[x],val[x]=w));
	s[fa[x]].erase(s[fa[x]].find(val[x]));
	s[fa[x]].insert(w);
	val[x]=w;
	modify(1,1,N,dfn[x],w);
	modify(1,1,N,dfn[fa[x]],*s[fa[x]].begin());
}
int query(int x,int y)
{
	int ret=1e9;
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		chkmin(ret,query(1,1,N,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if (dep[x]>dep[y]) swap(x,y);
	chkmin(ret,query(1,1,N,dfn[x],dfn[y]));
	if (x!=1&&x>n) chkmin(ret,val[fa[x]]);
	return ret;
}

int main()
{
	file();
	BuildTree::init();
	dfs1(1,0);dfs2(1,0,1);
	rep(i,1,N) modify(1,1,N,dfn[i],val[i]);
	char c;int x,y;
	while (Q--)
	{
		c=getchar();while (c!='C'&&c!='A') c=getchar();
		read(x,y);
		if (c=='C') modify(x,y);
		else printf("%d\n",query(x,y));
	}
	return 0;
}