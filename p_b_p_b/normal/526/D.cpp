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
    #define sz 1010101
    #define mod 19260817ll
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
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,K;
char s[sz];

ll hsh[sz],P[sz],_P[sz];
void init()
{
    P[0]=_P[0]=1;ll I=inv(26);
    rep(i,1,n) 
        _P[i]=_P[i-1]*I%mod,
        P[i]=P[i-1]*26%mod,
        hsh[i]=(hsh[i-1]+P[i]*(s[i]-'a')%mod)%mod;
}
ll Hash(int l,int r){return (hsh[r]-hsh[l-1]+mod)%mod*_P[l-1]%mod;}

int ok[sz];
void work(int p)
{
    int l=p*K,r=min(p*K+p,n);
    if (l>n) return;
    if (Hash(1,p)!=Hash(l-p+1,l)||Hash(1,l-p)!=Hash(p+1,l)) return;
    ++ok[l];
    int pos=l;
    ++l;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (Hash(1,mid-p*K)==Hash(p*K+1,mid)) pos=mid,l=mid+1;
        else r=mid-1;
    }
    --ok[pos+1];
}

int main()
{
    file();
    read(n,K);
    cin>>(s+1);
    init();
    rep(i,1,n/K) work(i);
    rep(i,1,n) ok[i]+=ok[i-1],putchar('0'+(ok[i]>0));
    return 0;
}