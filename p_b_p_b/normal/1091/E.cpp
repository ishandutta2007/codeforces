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
    #define sz 505005
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

int n;
int aa[sz],a[sz];
ll s[sz];

int check(int w) // return value : 0:ok;1:big;-1:small
{
    int n=::n+1,t=1;
    rep(i,1,n-1) a[i]=aa[i];a[n]=w;
    drep(i,n,2) 
        if (a[i-1]<=a[i]) swap(a[i-1],a[i]);
        else {t=i;break;}
    drep(i,n,1) s[i]=s[i+1]+a[i];
    int p=n+1;
    rep(k,1,n)
    {
        while (p>1&&a[p-1]<=k) --p;
        ll S;
        if (p<=k+1) S=1ll*k*(k-1)+s[k+1];
        else S=1ll*k*(k-1)+s[p]+1ll*k*(p-1-(k+1)+1);
        if (s[1]-s[k+1]<=S) continue;
        return p>t?1:-1;
    }
    return 0;
}

int main()
{
    file();
    int s=0;
    read(n);
    rep(i,1,n) read(aa[i]),s+=(aa[i]&1);
    sort(aa+1,aa+n+1);reverse(aa+1,aa+n+1);
    s&=1;
    int l,r,L=-1,R=-1;
    l=0,r=n/2;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (check(mid*2+s)>=0) L=mid*2+s,r=mid-1;
        else l=mid+1;
    }
    l=0,r=n/2;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (check(mid*2+s)<=0) R=mid*2+s,l=mid+1;
        else r=mid-1;
    }
    if (L==-1||R==-1||L>R) puts("-1");
    else for (int i=L;i<=R;i+=2) printf("%d ",i);
    return 0;
}