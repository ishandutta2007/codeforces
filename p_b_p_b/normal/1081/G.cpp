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
	#define sz 233333
	typedef long long ll;
	typedef double db;
	ll mod;
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
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,K;
int s1,s2,t1,t2;

ll sum[sz];
ll f(int n,int m)
{
	ll ans=1ll*n*m%mod;
	rep(i,1,n) (ans+=mod-2*(sum[i+m]-sum[i])%mod)%=mod;
	return ans*inv(2)%mod;
}

int main()
{
	file();
	read(n,K,mod);--K;
	rep(i,1,sz-1) sum[i]=(sum[i-1]+inv(i))%mod;
	s1=n,t1=1;
	while (K--)
	{
		if (!t2) 
		{
			if (s1&1) t2=t1,s2=s1>>1,s1-=s2;
			else s1>>=1,t1*=2;
		}
		else
		{
			if (s1&1) s2>>=1,t2=t2*2+t1,s1=s2+1;
			else s1>>=1,t1=t1*2+t2,s2>>=1;
		}
		if (s2==0) t2=0;
	}
	ll ans=1ll*t1*(1ll*s1*(s1-1)/2%mod)%mod+1ll*t2*(1ll*s2*(s2-1)/2%mod)%mod;ans=ans*inv(2)%mod;
	(ans+=(1ll*t1*(t1-1)/2%mod)*f(s1,s1))%=mod;
	(ans+=(1ll*t2*(t2-1)/2%mod)*f(s2,s2))%=mod;
	(ans+=1ll*t1*t2%mod*f(s1,s2)%mod)%=mod;
	cout<<ans;
	return 0;
}