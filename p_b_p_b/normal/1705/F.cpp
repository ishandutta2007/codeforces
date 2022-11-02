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
    #define sz 1111
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

int cc;
int query(string s)
{
    ++cc;
#ifndef NTFOrz
    printf("%s\n",s.c_str());
    fflush(stdout);
    int x; read(x);
    if (x==(int)s.size()||x==-1) exit(0);
    return x;
#else
    static string S; static int flg;
    if (!flg)
    {
        flg=1;
        rep(i,0,(int)s.size()-1) S+="FT"[rnd(0,1)];
    }
    int res=0; rep(i,0,(int)s.size()-1) res+=(s[i]==S[i]);
    if (res==(int)s.size()) cerr<<cc<<'\n',exit(0);
    return res;
#endif
}

int n;
int ans[sz];
void dfs(int x)
{
    if (ans[x]>=0) return;
    dfs(-ans[x]);
    ans[x]=ans[-ans[x]]^1;
}

int allF;
void work()
{
    vector<int>V; rep(i,1,n) V.push_back(i);
    string s; rep(i,1,n) s+='F';
    while (V.size()>=4u)
    {
        shuffle(V.begin(),V.end(),rng);
        vector<int>VV;
        rep(i,0,(int)V.size()/4-1)
        {
            vector<int>v(V.begin()+i*4,V.begin()+i*4+4);
            for (auto x:v) s[x-1]='T';
            int t=query(s)-allF;
            for (auto x:v) s[x-1]='F';
            if (t==4||t==-4) { for (auto x:v) ans[x]=(t==4); continue; }
            int x=v[0],y=v[1];
            s[x-1]=s[y-1]='T';
            int tt=query(s)-allF;
            s[x-1]=s[y-1]='F';
            if (tt==-2) ans[x]=ans[y]=0;
            else if (tt==2) ans[x]=ans[y]=1;
            else ans[y]=-x,VV.push_back(x);
            x=v[2],y=v[3];
            tt=t-tt;
            if (tt==-2) ans[x]=ans[y]=0;
            else if (tt==2) ans[x]=ans[y]=1;
            else ans[y]=-x,VV.push_back(x);
        }
        rep(i,(int)V.size()/4*4,(int)V.size()-1) VV.push_back(V[i]);
        V=VV;
        // cerr<<cc<<' '<<n-(int)V.size()<<'\n';
    }
    for (auto x:V) s[x-1]='T',ans[x]=(query(s)>allF),s[x-1]='F';
}


int main()
{
    read(n);
    rep(i,1,n) ans[i]=2;
    string s; rep(i,1,n) s+='F';
    allF=query(s);
    work();
    rep(i,1,n) if (ans[i]<0) dfs(i);
    s="";
    rep(i,1,n) s+="FT"[ans[i]];
    cerr<<query(s)<<'\n';
    assert(0);
    return 0;
}