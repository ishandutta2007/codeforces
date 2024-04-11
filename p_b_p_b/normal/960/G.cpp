#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define mod 998244353
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 500500
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
    inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

#define int ll

ll fac[sz],_fac[sz];

ll ksm(ll x,int y)
{
    ll ret;
    for (ret=1;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;
    return ret;
}
ll inv(ll x){return ksm(x,mod-2);}

void init()
{
    fac[0]=_fac[0]=1;
    rep(i,1,sz-5) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);
}

const ll g=3;
int r[sz],limit;
void NTT(ll *a,int type)
{
    rep(i,0,limit-1) if (r[i]<i) swap(a[i],a[r[i]]);
    for (int mid=1;mid<limit;mid<<=1)
    {
        ll Wn=ksm(g,(mod-1)/mid>>1);if (type==-1) Wn=inv(Wn);
        for (int len=mid<<1,j=0;j<limit;j+=len)
        {
            ll w=1;
            for (int k=0;k<mid;k++,w=1ll*w*Wn%mod)
            {
                ll x=a[j+k],y=1ll*w*a[mid+j+k];
                a[j+k]=(x+y+mod)%mod;a[j+k+mid]=(x-y+mod)%mod;
            }
        }
    }
    if (type==-1)
    {
        ll t=inv(limit);
        rep(i,0,limit-1) a[i]=(1ll*a[i]*t%mod+mod)%mod;
    }
}
void NTT(ll *a,ll *b,int len)//ans=a
{
    limit=1;int l=-1;
    while (limit<=len*2) limit<<=1,++l;
    rep(i,1,limit-1) r[i]=(r[i>>1]>>1)|((i&1)<<l);
    rep(i,len,limit) a[i]=b[i]=0;
    NTT(a,1);NTT(b,1);
    rep(i,0,limit) a[i]=1ll*a[i]*b[i]%mod;
    NTT(a,-1);
}

ll X[sz],a[sz],b[sz];
void work(int len)
{
    if (len==1) return (void)(X[1]=1);
    if (len&1)
    {
        work(len-1);
        X[len]=0;
        drep(i,len,1) (X[i]=X[i-1]+1ll*X[i]*(len-1)%mod)%=mod;
        return;
    }
    int n=len>>1;
    work(n);
    for (ll i=n,w=1;i>=0;i--,w=1ll*w*n%mod) a[i]=1ll*w*_fac[n-i]%mod;
    rep(i,0,n) b[i]=fac[i]*X[i]%mod;
    rep(i,n+1,n<<2) a[i]=b[i]=0;
    NTT(a,b,n+1);
    rep(i,0,n) a[i]=1ll*a[i+n]*_fac[i]%mod;
    rep(i,n+1,limit) a[i]=0;
    NTT(X,a,n+1);
}

int n,A,B;

signed main()
{
    file();
    init();
    read(n,A,B);
    if (n==1) return puts(A==B&&A==1?"1":"0"),0;
    work(n-1);
    cout<<1ll*X[A+B-2]*fac[A+B-2]%mod*_fac[A-1]%mod*_fac[B-1]%mod;
}