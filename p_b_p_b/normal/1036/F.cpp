#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pli pair<ll,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    #define sz 101001
    typedef long long ll;
    typedef long double db;
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
}
using namespace my_std;

int mu[sz],pri[sz],cnt;
bool npri[sz]; 
void init()
{
    #define X i*pri[j]
    mu[1]=1;
    rep(i,2,sz-1)
    {
        if (!npri[i]) pri[++cnt]=i,mu[i]=-1;
        for (int j=1;j<=cnt&&X<sz;j++)
        {
            npri[X]=1;
            if (i%pri[j]==0) break;
            mu[X]=-mu[i];
        }
    }
    #undef X
}

pli q[sz];
ll sqr[sz];
ll ans[sz];
db ksm(db x,int y){db ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
ll calc(ll n)
{
    sqr[1]=n;
    rep(i,3,60) while (ksm(sqr[i],i)>n) --sqr[i];
    ll ret=0;
    rep(i,1,60) ret+=(sqr[i]-1)*mu[i];
    return ret;
}

int main()
{
    file();
    init();
    int T;read(T);
    ll n;
    rep(i,1,T) read(n),q[i]=MP(-n,i);
    sort(q+1,q+T+1);
    sqr[3]=1e6+10,sqr[4]=32000,sqr[5]=4000;
    rep(i,1,61) sqr[i]=pow(1e18,1.0/i)+10;
    rep(i,1,T)
    {
        n=-q[i].fir;
        ll &x=sqr[2];x=sqrt(n)+10;
        while ((db)x*x>n) --x;
        ans[q[i].sec]=calc(n);
    }
    rep(i,1,T) printf("%lld\n",ans[i]);
    return 0;
}