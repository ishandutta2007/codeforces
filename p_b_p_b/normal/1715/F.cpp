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

int swp;
int n,m;

db ask(vector<pair<db,db>>V)
{
    printf("? %d\n",(int)V.size());
    if (swp) rep(i,0,(int)V.size()-1) swap(V[i].fir,V[i].sec);
    for (auto [x,y]:V) printf("%.15lf %.15lf\n",x,y);
    fflush(stdout);
    db x; read(x); return x;
}
db work()
{
    const db eps=1e-14;
    vector<pair<db,db>>V;
    for (int i=-2;i<=n+2;i+=2) V.push_back(MP(i,m-eps)),V.push_back(MP(i,0)),V.push_back(MP(i+1,0)),V.push_back(MP(i+1,m-eps));
    V.push_back(MP(n,m)),V.push_back(MP(0,m));
    db S=ask(V);
    V.clear();
    if (S<1e-8||S>1-1e-8)
    {
        int tot=0; for (int i=-2;i<=n+2;i+=2) tot++;
        int cc=0;
        for (int i=-2;i<=n+2;i+=2)
        {
            db l=i-(1-S),r=i+S;
            ++cc;
            r-=(1-1.0*cc/tot);
            V.push_back(MP(l,m-eps)),V.push_back(MP(l,0)),V.push_back(MP(r,0)),V.push_back(MP(r,m-eps));
        }
        V.push_back(MP(n,m)),V.push_back(MP(0,m));
        db S2=ask(V);
        cc=round(S2*tot);
        for (int i=-2;i<=n+2;i+=2)
        {
            db l=i-(1-S),r=i+S;
            --cc;
            if (!cc) return l;
        }
        assert(0); return 0;
    }
    int tot=0; for (int i=-2;i<=n+2;i+=2) tot+=2;
    int cc=0;
    db out; if (S<0.5) out=S; else out=1-S;
    for (int i=-2;i<=n+2;i+=2)
    {
        db l=i-(1-S),r=i+S;
        ++cc;
        if (S<0.5) l+=(1-out*cc/tot); else r-=(1-out*cc/tot);
        V.push_back(MP(l,m-eps)),V.push_back(MP(l,0)),V.push_back(MP(r,0)),V.push_back(MP(r,m-eps));
        l=i+(1-S),r=i+2-S;
        ++cc;
        if (S<0.5) r-=(1-out*cc/tot); else l+=(1-out*cc/tot);
        V.push_back(MP(l,m-eps)),V.push_back(MP(l,0)),V.push_back(MP(r,0)),V.push_back(MP(r,m-eps));
    }
    V.push_back(MP(n,m)),V.push_back(MP(0,m));
    db S2=ask(V);
    cc=round(S2*tot/out);
    for (int i=-2;i<=n+2;i+=2)
    {
        db l=i-(1-S),r=i+S;
        --cc;
        if (!cc) return l;
        l=i+(1-S),r=i+2-S;
        --cc;
        if (!cc) return l;
    }
    assert(0); return 0;
}

int main()
{
    read(n,m);
    db x=work();
    swp=1; swap(n,m);
    db y=work();
    printf("! %.10lf %.10lf\n",x,y); fflush(stdout);
    return 0;
}