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
    #define sz 404040
    #define mod 998244353
    typedef long long ll;
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

ll ksm(ll x,int y)
{
    ll ret=1;
    for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;
    return ret;
}
ll inv(ll x){return ksm(x,mod-2);}

int limit,r[sz];
ll G[sz],_G[sz];
void init(){for (int mid=1;mid<sz;mid<<=1) _G[mid]=inv(G[mid]=ksm(3,(mod-1)/mid>>1));}
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
        ll Wn=(type==1)?G[mid]:_G[mid];
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
ll tmp1[sz],tmp2[sz],tmp3[sz],tmp4[sz];
void PolyInv(ll *a,ll *f,int n) // f=a^{-1}
{
    if (n==1) return (void)(f[0]=inv(a[0]));
    int mid=(n+1)>>1;
    PolyInv(a,f,mid);
    NTT_init(n);
    rep(i,0,mid-1) tmp1[i]=f[i];rep(i,mid,limit-1) tmp1[i]=0;
    rep(i,0,n-1) tmp2[i]=a[i];rep(i,n,limit-1) tmp2[i]=0;
    NTT(tmp1,1);NTT(tmp2,1);
    rep(i,0,limit-1) tmp1[i]=tmp1[i]*(mod+2-tmp1[i]*tmp2[i]%mod)%mod;
    NTT(tmp1,-1);
    rep(i,0,n-1) f[i]=tmp1[i];
    rep(i,0,limit-1) tmp1[i]=tmp2[i]=0;
}
void PolySqrt(ll *a,ll *f,int n)
{
    if (n==1) return (void)(f[0]=sqrt(a[0])+0.5);
    int mid=(n+1)>>1;
    PolySqrt(a,f,mid);
    PolyInv(f,tmp3,n);
    rep(i,0,n-1) tmp1[i]=a[i],tmp2[i]=f[i];
    NTT_init(n);
    NTT(tmp1,1);NTT(tmp2,1);NTT(tmp3,1);
    ll inv2=inv(2);
    rep(i,0,limit-1) tmp1[i]=inv2*(tmp1[i]*tmp3[i]%mod+tmp2[i])%mod;
    NTT(tmp1,-1);
    rep(i,0,n-1) f[i]=tmp1[i];
    rep(i,0,limit-1) tmp1[i]=tmp2[i]=tmp3[i]=0;
}

int n,m;
ll a[sz];
ll tt1[sz],tt2[sz];
ll ans[sz];

int main()
{
    file();
    init();
    read(n,m);
    int x;
    rep(i,1,n) read(x),a[x]=1;
    tt1[0]=1;rep(i,1,m) tt1[i]=mod-4*a[i]%mod;
    PolySqrt(tt1,tt2,m+1);
    ++tt2[0];
    PolyInv(tt2,ans,m+1);
    rep(i,1,m) ans[i]=ans[i]*2%mod;
    rep(i,1,m) printf("%lld\n",ans[i]);
    return 0;
}