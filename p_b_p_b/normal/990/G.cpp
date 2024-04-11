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
    #define sz 200202
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

int mu[sz],pri[sz],cnt;
bool npri[sz];
void init()
{
    mu[1]=1;
    #define x (i*pri[j])
    rep(i,2,sz-1)
    {
        if (!npri[i]) pri[++cnt]=i,mu[i]=-1;
        rep(j,1,cnt) if (x<sz)
        {
            npri[x]=1;
            if (i%pri[j]==0) break;
            mu[x]=-mu[i];
        } else break;
    }
    #undef x
}

int n;
int a[sz];
int u[sz],v[sz];

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

ll ans[sz],Ans[sz];
vector<int>e[sz];
int fa[sz],size[sz];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
ll merge(int x,int y)
{
    x=getfa(x),y=getfa(y);
    fa[x]=y;
    ll ret=1ll*size[x]*size[y];
    size[y]+=size[x];
    return ret;
}

int main()
{
    file();
    init();
    read(n);
    rep(i,1,n) read(a[i]);
    rep(i,1,n-1)
    {
        read(u[i],v[i]);
        int w=gcd(a[u[i]],a[v[i]]);
        for (int j=1;j*j<=w;j++) if (w%j==0) { e[j].push_back(i); if (j*j!=w) e[w/j].push_back(i); }
    }
    rep(i,1,n) fa[i]=i,size[i]=1;
    rep(i,1,2e5)
    {
        for (int E:e[i]) Ans[i]+=merge(u[E],v[E]);
        for (int E:e[i]) size[fa[u[E]]=u[E]]=1,size[fa[v[E]]=v[E]]=1;
    }
    rep(i,1,2e5)
    {
        rep(j,1,2e5) 
            if (i*j>2e5) break; 
            else ans[i]+=Ans[i*j]*mu[j]; 
    }
    rep(i,1,n) ++ans[a[i]];
    rep(i,1,2e5) if (ans[i]) printf("%d %I64d\n",i,ans[i]);
    return 0;
}