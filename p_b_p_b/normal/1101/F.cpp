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
    #define sz 410 
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

int n,m;
int a[sz];

int dp[2][sz][sz];
int cur,lst;
void solve()
{
    swap(cur,lst);
    rep(len,1,n)
    {
        int p=1;
        rep(i,1,n-len+1)
        {
            int j=i+len-1;
            if (p<i) ++p;
            while (p<j&&max(dp[lst][i][p],a[j]-a[p])>=max(dp[lst][i][p+1],a[j]-a[p+1]))	++p;
            dp[cur][i][j]=max(dp[lst][i][p],a[j]-a[p]);
            j=i+len-1;
        }
    }
}

struct hh{int l,r,c,k;}q[260000];
inline bool cmp(const hh &x,const hh &y){return x.k<y.k;}

int main()
{
    file();
    read(n,m);
    rep(i,1,n) read(a[i]);
    rep(i,1,n) rep(j,i,n) dp[1][i][j]=a[j]-a[i];
    cur=1;
    ll ans=0;
    int l,r,c,k;
    rep(i,1,m) read(l,r,c,k),q[i]=(hh){l,r,c,k+1};
    sort(q+1,q+m+1,cmp);
    k=1;
    rep(i,1,m)
    {
        while (k<q[i].k) solve(),++k;
        chkmax(ans,1ll*dp[cur][q[i].l][q[i].r]*q[i].c);
    }
    cout<<ans;
    return 0;
}