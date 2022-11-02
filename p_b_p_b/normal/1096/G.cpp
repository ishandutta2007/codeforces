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
    #define sz 8010100
    #define mod 998244353ll 
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

int limit,r[sz];
void NTT_init(int n)
{
    limit=1;int l=-1;
    while (limit<=n+n) limit<<=1,++l;
    rep(i,0,limit-1) r[i]=(r[i>>1]>>1)|((i&1)<<l);
}
void NTT(ll *a,int type)
{
    rep(i,0,limit-1) if (i<r[i]) swap(a[i],a[r[i]]);
    rep(i,0,limit-1) a[i]%=mod;
    for (int mid=1;mid<limit;mid<<=1)
    {
        ll Wn=ksm(3,(mod-1)/mid>>1);if (type==-1) Wn=inv(Wn);
        for (int j=0,len=mid<<1;j<limit;j+=len)
        {
            ll w=1;
            for (int k=0;k<mid;k++,w=w*Wn%mod)
            {
                ll x=a[j+k],y=a[j+k+mid]*w;
                a[j+k]=(x+y)%mod;a[j+k+mid]=(1ll*mod*mod-y+x)%mod;
            }
        }
    }
    if (type==1) return;
    ll I=inv(limit);
    rep(i,0,limit-1) a[i]=a[i]*I%mod;
}

int n,K;
ll a[sz];

int main()
{
    file();
    read(n,K);
    int x;
    rep(i,1,K) read(x),a[x]=1;
    NTT_init(n*10);
    NTT(a,1);
    rep(i,0,limit) a[i]=ksm(a[i],n/2);
    NTT(a,-1);
    ll ans=0;
    rep(i,0,n*10) (ans+=a[i]*a[i]%mod)%=mod;
    cout<<ans;
    return 0;
}