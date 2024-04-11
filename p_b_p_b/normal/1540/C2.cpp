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
	#define sz 111
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

int n;
int c[sz],b[sz],B[sz];

ll pre[sz][sz*sz],pr;
void init()
{
	pre[0][0]=1;
	rep(i,0,n-1) rep(k,0,100*i) rep(t,0,c[i+1]) (pre[i+1][k+t]+=pre[i][k])%=mod;
	pr=1; rep(i,1,n) pr=pr*(c[i]+1)%mod;
}

ll dp[sz][sz*sz];
ll work(int x)
{
	static int lim[sz];
	rep(i,1,n) lim[i]=i*x+B[i];
	int p=1; while (p<=n&&lim[p]<=0) ++p; if (p>n) return pr;
	rep(i,p,n) rep(j,0,i*100) dp[i][j]=0; rep(i,lim[p],p*100) dp[p][i]=pre[p][i];
	rep(i,p,n-1)
	{
		rep(k,lim[i],i*100) { int l=k,r=k+c[i+1]; if (r<lim[i+1]) continue; chkmax(l,lim[i+1]); dp[i+1][l]+=dp[i][k],dp[i+1][r+1]+=mod-dp[i][k]; }
		dp[i+1][lim[i+1]]%=mod;
		rep(k,lim[i+1]+1,(i+1)*100) (dp[i+1][k]+=dp[i+1][k-1])%=mod;
	}
	ll res=0; rep(i,lim[n],n*100) res+=dp[n][i]; return res%mod;
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(c[i]);
	rep(i,2,n) read(b[i]),B[i]=b[i]+B[i-1]; rep(i,2,n) B[i]+=B[i-1];
	init();
	int Q; read(Q); map<int,ll>vis;
	while (Q--)
	{
		int x; read(x);
		if (x>100) { puts("0"); continue; }
		if (x<-6000) { printf("%lld\n",pr); continue; }
		if (vis.count(x)) { printf("%lld\n",vis[x]); continue; }
		ll ans=work(x); printf("%lld\n",vis[x]=ans);
	}
	return 0;
}