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
    #define sz 2010101
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
char s[sz];

namespace SA
{
    int sa[sz],rnk[sz],_rnk[sz],tp[sz],cnt[sz],n;
    void Sort(int m)
    {
        rep(i,1,m) cnt[i]=0;
        rep(i,1,n) ++cnt[rnk[i]];
        rep(i,1,m) cnt[i]+=cnt[i-1];
        drep(i,n,1) sa[cnt[rnk[tp[i]]]--]=tp[i];
    }
    void init()
    {
        rep(i,1,n) rnk[i]=s[i]-'('+1,tp[i]=i;
        Sort(5);
        for (int p=0,w=1,m=5;p<n;w<<=1,m=p)
        {
            p=0;
            rep(i,n-w+1,n) tp[++p]=i;
            rep(i,1,n) if (sa[i]>w) tp[++p]=sa[i]-w;
            Sort(m);
            memcpy(_rnk,rnk,sizeof(rnk));
            rnk[sa[p=1]]=1;
            rep(i,2,n) rnk[sa[i]]=(_rnk[sa[i]]==_rnk[sa[i-1]]&&_rnk[sa[i]+w]==_rnk[sa[i-1]+w])?p:++p;
        }
    }
}

int L,R,firR=1e9,lasL=-1;
int vis[sz];
int Sl[sz],Sr[sz];
void init()
{
    int cnt;
    cnt=0;
    rep(i,1,n)
        if (s[i]=='(') ++cnt;
        else if (cnt) --cnt;
        else vis[i]=-1,lasL=i,++L;
    cnt=0;
    drep(i,n,1)
        if (s[i]==')') ++cnt;
        else if (cnt) --cnt;
        else vis[i]=-2,firR=i,++R;
    int cur=1;
    while (cur<=n)
    {
        if (vis[cur]<0) { ++cur; continue; }
        int cnt=0;
        vis[cur]=2;
        while (cur<=n)
        {
            if (s[cur]=='(') ++cnt;
            else --cnt;
            ++cur;
            if (!cnt) break;
        }
        vis[cur-1]=1;
    }
    rep(i,1,n) Sl[i]=Sl[i-1]+(vis[i]==-1);
    drep(i,n,1) Sr[i]=Sr[i+1]+(vis[i]==-2);
}

void solve1()
{
    rep(i,1,n+n)
    {
        int x=SA::sa[i];
        if (x>n) continue;
        if ((vis[x-1]<0||vis[x-1]==1||x==1)&&x>lasL&&Sr[x]>=L)
        {
            rep(k,x,x+n-1) putchar(s[k]);
            rep(k,1,R-L) putchar(')');
            return;
        }
    }
}
void solve2()
{
    rep(i,1,n+n)
    {
        int x=SA::sa[i];
        if (x>n) continue;
        if ((vis[x+1]<0||vis[x+1]==2||x==n)&&x<firR&&Sl[x]>=R)
        {
            rep(k,1,L-R) putchar('(');
            rep(k,x+1,x+n) putchar(s[k]);
            return;
        }
    }
}

int main()
{
    file();
    cin>>(s+1);n=strlen(s+1);
    rep(i,n+1,n+n) s[i]=s[i-n];
    SA::n=n+n;SA::init();
    init();
    if (L<=R) solve1();
    else solve2();
    return 0;
}