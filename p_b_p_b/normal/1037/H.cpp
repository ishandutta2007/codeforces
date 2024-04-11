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
    #define sz 202020
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

struct hh{int link,len,ch[28],edp;}a[sz];
int last=1,cnt=1;
void insert(int c,int pp)
{
    int cur=++cnt;a[cur].edp=pp;
    int p=last;last=cur;
    a[cur].len=a[p].len+1;
    while (!a[p].ch[c]) a[p].ch[c]=cur,p=a[p].link;
    if (!p) return void(a[cur].link=1);
    int q=a[p].ch[c];
    if (a[q].len==a[p].len+1) return void(a[cur].link=q);
    int t=++cnt;
    a[t]=a[q];a[t].len=a[p].len+1;a[t].edp=0;
    while (a[p].ch[c]==q) a[p].ch[c]=t,p=a[p].link;
    a[q].link=a[cur].link=t;
}

#define Tree sz*20
int tr[Tree],ls[Tree],rs[Tree],cc;
int root[sz];
void insert(int &k,int l,int r,int x)
{
    if (!k) k=++cc;
    tr[k]=1;
    if (l==r) return;
    int mid=(l+r)>>1;
    if (x<=mid) insert(ls[k],l,mid,x);
    else insert(rs[k],mid+1,r,x);
}
int merge(int k1,int k2,int l,int r)
{
    if (!k1||!k2) return k1+k2;
    int k=++cc;tr[k]=tr[k1]|tr[k2];
    int mid=(l+r)>>1;
    ls[k]=merge(ls[k1],ls[k2],l,mid);
    rs[k]=merge(rs[k1],rs[k2],mid+1,r);
    return k;
//	if (!k1||!k2) return k1+k2;
//	tr[k1]|=tr[k2];
//	int mid=(l+r)>>1;
//	ls[k1]=merge(ls[k1],ls[k2],l,mid);
//	rs[k1]=merge(rs[k1],rs[k2],mid+1,r);
//	return k1;
}
int query(int k,int l,int r,int x,int y)
{
    if (!k||x>y) return 0;
    if (x<=l&&r<=y) return tr[k];
    int mid=(l+r)>>1;
    if (x<=mid&&query(ls[k],l,mid,x,y)) return 1;
    if (y>mid&&query(rs[k],mid+1,r,x,y)) return 1;
    return 0;
}

int c[sz],id[sz];
void init()
{
    rep(i,1,n) insert(s[i]-'a'+1,i);
    rep(i,1,cnt) ++c[a[i].len];
    rep(i,1,n) c[i]+=c[i-1];
    drep(i,cnt,1) id[c[a[i].len]--]=i;
    drep(i,cnt,1) 
    {
        int x=id[i];
        if (a[x].edp) insert(root[x],1,n,a[x].edp);
        root[a[x].link]=merge(root[a[x].link],root[x],1,n);
    }
}

int L,R;
char ss[sz];int m;
int p[sz];
void Query()
{
    m=strlen(ss+1);int lim=m,cur=1;
    p[0]=1;
    rep(i,1,m) if (!(cur=a[cur].ch[ss[i]-'a'+1])) { lim=i-1; break; } else p[i]=cur;
    ss[m+1]='a'-1;
    drep(i,lim,0) rep(j,ss[i+1]-'a'+1+1,26) if (a[p[i]].ch[j]&&query(root[a[p[i]].ch[j]],1,n,L+i,R))
    {
        rep(k,1,i) putchar(ss[k]);
        putchar(j-1+'a');puts("");
        return; 
    }
    puts("-1");
}

int main()
{
    file();
    cin>>(s+1);n=strlen(s+1);
    init();
    int Q;read(Q);
    while (Q--)
    {
        read(L,R);cin>>(ss+1);
        Query();
    }
    return 0;
}