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
    #define sz 402200 
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
pii a[sz];
int aa[sz];

int pre[sz],suf[sz];
void add(int p){suf[pre[p]]=pre[suf[p]]=p;}
void del(int p){suf[pre[p]]=suf[p];pre[suf[p]]=pre[p];}

int Ans[sz];

int pos[sz],blo,num;
void init(){blo=sqrt(n);rep(i,1,n) pos[i]=(i-1)/blo+1;num=pos[n];}
struct hh{int l,r,id;}q[sz];
inline bool cmp(const hh &x,const hh &y){return pos[x.l]==pos[y.l]?x.r<y.r:pos[x.l]<pos[y.l];}

int Lans[sz];
int update(int x)
{
    int ret=1e9;
    if (pre[x]) chkmin(ret,aa[x]-aa[pre[x]]);
    if (suf[x]!=n+1) chkmin(ret,aa[suf[x]]-aa[x]);
    return ret;
}

int main()
{
    file();
    read(n);
    rep(i,1,n) read(a[i].fir),a[i].sec=i,aa[i]=a[i].fir;
    sort(a+1,a+n+1);
    read(m);
    init();
    int x,y;
    rep(i,1,m) read(x,y),q[i]=(hh){x,y,i};
    sort(q+1,q+m+1,cmp);
    int p=1;
    rep(_,1,num)
    {
        int L=(_-1)*blo+1,R=min(_*blo,n),posR=R;
        rep(i,1,n) Lans[i]=1e9;
        int lst=0;
        rep(i,0,n+1) pre[i]=suf[i]=0;
        rep(i,1,n) suf[lst]=a[i].sec,pre[a[i].sec]=lst,lst=a[i].sec;
        pre[suf[lst]=n+1]=lst;
        rep(i,1,R) del(i);
        drep(i,n,R+1) del(i);
        rep(i,R+1,n) add(i),Lans[i]=min(Lans[i-1],update(i));
        drep(i,R,L) add(i);
        drep(i,n,R+1) del(i);
        for (;p<=m&&pos[q[p].l]==_;p++)
        {
            int ans=1e9;
            if (q[p].r<=R)
            {
                rep(i,L,q[p].l-1) del(i);
                drep(i,R,q[p].l) del(i);
                rep(i,q[p].l,q[p].r) add(i),chkmin(ans,update(i));
                rep(i,q[p].r,R) add(i);
                drep(i,q[p].l-1,L) add(i);
                Ans[q[p].id]=ans;
            }
            else
            {
                while (posR<q[p].r) ++posR,add(posR);
                rep(i,L,R) del(i);
                drep(i,R,q[p].l) add(i),chkmin(ans,update(i));
                drep(i,q[p].l-1,L) add(i);
                Ans[q[p].id]=min(ans,Lans[posR]);
            }
        }
    }
    rep(i,1,m) printf("%d\n",Ans[i]);
    return 0;
}