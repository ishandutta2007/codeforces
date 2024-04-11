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
        #ifdef NTFOrz
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

int n,m,_n;
pii a[sz],b[sz];
int jmp[sz][25],R[sz][25];

int main()
{
    file();
	read(n,m);
	rep(i,1,n) read(b[i].fir,b[i].sec);
	sort(b+1,b+n+1);
	int cur=0;
	rep(i,1,n) if (chkmax(cur,b[i].sec)) a[++_n]=b[i];
	n=_n;
	rep(i,1,n)
	{
		int x=upper_bound(a+1,a+n+1,MP(a[i].sec,(int)1e9))-a-1;
		if (x<=i||!x) continue;
		jmp[i][0]=x;
	}
	rep(j,1,20) rep(i,1,n) jmp[i][j]=jmp[jmp[i][j-1]][j-1];
	rep(i,1,n) rep(j,0,20) R[i][j]=a[jmp[i][j]].sec;
	while (m--)
	{
		int l,r;read(l,r);
		int x=upper_bound(a+1,a+n+1,MP(l,(int)1e9))-a-1;
		if (!x||a[x].fir>l) { puts("-1"); continue; }
		if (a[x].sec>=r) { puts("1"); continue; }
		int ans=1;
		drep(i,20,0) if (R[x][i]&&R[x][i]<r) ans+=(1<<i),x=jmp[x][i];
		++ans,x=jmp[x][0];
		if (a[x].sec<r) { puts("-1"); continue; }
		printf("%d\n",ans);
	}
	return 0;
}