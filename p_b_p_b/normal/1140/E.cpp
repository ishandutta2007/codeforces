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
    #define sz 202020
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

int n;ll k;
int a[sz];

int tmp[sz];
ll dp[sz][2];
int nxt[sz];
ll work(int *a,int m)
{
    rep(i,2,m) if (a[i]==a[i-1]&&a[i]!=-1) return 0;
    int n=m;while (a[n]==-1) --n;
    if (!n) return 1ll*k*ksm(k-1,m-1)%mod;
    drep(i,n,1) 
        if (a[i]!=-1) nxt[i]=i; 
        else nxt[i]=nxt[i+1];
    int las=0;
    rep(i,1,n) if (a[i]==-1)
    {
        if (i==1) dp[i][0]=k-1,dp[i][1]=1;
        else if (a[i-1]!=-1)
        {
            if (las)
            {
                if (a[i-1]==a[nxt[i]]) dp[i][0]=1ll*(k-1)*dp[las][0]%mod,dp[i][1]=0;
                else dp[i][0]=1ll*(k-2)*dp[las][0]%mod,dp[i][1]=dp[las][0];
            }
            else
            {
                if (a[i-1]==a[nxt[i]]) dp[i][0]=k-1,dp[i][1]=0;
                else dp[i][0]=k-2,dp[i][1]=1;
            }
        }
        else dp[i][0]=((k-1)*dp[i-1][1]+(k-2)*dp[i-1][0])%mod,dp[i][1]=dp[i-1][0];
        las=i;
    }
    if (!las) return ksm(k-1,m-n);
    return dp[las][0]*ksm(k-1,m-n)%mod;
}

int main()
{
    file();
    read(n,k);
    rep(i,1,n) read(a[i]);
    int m=(n+1)>>1;
    for (int i=1;i<=n;i+=2) tmp[(i+1)>>1]=a[i];
    ll ans1=work(tmp,m);
    for (int i=2;i<=n;i+=2) tmp[i>>1]=a[i];
    ll ans2=work(tmp,n-m);
    cout<<ans1*ans2%mod;
    return 0; 
}