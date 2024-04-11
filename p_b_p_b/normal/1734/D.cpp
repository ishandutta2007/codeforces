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
    #define templ template<typename T>
    #define sz 233333
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
    inline void print(int x)
    {
        if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
        while(__z[++__zz]=x%10+48,x/=10);
        while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
    }
    void file()
    {
        #ifdef NTFOrz
        freopen("a.in","r",stdin);
        #endif
    }
    inline void chktime()
    {
        #ifdef NTFOrz
        cerr<<clock()/1000.0<<'\n';
        #endif
    }
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
}
using namespace my_std;

int n,K;
ll a[sz];
int nxt[sz],pre[sz];

struct hh
{
    ll x,y;
    bool operator < (const hh &a) const
    {
        if ((x<y)!=(a.x<a.y)) return a.x<a.y;
        if (x<y) return x>a.x;
        return y<a.y;
    }
    const hh operator + (const hh &a) const {if (y>=a.x) return hh{x,y-a.x+a.y};return hh{x-y+a.x,a.y};}
}b[sz];


void work()
{
    read(n,K);
    rep(i,1,n) read(a[i]);
    ll cur=a[K]; a[K]=0;
    a[0]=a[n+1]=1e18;
    rep(i,0,n+1) if (a[i]<=0) b[i]=hh{-a[i],0}; else b[i]=hh{0,a[i]};
    stack<hh>L,R;
    rep(i,0,K-1)
    {
        hh t=b[i];
        while (L.size()&&t<L.top()) t=t+L.top(),L.pop();
        L.push(t);
    }
    drep(i,n+1,K+1)
    {
        hh t=b[i];
        while (R.size()&&t<R.top()) t=t+R.top(),R.pop();
        R.push(t);
    }
    while (L.size()&&R.size())
    {
        if (L.top()<R.top())
        {
            if (cur-R.top().x<0) return puts("NO"),void();
            cur+=R.top().y-R.top().x;
            R.pop();
        }
        else
        {
            if (cur-L.top().x<0) return puts("NO"),void();
            cur+=L.top().y-L.top().x;
            L.pop();
        }
    }
    puts("YES");
}

int main()
{
    file();
    int T; read(T);
    while (T--) work();
    return 0;
}