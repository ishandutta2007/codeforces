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
    #define sz 233
    #define mod 1000000007ll 
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

int n;
int edge[sz][sz];

ll a[sz][sz];
void make_edge(int x,int y,ll w){a[x][x]+=w;a[x][y]-=w;}
ll gauss(int n,int type)
{
    ll ret=1;
    rep(i,1,n)
    {
        int tmp=-1;
        rep(j,i,n) if (a[j][i]) tmp=j;
        if (tmp!=i) ret=-ret,swap(a[i],a[tmp]);
        rep(j,i+1,n)
        {
            ll I=a[j][i]*inv(a[i][i])%mod;
            rep(k,i,n+type) (a[j][k]+=mod-I*a[i][k]%mod)%=mod;
        }
    }
    rep(i,1,n) ret=ret*a[i][i]%mod;
    return (ret%mod+mod)%mod;
}

ll s[sz][sz];
ll ans[sz];

int main()
{
    file();
    read(n);
    int x,y;
    rep(i,1,n-1) read(x,y),edge[x][y]=edge[y][x]=1;
    rep(t,1,n)
    {
        rep(i,1,n) rep(j,1,n) a[i][j]=0;
        rep(i,1,n) rep(j,1,n) make_edge(i,j,edge[i][j]?t:1);
        s[t][n+1]=gauss(n-1,0);
        ll cur=1;
        rep(i,1,n) s[t][i]=cur,cur=cur*t%mod;
    }
    rep(i,1,n) rep(j,1,n+1) a[i][j]=s[i][j];
    gauss(n,1);
    drep(i,n,1)
    {
        rep(j,i+1,n) (a[i][n+1]-=a[i][j]*ans[j-1]%mod-mod)%=mod;
        ans[i-1]=a[i][n+1]*inv(a[i][i])%mod;
    }
    rep(i,0,n-1) printf("%lld ",ans[i]);
    return 0;
}