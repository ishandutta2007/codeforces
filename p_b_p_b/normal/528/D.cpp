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
    #define sz 802002
    #define mod 998244353
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

int n,m,K;
char A[sz],B[sz];
int a[sz],b[sz];
int ans[sz];
char ch[]={' ','A','T','G','C'};

int r[sz],limit;
void NTT_init(int n)
{
    limit=1;int l=-1;
    while (limit<=n+n) limit<<=1,++l;
    rep(i,0,limit-1) r[i]=(r[i>>1]>>1)|((i&1)<<l);
}
void NTT(int *a,int type)
{
    rep(i,0,limit-1) if (i<r[i]) swap(a[i],a[r[i]]);
    for (int mid=1;mid<limit;mid<<=1)
    {
        ll Wn=ksm(3,(mod-1)/mid>>1);if (type==-1) Wn=inv(Wn);
        for (int len=mid<<1,j=0;j<limit;j+=len)
        {
            ll w=1;
            for (int k=0;k<mid;k++,w=w*Wn%mod)
            {
                ll x=a[j+k],y=w*a[j+k+mid]%mod;
                a[j+k]=(x+y)%mod;a[j+k+mid]=(x-y+mod)%mod;
            }
        }
    }
    if (type==1) return;
    ll I=inv(limit);
    rep(i,0,limit-1) a[i]=1ll*a[i]*I%mod;
}

void solve(char ch)
{
    NTT_init(n+1);
    rep(i,0,limit-1) a[i]=b[i]=0;
    rep(i,1,m) b[i]=(B[i]==ch);
    int cnt;
    cnt=1e9;
    rep(i,1,n)
        if (A[i]==ch) cnt=1,a[i]=1;
        else a[i]=(cnt<=K),++cnt;
    cnt=1e9;
    drep(i,n,1)
        if (A[i]==ch) cnt=1;
        else a[i]|=(cnt<=K),++cnt;
    reverse(b+1,b+m+1);
    NTT(a,1);NTT(b,1);
    rep(i,0,limit-1) a[i]=1ll*a[i]*b[i]%mod;
    NTT(a,-1);
    rep(i,1,n) ans[i]+=a[i+m];
}

int main()
{
    file();
    read(n,m,K);
    cin>>(A+1)>>(B+1);
    rep(i,1,4) solve(ch[i]);
    int Ans=0;
    rep(i,1,n-m+1) Ans+=(ans[i]==m);
    cout<<Ans;
    return 0;
}