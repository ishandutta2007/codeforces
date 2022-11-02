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
    #define sz 800202 
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
    char sr[1<<21],z[20];int C=-1,Z=0;
    inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
    inline void print(register int x)
    {
    	if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
    	while(z[++Z]=x%10+48,x/=10);
    	while(sr[++C]=z[Z],--Z);sr[++C]='\n';
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

int n,x;
int a[sz];
int L[sz],R[sz];

const db PI=acos(-1.0);
struct Complex
{
    db x,y;
    Complex(db xx=0,db yy=0){x=xx,y=yy;}
};
const Complex operator + (const Complex &a,const Complex &b) {return Complex(a.x+b.x,a.y+b.y);}
const Complex operator - (const Complex &a,const Complex &b) {return Complex(a.x-b.x,a.y-b.y);}
const Complex operator * (const Complex &a,const Complex &b) {return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}

int limit,r[sz];
void FFT_init(int n)
{
    int l=-1;limit=1;
    while (limit<=n+n) ++l,limit<<=1;
    rep(i,0,limit-1) r[i]=(r[i>>1]>>1)|((i&1)<<l);
}
void FFT(Complex *a,int type)
{
    for (int i=0;i<limit;i++) if (i<r[i]) swap(a[i],a[r[i]]);
    for (int mid=1;mid<limit;mid<<=1)
    {
        Complex Wn(cos(PI/mid),type*sin(PI/mid));
        for (int len=mid<<1,j=0;j<limit;j+=len)
        {
            Complex w(1,0);
            for (int k=0;k<mid;k++,w=w*Wn)
            {
                Complex x=a[j+k],y=w*a[j+mid+k];
                a[j+k]=x+y;a[j+k+mid]=x-y;
            }
        }
    }
}
Complex _a[sz],_b[sz];

ll ans[sz];
ll CC(int n){return 1ll*n*(n+1)/2;}

int main()
{
    file();
    int cnt,c,cc;
    read(n,x);
    rep(i,1,n) read(a[i]);
    cnt=c=0;
    rep(i,1,n)
        if (a[i]<x) L[++c]=cnt+1,cnt=0;
        else ++cnt;
    cnt=0;cc=c;
    drep(i,n,1)
        if (a[i]<x) R[c--]=cnt+1,cnt=0;
        else ++cnt;
    reverse(L+1,L+cc+1);
    rep(i,1,cc) _a[i].x=L[i],_b[i].x=R[i];
    FFT_init(cc+1);
    FFT(_a,1);FFT(_b,1);
    rep(i,0,limit-1) _a[i]=_a[i]*_b[i];
    FFT(_a,-1);
    rep(i,1,n) ans[i]=ll(_a[i+cc].x/limit+0.5);
    if (cc)
    {
        rep(i,1,cc) ans[0]+=CC(R[i]-1);
        ans[0]+=CC(L[cc]-1);
    } else ans[0]=CC(n);
    rep(i,0,n) printf("%lld ",ans[i]);
    return 0;
}