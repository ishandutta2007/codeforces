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
	#define sz 202002
	#define mod 1000000007ll
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

int n;ll T;
ll a[sz],sum[sz];

ll fac[sz],_fac[sz];
void init(){_fac[0]=fac[0]=1;rep(i,1,sz-1) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);}
ll C(int n,int m){return n>=m&&m>=0?fac[n]*_fac[m]%mod*_fac[n-m]%mod:0;}

ll f[sz],s[sz];
ll ans;

int main()
{
	file();
	read(n,T);
	rep(i,1,n) read(a[i]),sum[i]=sum[i-1]+a[i];
	init();
	s[1]=1;
	if (a[1]<T) ans=1,f[1]=2;
	else if (a[1]==T) ans=inv(2),f[1]=1;
	else return puts("0"),0; 
	rep(i,2,n)
	{
		ll spr=T-sum[i];
		if (spr<0) break;
		if (spr>=i) { (ans+=1)%=mod;f[i]=ksm(2,i),s[i]=i;continue; }
		s[i]=spr;f[i]=(mod+2ll*f[i-1]%mod-C(i-1,spr))%mod;
		rep(j,spr+1,s[i-1]) (f[i]+=mod-2ll*C(i-1,j)%mod)%=mod;
		(ans+=f[i]*inv(ksm(2,i))%mod)%=mod;
	}
	cout<<ans;
	return 0;
}