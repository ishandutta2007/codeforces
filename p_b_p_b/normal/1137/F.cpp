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
    #define sz 200202
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

int n,Q;
int MX;

struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

int sum[sz<<1];
void add(int x,int w){if (!x) return;while (x<=n+Q) sum[x]+=w,x+=(x&(-x));}
int Query(int x){int ret=0;while (x) ret+=sum[x],x-=(x&(-x));return ret;}

namespace LCT
{
	int fa[sz],val[sz],W[sz],ch[sz][2],size[sz];
	// val: W: 
	int tag[sz];
	#define ls ch[x][0]
	#define rs ch[x][1]
	void Rev(int x){tag[x]^=1;swap(ls,rs);}
	void pushdown(int x){if (!tag[x]) return;if (ls) Rev(ls);if (rs) Rev(rs);tag[x]=0;}
	void pushup(int x){size[x]=size[ls]+size[rs]+1;val[x]=(rs?val[rs]:W[x]);}
	int nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
	int get(int x){return ch[fa[x]][1]==x;}
	void Pushdown(int x){if (nroot(x)) Pushdown(fa[x]);pushdown(x);}
	void rotate(int x)
	{
		int y=fa[x],k=get(x),w=ch[x][!k],z=fa[y];
		if (nroot(y)) ch[z][get(y)]=x;ch[x][!k]=y,ch[y][k]=w;
		if (w) fa[w]=y;fa[y]=x;fa[x]=z;
		pushup(y),pushup(x);
	}
	void splay(int x){Pushdown(x);for (int y;y=fa[x],nroot(x);rotate(x)) if (nroot(y)) rotate(get(x)==get(y)?y:x);}
	void access(int x,int w)
	{
		int y=0;
		for (;x;x=fa[y=x])
		{
			splay(x);int s=size[ls]+1,va=val[x];
			add(va,-s);add(w,s);splay(x);
			rs=y,pushup(x);
		}
	}
	void change(int x)
	{
		splay(x);
		if (val[x]==MX){ add(MX,-1); add(MX+1,1); val[x]=W[x]=MX+1; ++MX; return; }
		int va=val[x];
		int y=fa[x];
		if (ls) { y=ls; while (pushdown(y),ch[y][1]) y=ch[y][1]; }
		access(y,MX);splay(y);Rev(y);fa[y]=x;
		while (pushdown(y),ch[y][1]) y=ch[y][1];val[y]=W[y]=MX;splay(y);
		fa[x]=0;pushdown(x);
		ls=rs=0;val[x]=W[x]=MX+1;add(MX+1,1);add(va,-1);
		pushup(x);++MX;
	}
	int query(int x)
	{
		splay(x);
		int va=val[x],rnk=Query(va-1);
		rnk+=size[rs]+1;
		return rnk;
	}
}
using namespace LCT;

void dfs(int x,int f){go(x) if (edge[i].t!=f) dfs(edge[i].t,x);fa[x]=f;val[x]=0;size[x]=1;}

int main() // not finished!!!
{
    file();
	read(n,Q);
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs(1,0);MX=0;
	rep(i,1,n) 
		change(i);
	rep(i,1,Q)
	{
		char s[20];cin>>(s+1);
		if (s[1]=='u') read(x),change(x);
		else if (s[1]=='w') read(x),printf("%d\n",query(x));
		else read(x,y),printf("%d\n",query(x)<query(y)?x:y);
	}
	return 0;
}