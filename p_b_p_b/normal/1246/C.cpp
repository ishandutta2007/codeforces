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
	#define sz 2010
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

int n,m;
char s[sz][sz];

int d[sz][sz],r[sz][sz];
ll f[sz][sz],g[sz][sz];
ll addf[sz][sz],addg[sz][sz];

int main()
{
	file();
	read(n,m);
	rep(i,1,n) cin>>(s[i]+1);
	drep(i,n,1) rep(j,1,m) d[i][j]=(s[i][j]=='R')+d[i+1][j];
	rep(i,1,n) drep(j,m,1) r[i][j]=(s[i][j]=='R')+r[i][j+1];
	if (n==1) return puts(r[1][1]?"0":"1"),0;
	if (m==1) return puts(d[1][1]?"0":"1"),0;
	rep(j,2,m-r[1][1]) if (d[2][j]!=n-1) f[2][j]=1;
	rep(i,2,n-d[1][1]) if (r[i][2]!=m-1) g[i][2]=1;
	rep(i,2,n) rep(j,2,m)
	{
		(addg[i][j]+=addg[i-1][j])%=mod;(g[i][j]+=addg[i][j])%=mod;
		(addf[i][j]+=addf[i][j-1])%=mod;(f[i][j]+=addf[i][j])%=mod;
		if (d[i][j]!=n-i+1)
		{
			int dn=d[i][j];
			(addg[i][j+1]+=f[i][j])%=mod,(addg[n-dn+1][j+1]-=f[i][j])%=mod;
		}
		if (r[i][j]!=m-j+1)
		{
			int ri=r[i][j];
			(addf[i+1][j]+=g[i][j])%=mod,(addf[i+1][m-ri+1]-=g[i][j])%=mod;
		}
	}
	ll ans=0;
	rep(j,1,m) if (!r[n][j]) (ans+=g[n][j])%=mod;
	rep(i,1,n) if (!d[i][m]) (ans+=f[i][m])%=mod;
	(ans+=mod)%=mod;
	cout<<ans;
	return 0;
}