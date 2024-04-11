#include<bits/stdc++.h>
clock_t __t=clock();
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
	#define sz 10010100
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
		cout<<(clock()-__t)/1000.0<<'\n';
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

const int MX=1e7;

int pri[5000000],cc,to[sz];short mu[sz];
bool npri[sz];
void init()
{
	mu[1]=1;
	rep(i,2,sz-1)
	{
		if (!npri[i]) pri[++cc]=i,mu[i]=-1,to[i]=i;
		rep(j,1,cc) if (i*pri[j]<sz)
		{
			int x=i*pri[j];
			npri[x]=1;
			if (i%pri[j]==0) { to[x]=to[i]; break; }
			mu[x]=-mu[i];to[x]=to[i]*pri[j];
		} else break;
	}
}

int n;
int cnt[sz];

int s[sz],s1[sz],s2[sz];
ll pw2[505005];

int main()
{
	file();
	read(n);
	int x;
	rep(i,1,n) read(x),++cnt[x];
	init();
	chktime();
	pw2[0]=1;rep(i,1,5e5) pw2[i]=pw2[i-1]*2%mod;
	drep(i,MX,1)
	{
		ll cur=0;
		for (register int j=1;j*i<=MX;++j) cur-=s1[i*j],s[i]+=cnt[i*j];
		s1[i]=(pw2[s[i]]-1+mod+cur%mod)%mod;
	}
	chktime();
	rep(i,1,MX) if (mu[i]) for (register int j=1;j*i<=MX;++j) if (mu[i*j]) s2[i*j]+=mu[i]*s[i];
	chktime();
	rep(i,1,MX) s2[i]=s2[to[i]];
	ll ans=0;
	rep(i,2,MX) (ans+=1ll*s1[i]*s2[i]%mod)%=mod;
	chktime();
	cout<<ans;
	return 0;
}