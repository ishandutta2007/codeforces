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

int n,m,K;
vector<pii>V[sz];

ll dis[sz];
ll check(int x,int y){return dis[x]+1ll*(x-y)*(x-y);}
ll Y(int i){return dis[i]+1ll*i*i;}
void work()
{
    static ll dp[sz]; dp[1]=1e18;
    static int q[sz]; int l=1,r=1; q[1]=1;
    rep(i,2,n)
    {
        while (l!=r&&check(q[l],i)>=check(q[l+1],i)) ++l;
        dp[i]=check(q[l],i);
        while (l!=r&&(__int128)(i-q[r-1])*(Y(q[r])-Y(q[r-1]))-(__int128)(q[r]-q[r-1])*(Y(i)-Y(q[r-1]))>=0) --r;
        q[++r]=i;
    }
    rep(i,1,n) chkmin(dis[i],dp[i]);
    // rep(i,1,n) printf("%lld ",dis[i]); puts("");
}

void dijkstra()
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
    rep(i,1,n) q.push(MP(dis[i],i));
    while (q.size())
    {
        auto [d,x]=q.top(); q.pop();
        if (d!=dis[x]) continue;
        for (auto [v,w]:V[x]) if (chkmin(dis[v],dis[x]+w)) q.push(MP(dis[v],v));
    }
    // rep(i,1,n) printf("%lld ",dis[i]); puts("");
}

int main()
{
    file();
    read(n,m,K);
    int x,y,z;
    while (m--) read(x,y,z),V[x].push_back(MP(y,z)),V[y].push_back(MP(x,z));
    memset(dis,0x3f,sizeof(dis)); dis[1]=0;
    dijkstra();
    rep(i,1,K) work(),reverse(dis+1,dis+n+1),work(),reverse(dis+1,dis+n+1),dijkstra();
    rep(i,1,n) printf("%lld ",dis[i]);
    return 0;
}