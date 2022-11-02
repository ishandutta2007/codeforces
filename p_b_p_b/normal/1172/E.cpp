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
    #define sz 404004
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

int n,m;
int col[sz];

struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

int f[sz];
void dfs(int x,int fa)
{
	f[x]=fa;
	go(x) if (edge[i].t!=fa) dfs(edge[i].t,x);
}

#define Sq(x) (1ll*(x)*(x))
int nc[sz];
namespace LCT
{
	int fa[sz],s[sz],size[sz],ch[sz][2],tag[sz],rt[sz];
	#define S(x) (size[x]+s[x])
	// s:S(ls)+S(rs)+1; size: \sum_{v!=ls&&v!=rs} S(v)
	ll sq[sz]; // \sum_{v!=ls&&v!=rs} S(v)^2
	#define ls ch[x][0]
	#define rs ch[x][1]
	int get(int x){return ch[fa[x]][1]==x;}
	int nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
	void pushup(int x){s[x]=S(ls)+S(rs)+1;if (ls) rt[x]=rt[ls]; else rt[x]=x;}
	void Rev(int x){tag[x]^=1;swap(ls,rs);}
	void pushdown(int x){if (!tag[x]) return; if (ls) Rev(ls); if (rs) Rev(rs); tag[x]=0;}
	void Pushdown(int x){if (nroot(x)) Pushdown(fa[x]);pushdown(x);}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y],k=get(x),w=ch[x][!k];
		if (nroot(y)) ch[z][get(y)]=x;ch[x][!k]=y;ch[y][k]=w;
		if (w) fa[w]=y;fa[y]=x;fa[x]=z;
		pushup(y),pushup(x);
	}
	void splay(int x){Pushdown(x);for (int y;y=fa[x],nroot(x);rotate(x)) if (nroot(y)) rotate(get(x)==get(y)?y:x);}
	void access(int x){for (int y=0;x;x=fa[y=x]) splay(x),size[x]+=S(rs)-S(y),sq[x]+=Sq(S(rs))-Sq(S(y)),rs=y,pushup(x);}
	ll calc(int x){splay(x);return sq[x]+Sq(S(rs));}
	ll link(int x) // link(x,f_x)
	{
		nc[x]=0;
		int y=f[x];
		access(x),splay(x);
		access(y),splay(y);
		int root=rt[y];splay(root);
		ll ret=-calc(root)-calc(x);
		fa[x]=y;size[y]+=S(x);sq[y]+=Sq(S(x));splay(y);
		ret+=calc(root);
		return ret;
	}
	ll cut(int x) // cut(x,f_x)
	{
		nc[x]=1;
		int y=f[x];
		access(x),splay(y);
		int root=rt[y];splay(root);
		ll ret=-calc(root);
		splay(y);ch[y][1]=fa[x]=0;pushup(y);
		ret+=calc(x);
		ret+=calc(root);
		return ret;
	}
}
using namespace LCT;

ll ans[sz];
vector<pii>V[sz];

int main()
{
    file();
	read(n,m);
	rep(i,1,n) read(col[i]),V[col[i]].push_back(MP(i,0));
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs(1,0);
	rep(i,1,m) read(x,y),V[col[x]].push_back(MP(x,i)),V[col[x]=y].push_back(MP(x,i));
	f[1]=n+1;nc[n+1]=1;
	rep(i,1,n) pushup(i);
	rep(i,1,n) link(i);
	rep(c,1,n)
	{
		ans[0]+=1ll*n*n;
		for (auto w:V[c])
		{
			int x=w.fir;
			if (nc[x]) ans[w.sec]+=link(x);
			else ans[w.sec]+=cut(x);
		}
		for (auto w:V[c]) if (nc[w.fir]) link(w.fir);
	}
	rep(i,1,m) ans[i]+=ans[i-1];
	rep(i,0,m) printf("%I64d\n",1ll*n*n*n-ans[i]);
	return 0;
}