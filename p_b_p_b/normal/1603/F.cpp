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
	#define sz 10101000
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
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

ll wtf[sz],pre[sz];

void work()
{
	int n,K,x; read(n,K,x);
	if (x==0)
	{
		if (n>K) return puts("0"),void();
		ll ans=1,w1=ksm(2,K),w2=1;
		rep(i,1,n) ans=ans*(w1-w2+mod)%mod,w2=w2*2%mod;
		printf("%lld\n",ans);
		return;
	}
	ll ans=1;
	ll t=1,w1=ksm(2,K),w2=2;
	ll I=inv(2);
	ll pw=ksm(2,n),T=1;
	rep(m,1,min(K-1,n))
	{
		t=t*(w1-w2+mod)%mod,w2=w2*2%mod;
		T=T*(mod+1-pw)%mod; pw=pw*I%mod;
		(ans+=wtf[m]*t%mod*T%mod)%=mod;
	}
	printf("%lld\n",ans);
}

int main()
{
	file();
	wtf[0]=1; rep(i,1,sz-1) wtf[i]=wtf[i-1]*2%mod;
	rep(i,0,sz-1) wtf[i]=(mod+1-wtf[i])%mod;
	pre[0]=1; rep(i,1,sz-1) pre[i]=pre[i-1]*wtf[i]%mod;
	ll tmp; pre[sz-1]=inv(pre[sz-1]);
	drep(i,sz-1,1) tmp=wtf[i],wtf[i]=pre[i],pre[i-1]=pre[i]*tmp%mod;
	int T; read(T);
	while (T--) work();
	return 0;
}