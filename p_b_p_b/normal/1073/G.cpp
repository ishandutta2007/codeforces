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
    #define sz 220020
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
    templ inline void print(T x)
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

int n,Q;
int a[sz];
char s[sz];

int h[sz];
int st[sz][30],lg2[sz];
void init()
{
    lg2[1]=0;rep(i,2,n) lg2[i]=lg2[i>>1]+1;
    rep(i,1,n) st[i][0]=h[i];
    rep(j,1,20)
        rep(i,1,n-(1<<j)+1)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
inline int query(register int l,register int r){if (l>r) return 1e9;int len=lg2[r-l+1];return min(st[l][len],st[r-(1<<len)+1][len]);}

namespace SA
{
    int cnt[sz],sa[sz],tp[sz],rnk[sz],_rnk[sz];
    void Sort(int m)
    {
        rep(i,1,m) cnt[i]=0;
        rep(i,1,n) ++cnt[rnk[i]];
        rep(i,1,m) cnt[i]+=cnt[i-1];
        drep(i,n,1) sa[cnt[rnk[tp[i]]]--]=tp[i];
    }
    void init()
    {
        rep(i,1,n) rnk[i]=a[i],tp[i]=i;
        Sort(27);
        for (int w=1,p=0,m=27;p<n;w<<=1,m=p)
        {
            p=0;
            rep(i,n-w+1,n) tp[++p]=i;
            rep(i,1,n) if (sa[i]>w) tp[++p]=sa[i]-w;
            Sort(m);
            memcpy(_rnk,rnk,sizeof(rnk));
            rnk[sa[p=1]]=1;
            rep(i,2,n) rnk[sa[i]]=(_rnk[sa[i]]==_rnk[sa[i-1]]&&_rnk[sa[i]+w]==_rnk[sa[i-1]+w])?p:++p;
        }
        for (int i=1,j,k=0;i<=n;i++)
        {
            if (k) k--;
            j=sa[rnk[i]-1];
            while (a[i+k]==a[j+k]) ++k;
            h[rnk[i]]=k;
        }
    }
}

int q1[sz],q2[sz];
struct hh{ll sum,S;int mn;};
struct hhh{int id,type;}q[sz<<1];
inline bool cmp(const hhh &x,const hhh &y){return x.id==y.id?x.type>y.type:x.id<y.id;}
ll solve(int *q1,int *q2,int n,int m)
{
    stack<hh>s;
    rep(i,1,n) q[i]=(hhh){q1[i]+1,1};rep(i,1,m) q[i+n]=(hhh){q2[i],0};
    sort(q+1,q+n+m+1,cmp);
    int lst=-1;ll ret=0;
    rep(i,1,n+m)
    {
        if (lst!=-1) 
        {
            int x=query(lst+1,q[i].id);
            ll SS=0;
            while (!s.empty()&&s.top().mn>=x) SS+=s.top().S,s.pop();
            ll sum=SS*x;if (!s.empty()) sum+=s.top().sum;
            s.push((hh){sum,SS,x});
        }
        if (q[i].type) { ll S=h[q[i].id],sum=S+(s.empty()?0:s.top().sum); s.push((hh){sum,1,h[q[i].id]}); }
        else if (!s.empty()) ret+=s.top().sum;
        lst=q[i].id;
    }
    return ret;
}

int main()
{
    file();
    read(n,Q);
    cin>>(s+1);
    rep(i,1,n) a[i]=s[i]-'a'+1;
    SA::init();
    init();
    while (Q--)
    {
        int x,y,z;ll ans=0;
        read(x,y);
        rep(i,1,x) read(z),q1[i]=SA::rnk[z];
        rep(i,1,y) read(z),q2[i]=SA::rnk[z];
        sort(q1+1,q1+x+1);sort(q2+1,q2+y+1);
        ans+=solve(q1,q2,x,y);
        ans+=solve(q2,q1,y,x);
        int t1=1,t2=1;
        while (t1<=x&&t2<=y) 
        {
            if (q1[t1]==q2[t2]) ans+=n-SA::sa[q1[t1]]+1,++t1,++t2;
            else if (q1[t1]<q2[t2]) ++t1;
            else ++t2;
        }
        print(ans);
    }
    Ot();
    return 0;
}