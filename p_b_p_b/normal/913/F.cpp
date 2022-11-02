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
	#define sz 4040
	#define mod 998244353ll
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
		#ifdef NTFOrz
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

int n;ll _a,_b,p,q;
ll pw1[sz],pw2[sz];
ll f[sz],g[sz],dp[sz][sz];

int main()
{
	file();
	read(n,_a,_b);p=_a*inv(_b)%mod;q=mod+1-p;
	pw1[0]=pw2[0]=1;
	rep(i,1,n) pw1[i]=pw1[i-1]*p%mod,pw2[i]=pw2[i-1]*q%mod;
	dp[0][0]=1;
	rep(i,1,n) rep(j,0,i) dp[i][j]=(dp[i-1][j]*pw2[j]%mod+dp[i-1][j-1]*pw1[i-j]%mod)%mod;
	rep(i,1,n) g[i]=1;
	rep(i,2,n) rep(j,1,i-1) g[i]=(mod+g[i]-dp[i][j]*g[j]%mod)%mod;
	f[1]=0;
	rep(i,2,n)
	{
		ll sum=0;
		rep(j,1,i-1) (sum+=dp[i][j]*g[j]%mod*(1ll*j*(i-j)%mod+(1ll*j*(j-1)/2%mod)+f[j]+f[i-j])%mod)%=mod;
		(sum+=g[i]*(1ll*i*(i-1)/2%mod)%mod)%=mod;
		f[i]=sum*inv(mod+1-g[i])%mod; 
	}
	cout<<f[n];
	return 0;
}