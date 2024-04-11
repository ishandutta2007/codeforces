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
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n;
ll mod;
int p[25],cnt;
int a[sz];

ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
void exgcd(int a,int b,ll &x,ll &y)
{
    if (!b) return (void)(x=1,y=0);
    exgcd(b,a%b,y,x);
    (y-=(a/b*x)%mod-mod)%=mod;
}
ll inv(ll a){ll x,y;exgcd(a,mod,x,y);x=(x%mod+mod)%mod;return x;}

ll c[sz<<2][25];
ll sum[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void pushup(int k){sum[k]=(sum[ls]+sum[rs])%mod;}
void pushdown(int k)
{
    ll S=1;ll *t=c[k],*Ls=c[ls],*Rs=c[rs];
    rep(i,1,cnt) 
        S=S*ksm(p[i],t[i])%mod,
        Ls[i]+=t[i],Rs[i]+=t[i],
        t[i]=0;
    ll x=t[0];
    (Ls[0]*=x)%=mod;(Rs[0]*=x)%=mod;
    (S*=x)%=mod;
    t[0]=1;
    sum[ls]=sum[ls]*S%mod;sum[rs]=sum[rs]*S%mod;
}
void build(int k,int l,int r)
{
    c[k][0]=1;
    if (l==r)
    {
        sum[k]=a[l]%mod;
        rep(i,1,cnt) while (a[l]%p[i]==0) ++c[k][i],a[l]/=p[i];
        c[k][0]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(lson),build(rson);
    pushup(k);
}
ll query(int k,int l,int r,int x,int y)
{
    if (x<=l&&r<=y) return sum[k];
    int mid=(l+r)>>1;ll ret=0;
    pushdown(k);
    if (x<=mid) ret+=query(lson,x,y);
    if (y>mid) ret+=query(rson,x,y);
    return ret%mod;
}
void modify(int k,int l,int r,int x,int *s)
{
    if (l==r)
    {
        ll S=1;
        rep(i,1,cnt) c[k][i]-=s[i],S=S*ksm(p[i],c[k][i])%mod;
        c[k][0]=c[k][0]*inv(s[0])%mod;
        S=S*c[k][0]%mod;
        sum[k]=S;
        return;
    }
    pushdown(k);
    int mid=(l+r)>>1;
    if (x<=mid) modify(lson,x,s);
    else modify(rson,x,s);
    pushup(k);
}
void modify(int k,int l,int r,int x,int y,int *s)
{
    if (x<=l&&r<=y)
    {
        ll S=1;
        rep(i,1,cnt) c[k][i]+=s[i],S=S*ksm(p[i],s[i])%mod;
        (c[k][0]*=s[0])%=mod;(S*=s[0])%=mod;
        (sum[k]*=S)%=mod;
        return;
    }
    pushdown(k);
    int mid=(l+r)>>1;
    if (x<=mid) modify(lson,x,y,s);
    if (y>mid) modify(rson,x,y,s);
    pushup(k);
}
void dfs(int k,int l,int r)
{
    if (l==r)
    {
        ll ret=1;
        rep(i,1,cnt) ret=ret*ksm(p[i],c[k][i])%mod;
        ret*=c[k][0];
        printf("%lld ",ret);
        return;
    }
    pushdown(k);
    int mid=(l+r)>>1;
    dfs(lson);dfs(rson);
}

int s[sz];
void divide(int x)
{
    rep(i,1,cnt) s[i]=0;
    rep(i,1,cnt) while (x%p[i]==0) ++s[i],x/=p[i];
    s[0]=x;
}

int main()
{
    file();
    read(n,mod);int mm=mod;
    rep(i,2,sqrt(mod)) if (mm%i==0) { p[++cnt]=i; while (mm%i==0) mm/=i; }
    if (mm!=1) p[++cnt]=mm;
    rep(i,1,n) read(a[i]);
    build(1,1,n);
    int Q;read(Q);
    int opt,x,y,z;
    while (Q--)
    {
        read(opt);
        if (opt==1) read(x,y,z),divide(z),modify(1,1,n,x,y,s);
        else if (opt==2) read(x,y),divide(y),modify(1,1,n,x,s);
        else read(x,y),printf("%lld\n",query(1,1,n,x,y)%mod);
    }
    return 0;
}