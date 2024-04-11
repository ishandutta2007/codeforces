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
    #define sz 101101
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
    char __sr[1<<21],__z[20];int __C=-1,__Z=0;
    inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
    inline void print(register int x)
    {
    	if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
    	while(__z[++__Z]=x%10+48,x/=10);
    	while(__sr[++__C]=__z[__Z],--__Z);__sr[++__C]='\n';
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

int n,m,K;
char s[sz];
int a[sz],aa[sz];
int cnt[233];
ll T;

ll fac[sz],_fac[sz];
void init(){fac[0]=_fac[0]=1;rep(i,1,sz-1) fac[i]=fac[i-1]*i%mod,_fac[i]=inv(fac[i]);}
ll C(int n,int m){return n>=m&&m>=0?fac[n]*_fac[m]%mod*_fac[n-m]%mod:0;}

int sum[66];
ll dp[sz],cur[sz];
ll ans[66][66];
void Init()
{
    rep(i,1,K) sum[i]=sum[i-1]+cnt[i];
    dp[0]=1;
    int n=::n>>1;
    rep(i,1,K)
        drep(j,n,cnt[i])
            dp[j]=(dp[j]+dp[j-cnt[i]])%mod;
}
ll solve(int x,int y)
{
    int n=::n>>1;
    if ((cnt[x]>n&&x==y)||(cnt[x]+cnt[y]>n&&x!=y)) return 0;
    ll c=fac[n]*fac[n]%mod*inv(T)%mod;
    if (x==y) return c*dp[n]%mod;
    rep(i,0,n) cur[i]=dp[i];
    rep(j,cnt[x],n)
        cur[j]=(cur[j]-cur[j-cnt[x]]+mod)%mod;
    rep(j,cnt[y],n)
        cur[j]=(cur[j]-cur[j-cnt[y]]+mod)%mod;
    return c*cur[n-cnt[x]-cnt[y]]*2%mod;
}

int main()
{
    file();
    cin>>(s+1);n=strlen(s+1);
    rep(i,1,n) a[i]=aa[i]=s[i];
    sort(aa+1,aa+n+1);K=unique(aa+1,aa+n+1)-aa-1;
    rep(i,1,n) a[i]=lower_bound(aa+1,aa+K+1,a[i])-aa;
    rep(i,1,n) ++cnt[a[i]];
    init();Init();
    T=1;rep(i,1,K) T=T*fac[cnt[i]]%mod;
    rep(i,1,K) rep(j,1,K) ans[i][j]=solve(i,j);
    read(m);
    int x,y;
    while (m--) read(x,y),printf("%lld\n",ans[a[x]][a[y]]);
    return 0;
}