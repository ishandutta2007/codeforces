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
    #define S 500
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

int n,m;
int pos[sz],a[sz];

struct hh
{
    int type; // 0:query,1:add
    int p,pos,v; // a[p]->pos,v
    int r,x,y,val,id; // a:1~r,pos:x~y 
}q[sz<<3];
inline bool cmp(const hh &x,const hh &y)
{
    if (x.type!=y.type) return x.type<y.type;
    if (x.type==1) return x.p<y.p;
    return x.r<y.r;
}
int cnt;

void adda(int x,int pos){if (a[x]) q[++cnt]=(hh){1,x,a[x],-1,0,0,0,0,0};q[++cnt]=(hh){1,x,pos,1,0,0,0,0,0};}
void addq(int l1,int r1,int l2,int r2,int id){q[++cnt]=(hh){0,0,0,0,l2-1,l1,r1,-1,id};q[++cnt]=(hh){0,0,0,0,r2,l1,r1,1,id};}

int Ans[sz];
int tr[sz];
void add(int x,int y){while (x<=n) tr[x]+=y,x+=(x&(-x));}
int query(int x){int ret=0;while (x) ret+=tr[x],x-=(x&(-x));return ret;}
void solve(int l,int r)
{
    if (l==r) return;
    int mid=(l+r)>>1;
    solve(l,mid);solve(mid+1,r);
    int p=l-1;
    rep(i,mid+1,r) if (q[i].type==0)
    {
        while (p<mid)
        {
            if (q[p+1].type==0) ++p;
            else if (q[p+1].p<=q[i].r) 
            {
                ++p;
                add(q[p].pos,q[p].v);
            }
            else break; 
        }
        Ans[q[i].id]+=q[i].val*(query(q[i].y)-query(q[i].x-1));
    }
    rep(i,l,p) if (q[i].type) add(q[i].pos,-q[i].v);
    sort(q+l,q+r+1,cmp);
}

int main()
{
    file();
    read(n,m);
    int x,y,z,l1,l2,r1,r2;
    rep(i,1,n) read(x),pos[x]=i;
    rep(i,1,n) read(x),adda(i,pos[x]),a[i]=pos[x];
    int c=0;
    rep(i,1,m)
    {
        read(z);
        if (z==1) read(l1,r1,l2,r2),addq(l1,r1,l2,r2,++c);
        else read(x,y),adda(x,a[y]),adda(y,a[x]),swap(a[x],a[y]);
    }
    solve(1,cnt);
    rep(i,1,c) printf("%d\n",Ans[i]);
    return 0;
}