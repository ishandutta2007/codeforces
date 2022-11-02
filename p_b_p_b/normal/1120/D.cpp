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

int n;
ll c[sz];

namespace getans
{
    int fa[sz];
    void init(){rep(i,1,n) fa[i]=i;}
    int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
    bool ok[sz];
    struct hh{int f,t;ll w;int id;}edge[sz];
    inline bool operator < (const hh &x,const hh &y){return x.w<y.w;}
    ll ans;
    void work(int L,int R)
    {
        rep(j,L,R)
        {
            int x=getfa(edge[j].f),y=getfa(edge[j].t);
            if (x==y) continue;
            ok[edge[j].id]=1;
        }
        rep(j,L,R)
        {
            int x=getfa(edge[j].f),y=getfa(edge[j].t);
            if (x==y) continue;
            ans+=edge[j].w;
            fa[x]=y;
        }
    }
    int MAIN()
    {
        init();
        sort(edge+1,edge+n+1);
        int lst=1;
        rep(i,1,n)
        {
            if (edge[i].w==edge[lst].w) continue;
            work(lst,i-1);
            lst=i;
        }
        work(lst,n);
        cout<<ans<<' ';
        int cnt=0;
        rep(i,1,n) if (ok[i]) ++cnt;
        printf("%d\n",cnt);
        rep(i,1,n) if (ok[i]) printf("%d ",i);
        return 0;
    }
}

namespace build
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
    int dfn[sz],low[sz],pre[sz],cnt;
    int a[sz],cc;
    #define v edge[i].t
    void dfs(int x,int fa)
    {
        pre[dfn[x]=++cnt]=x;
        bool flg=0;
        go(x) if (v!=fa) flg=1,dfs(v,x);
        low[x]=cnt;
        if (!flg) a[++cc]=dfn[x];
    }
    #undef v
    void init()
    {
        int x,y;
        rep(i,1,n-1) read(x,y),make_edge(x,y);
        dfs(1,0);
        rep(i,1,n) 
        {
            int L=lower_bound(a+1,a+cc+1,dfn[i])-a;
            int R=upper_bound(a+1,a+cc+1,low[i])-a;
            getans::edge[i]=(getans::hh){L,R,c[i],i};
        }
    }
}

int main()
{
    file();
    read(n);
    rep(i,1,n) read(c[i]);
    build::init();
    return getans::MAIN();
}