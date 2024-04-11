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
    #define sz 101010
    #define mod 1000000007 
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
    char sr[1<<21],z[20];int C=-1,Z=0;
    inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
    inline void print(register int x)
    {
    	if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
    	while(z[++Z]=x%10+48,x/=10);
    	while(sr[++C]=z[Z],--Z);sr[++C]='\n';
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

int n,Q;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
    edge[++ecnt]=(hh){t,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,head[t]};
    head[t]=ecnt;
}

int dfn[sz],son[sz],size[sz],dep[sz],top[sz],fa[sz],T;
#define v edge[i].t
void dfs1(int x,int fa)
{
    ::fa[x]=fa;dep[x]=dep[fa]+1;
    size[x]=1;
    go(x) if (v!=fa)
    {
        dfs1(v,x);
        size[x]+=size[v];
        if (size[v]>size[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int fa,int tp)
{
    top[x]=tp;dfn[x]=++T;
    if (son[x]) dfs2(son[x],x,tp);
    go(x) if (v!=fa&&v!=son[x]) dfs2(v,x,v);
}
#undef v

int tr[sz];
void add(int x,int y){while (x<=n) tr[x]+=y,x+=(x&(-x));}
int query(int x){int ret=0;while (x) ret+=tr[x],x-=(x&(-x));return ret;}
int query(int x,int y){return query(y)-query(x-1);}

int Query(int x,int y)
{
    int ret=0;
    while (top[x]!=top[y])
    {
        if (dep[top[x]]<dep[top[y]]) swap(x,y);
        ret+=query(dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if (dep[x]>dep[y]) swap(x,y);
    ret+=query(dfn[x],dfn[y]);
    return ret;
}

int a[sz];
int f[sz];
inline bool cmp(const int &x,const int &y){return f[x]<f[y];}
ll dp[333];

int main()
{
    file();
    int x,y,K,m,rt;
    read(n,Q);
    rep(i,1,n-1) read(x,y),make_edge(x,y);
    dfs1(1,0);dfs2(1,0,1);
    while (Q--)
    {
        read(K,m,rt);
        rep(i,1,K) read(a[i]),add(dfn[a[i]],1);
        rep(j,1,m) dp[j]=0;
        dp[0]=1;
        rep(i,1,K) f[a[i]]=Query(rt,a[i])-1;
        sort(a+1,a+K+1,cmp);
        rep(i,1,K)
        {
            x=a[i];
            drep(j,m,f[x]+1) dp[j]=(dp[j-1]+dp[j]*(j-f[x])%mod)%mod;
            rep(j,0,f[x]) dp[j]=0;
        }
        ll ans=0;
        rep(i,1,m) (ans+=dp[i])%=mod;
        printf("%lld\n",ans);
        rep(i,1,K) add(dfn[a[i]],-1);
    }
    return 0;
}