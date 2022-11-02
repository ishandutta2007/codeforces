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

int ask(set<int>s)
{
    printf("? %d ",(int)s.size());
    for (auto x:s) printf("%d ",x);
    puts("");
    fflush(stdout);
    string S; cin>>S;
    return S=="YES";
}

vector<int>V;
set<int> bu(set<int>s){set<int>res;for (auto x:V) if (!s.count(x)) res.insert(x);return res;};
set<int> bin(set<int>s1,set<int>s2){for (auto x:s2) s1.insert(x);return s1;}

void test(int x)
{
    printf("! %d\n",x); fflush(stdout);
    string s; cin>>s;
    if (s[1]==')') exit(0);
}

void know1()
{
    int w=ask({V[0],V[1]});
    if (w) test(V[0]),test(V[1]);
    else test(V[0]),test(V[2]); 
}
void know2()
{
    test(V[0]),test(V[1]);
}

int main()
{
    int n; read(n);
    rep(i,1,n) V.push_back(i);
    while (V.size()>3u)
    {
        set<int>s1,s2;
        rep(i,0,(int)V.size()-1)
        {
            if (i%2==0) s1.insert(V[i]);
            if ((i&2)==0) s2.insert(V[i]);
        }
        int w1=ask(s1); if (!w1) s1=bu(s1);
        int w2=ask(s2); if (!w2) s2=bu(s2);
        set<int>Or=bin(s1,s2);
        V=vector<int>(Or.begin(),Or.end());
    }
    if ((int)V.size()<=2)
    {
        for (auto x:V) test(x);
        assert(0);
        return 0;
    }
    int w=ask({V[0],V[1]});
    if (!w) swap(V[0],V[2]),know1();
    else
    {
        w=ask({V[0],V[1]});
        if (!w) swap(V[0],V[2]),know1();
        else know2();
    }
    assert(0);
    return 0;
}