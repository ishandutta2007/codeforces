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
    #define sz 100
    typedef long long ll;
    typedef long double db;
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

int n;
struct hh{ll a,b;inline bool operator < (const hh &y) const {return a>y.a;}}a[sz];

vector<db>w[sz],sum[sz];
int c[sz];
db dp[sz][sz]; // ij 
// j*2 \geq c[i]

bool judge(db W)
{
    int cnt=0;
    rep(i,1,n) w[i].resize(0),sum[i].resize(0);
    rep(i,1,n) 
    {
        if (i==1||a[i].a!=a[i-1].a) ++cnt;
        w[cnt].push_back(a[i].a-W*a[i].b);
    }
    rep(i,1,cnt)
    {
        sort(w[i].begin(),w[i].end());
        sum[i].resize(w[i].size());
        sum[i][0]=w[i][0];
        c[i]=c[i-1]+w[i].size();
        rep(j,1,(int)sum[i].size()-1) sum[i][j]=sum[i][j-1]+w[i][j];
    }
    rep(i,0,n) rep(j,0,c[cnt]) dp[i][j]=1e19;
    dp[0][0]=0;
    rep(i,1,cnt) 
        rep(j,1,c[i]) 
            if (j*2>=c[i])
            {
                dp[i][j]=dp[i-1][j];
                rep(k,1,min(j,c[i]-c[i-1])) if (c[i]-c[i-1]-k<=j*2-c[i-1]-2*k)
                    chkmin(dp[i][j],dp[i-1][j-k]+sum[i][k-1]);
            }
                
    db ret=1e19;
    rep(i,1,n) chkmin(ret,dp[cnt][i]);
    return ret<=0;
}

int main()
{
    file();
    read(n);
    rep(i,1,n) read(a[i].a);
    rep(i,1,n) read(a[i].b);
    sort(a+1,a+n+1);
    db l=0,r=1e10;
    while (r-l>=1e-7)
    {
        db mid=(l+r)/2;
        if (judge(mid)) r=mid;
        else l=mid;
    }
    printf("%lld",(ll)ceil((l)*1000));
    return 0;
}