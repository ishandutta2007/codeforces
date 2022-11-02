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

int n,X,Y;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
int val[sz];
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

namespace BuildTree
{
	int n,m,N;
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
					++N;::make_edge(x,N);::val[N]=0;
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
		N=n;
		rep(i,1,n) ::val[i]=1;
		int x,y;
		rep(i,1,m) read(x,y),make_edge(x,y);
		tarjan(1,0);
		::n=N;
		rep(i,1,n) dfn[i]=low[i]=in[i]=0;
		while (!s.empty()) s.pop();
		rep(i,1,n) head[i]=0;ecnt=0;cnt=0;
	}
}

int son[sz];
int size[sz];
#define v edge[i].t
void dfs(int x,int fa)
{
	size[x]=val[x];
	go(x) if (v!=fa)
	{
		dfs(v,x);
		if (son[v]||v==Y) son[x]=v;
		size[x]+=size[v];
	}
}
#undef v

void work()
{
	read(BuildTree::n,BuildTree::m,X,Y);
	BuildTree::init();
	dfs(X,0);
	int s1=size[Y]-1,s2=size[X]-size[son[X]]-1;
	printf("%lld\n",1ll*s1*s2);
	ecnt=0;rep(i,1,n) head[i]=size[i]=val[i]=son[i]=0;
}

int main()
{
    file();
    int T;read(T);
    while (T--) work();
	return 0;
}