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
    #define sz 233333
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
}
using namespace my_std;

namespace FLOW
{
int S,T;
struct hh{int t,w,nxt;}edge[sz<<3];
int head[sz<<2],ecnt=1;
void make_edge(int f,int t,int w) 
{
	edge[++ecnt]=(hh){t,w,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,0,head[t]};
	head[t]=ecnt; 
}

int dep[sz<<2],cur[sz<<2];
#define v edge[i].t
int dfs(int x,int f)
{
	if (x==T) return f;
	int ret=0;
	for (int &i=cur[x];i;i=edge[i].nxt) if (dep[v]==dep[x]+1&&edge[i].w)
	{
		int k=dfs(v,min(f,edge[i].w));
		edge[i].w-=k;edge[i^1].w+=k;
		ret+=k;f-=k;
		if (!f) break;
	}
	return ret;
}
bool bfs()
{
	rep(i,1,T) dep[i]=0,cur[i]=head[i];
	dep[S]=1;queue<int>q;q.push(S);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		go(x) if (edge[i].w&&!dep[v]) dep[v]=dep[x]+1,q.push(v);
	}
	return dep[T];
}
int dinic(){int ret=0;while (bfs()) ret+=dfs(S,1e9);return ret;}
#undef v
}

int n,m;
int a[sz];
int u[sz],v[sz],U[sz],V[sz];
int s[sz];

int main()
{
    file();
    read(n,m);
    rep(i,1,n) read(s[i]);
    rep(i,1,n) read(a[i]);
    rep(i,1,m) read(u[i],v[i]),a[u[i]]--,a[v[i]]--;
    rep(i,1,n) if (s[i]&&(a[i]%2==1||a[i]%2==-1||a[i]>0)) return puts("NO"),0; else a[i]=-a[i];
    ll tot=0;
    rep(i,1,n) if (s[i]) tot+=a[i]/2;
    if (tot>m) return puts("NO"),0;
    FLOW::S=n+1+m+1,FLOW::T=FLOW::S+1;
    rep(i,1,n) if (s[i]==1) FLOW::make_edge(FLOW::S,i,a[i]/2);
    FLOW::make_edge(FLOW::S,n+1,m-tot);
    rep(i,1,m) U[i]=u[i],V[i]=v[i];
    rep(i,1,m) { if (!s[u[i]]) u[i]=n+1; if (!s[v[i]]) v[i]=n+1; FLOW::make_edge(u[i],i+n+1,1); FLOW::make_edge(v[i],i+n+1,1); }
    rep(i,1,m) FLOW::make_edge(i+n+1,FLOW::T,1);
    int c=FLOW::dinic();
    if (c!=m) return puts("NO"),0;
    puts("YES");
    rep(i,1,m) for (int j=FLOW::head[i+n+1];j;j=FLOW::edge[j].nxt)
    {
        int t=FLOW::edge[j].t;
        if (t!=FLOW::T&&!FLOW::edge[j^1].w)
        {
            if (t!=u[i]) swap(u[i],v[i]),swap(U[i],V[i]);
            printf("%d %d\n",U[i],V[i]),a[u[i]]=-2;
            break;
        }
    }
    // rep(i,1,n) if (s[i]) assert(!a[i]);
    return 0;
}