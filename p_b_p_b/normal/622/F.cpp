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
    #define sz 1010101
    typedef long long ll;
    const ll mod=1e9+7;
    template<typename T>
    inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.')
        {
            ch=getchar();
            while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
        }
        t=(f?-t:t);
    }
    template<typename T,typename... Args>
    inline void read(T& t,Args&... args){read(t); read(args...);}
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.txt","r",stdin);
        #endif
    }
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,k;

inline ll ksm(ll x,int y)
{
    ll ret=1;
    for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;
    return ret;
}

ll f[sz];
ll fac[sz],_fac[sz],pre[sz],suf[sz];
ll solve()
{
    fac[0]=_fac[0]=1;rep(i,1,sz-1) _fac[i]=ksm(fac[i]=fac[i-1]*i%mod,mod-2);
    pre[0]=1;rep(i,1,k+2) pre[i]=pre[i-1]*(n-i)%mod;
    suf[k+3]=1;drep(i,k+2,1) suf[i]=suf[i+1]*(n-i)%mod;
    ll ans=0;
    rep(i,1,k+2) ans=(ans+f[i]*pre[i-1]%mod*suf[i+1]%mod*_fac[i-1]%mod*_fac[k+2-i]%mod*(((k+2-i)&1)?-1:1)+mod)%mod;
    return ans;
}

int main()
{
    file();
    read(n,k);
    if (k==0) return printf("%d",n),0;
    rep(i,1,k+2) f[i]=(f[i-1]+ksm(i,k))%mod;
    if (n<=k+2) return printf("%lld",f[n]),0;
    printf("%lld",solve());
    return 0;
}