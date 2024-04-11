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
    #define sz 404004
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

int n,m;
int a[sz];
map<int,int>cc;
pii cnt[sz];

int work(int x)
{
	int sum=0;
	rep(i,1,m) sum+=min(cnt[i].fir,x);
	sum/=x;
	return sum>=x?sum:-1;
}

int ans[sz<<2];
void Print(int x)
{
	sort(cnt+1,cnt+m+1);reverse(cnt+1,cnt+m+1);
	rep(i,1,m) chkmin(cnt[i].fir,x);
	int y=0;
	rep(i,1,m) y+=cnt[i].fir;
	y/=x;
	printf("%d\n%d %d\n",x*y,x,y);
	#define id(a,b) (((a)-1)*y+(b))
	#define calc(a) (((a)>y)?(a)-y:(a))
	int p=1;
	rep(i,1,y) rep(j,1,x) 
	{
		ans[id(j,calc(i+j-1))]=cnt[p].sec;
		if (!--cnt[p].fir) ++p;
	}
	rep(i,1,x)
	{
		rep(j,1,y) printf("%d ",ans[id(i,j)]);
		puts("");
	}
}

int main()
{
    file();
	read(n);
	rep(i,1,n) read(a[i]),++cc[a[i]];
	for (auto x:cc) cnt[++m]=MP(x.sec,x.fir);//,printf("%d %d\n",x.fir,x.sec);
	int mx=0,p=0;
	for (int i=1;i*i<=n;i++) if (chkmax(mx,work(i)*i)) p=i;
	Print(p);
	return 0;
}