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
    #define sz 303030
    typedef long long ll;
    const ll mod=1e9+9;
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

int n,m;
int a[sz];

ll f[sz],ff[sz],F[sz];
void init()
{
    F[1]=f[1]=1;
    rep(i,2,sz-1) F[i]=(F[i-1]+(f[i]=(f[i-1]+f[i-2])%mod))%mod;
    rep(i,1,sz-1) ff[i]=(i&1)?f[i]:mod-f[i];
}

ll tg1[sz<<2],tg2[sz<<2],sum[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r
#define S int k,int l,int r
#define I inline
I void Add1(S,ll s){(tg1[k]+=s)%=mod;(sum[k]+=s*(F[r]-F[l-1]+mod)%mod)%=mod;}
I void Add2(S,ll s){(tg2[k]+=s)%=mod;(sum[k]+=s*(F[r+1]-F[l]+mod)%mod)%=mod;}
I void pushdown(S)
{
    if (!tg1[k]&&!tg2[k]) return;
    int mid=(l+r)>>1;
    ll &t1=tg1[k],&t2=tg2[k];
    Add1(lson,t1);Add1(rson,t1);
    Add2(lson,t2);Add2(rson,t2);
    t1=t2=0;
}
void pushup(int k){sum[k]=(sum[ls]+sum[rs])%mod;}
void add(S,int x,int y,ll s1,ll s2)
{
    if (x<=l&&r<=y) return Add1(k,l,r,s1),Add2(k,l,r,s2);
    pushdown(k,l,r);
    int mid=(l+r)>>1;
    if (x<=mid) add(lson,x,y,s1,s2);
    if (y>mid) add(rson,x,y,s1,s2);
    pushup(k);
}
ll query(S,int x,int y)
{
    if (x<=l&&r<=y) return sum[k];
    pushdown(k,l,r);
    int mid=(l+r)>>1;
    ll ret=0;
    if (x<=mid) ret+=query(lson,x,y);
    if (y>mid) ret+=query(rson,x,y);
    return ret%mod;
}
void build(S)
{
    if (l==r) return (void)(sum[k]=a[l]%mod);
    int mid=(l+r)>>1;
    build(lson);build(rson);
    pushup(k);
}

int main()
{
    file();
    int x,y,z;
    read(n,m);
    rep(i,1,n) read(a[i]);
    init();
    build(1,1,n);
    while (m--)
    {
        read(z,x,y);
        if (z==1) add(1,1,n,x,y,ff[x],ff[x-1]);
        else printf("%lld\n",query(1,1,n,x,y));
    }
    return 0;
}