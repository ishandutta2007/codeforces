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
    #define sz 303030
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

int n;ll a;
ll sum[sz];
ll d[sz];
ll F[sz];

struct hh
{
    ll f;
    ll mx;
    ll mxr;
}s[sz];
int top;
inline ll sq(ll x){return x*x;}

int main()
{
    file();
    read(n,a);
    ll x;
    rep(i,1,n) read(d[i],x),sum[i]=sum[i-1]+x,F[i]=a*i-sum[i];
    ll ans=max(a-sum[n]+sum[n-1],0ll);
    s[++top]=(hh){F[n],0,F[n]};
    s[0].mxr=-1e15;
    drep(i,n-1,1)
    {
        ll mxF=-1e15;
        while (top&&s[top].mx<=d[i+1]-d[i]) chkmax(mxF,s[top].f),s[top]=(hh){0,0,0},--top;
        if (mxF!=-1e15) {++top;s[top]=(hh){mxF,d[i+1]-d[i],max(mxF-sq(d[i+1]-d[i]),s[top-1].mxr)};}
        ++top;s[top]=(hh){F[i],0,max(F[i],s[top-1].mxr)};
        chkmax(ans,s[top].mxr-a*i+a+sum[i-1]);
    }
    cout<<ans;
    return 0;
}