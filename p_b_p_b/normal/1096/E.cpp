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
    #define mod (ll(998244353))
    #define sz 10101
    typedef long long ll;
    typedef double db;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    template<typename T>inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    template<typename T>inline void read(T& t)
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
        freopen("a.txt","r",stdin);
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

ll fac[sz],_fac[sz];
void init(){fac[0]=_fac[0]=1;rep(i,1,sz-1) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);}
ll C(int n,int m){return n>=m&&m>=0?fac[n]*_fac[m]%mod*_fac[n-m]%mod:0;}

int n,r,s;

ll calc(int sum,int n,int top) // sum points for n people , < top
{
    if (!n) return sum==0;
    ll ret=0;
    rep(i,0,n)
    {
        if (i*top>sum) return ret;
        int cur=sum-i*top;
        ret=(ret+1ll*((i&1)?-1:1)*C(cur+n-1,n-1)*C(n,i)%mod+mod)%mod;
    }
    return ret;
}

int main()
{
    file();
    init();
    read(n,s,r);
    ll tot=C(s-r+n-1,n-1);
    ll ans=0;
    rep(i,r,s)
    {
        rep(j,0,n-1)
        {
            int rest=s-i-i*j;if (rest<0) break;
            ans=(ans+calc(rest,n-j-1,i)*C(n-1,j)%mod*inv(j+1)%mod)%mod;
        }
    }
    cout<<ans*inv(tot)%mod;
    return 0;
}