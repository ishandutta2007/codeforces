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
	#define sz 1555
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
		cout<<(clock()-__t)/1000.0<<'\n';
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	ll mul(ll x,ll y){ull s=1.0*x/mod*y;ll res=1ull*x*y-s*mod;return (res%mod+mod)%mod;}
}
using namespace my_std;
 
int n,m;
int cnt[sz],pre[sz],tot[sz],a[sz][44];
ll _fac[sz],fac[sz];
ll tr[44][44];

void init()
{
	static int p[sz],vis[sz];
	rep(i,1,n) read(p[i]);
	rep(i,1,n) if (!vis[i]) { vis[i]=1; int len=1; for (int x=p[i];x!=i;x=p[x]) vis[x]=1,++len; ++cnt[len]; }
	m=1; rep(i,1,n) m*=(cnt[i]+1);
	pre[1]=1; rep(i,2,n+1) pre[i]=pre[i-1]*(cnt[i-1]+1);
	rep(i,0,m-1) { int x=i; rep(k,1,n) tot[i]+=(a[i][k]=x%(cnt[k]+1))*k,x/=(cnt[k]+1); }
	_fac[0]=fac[0]=1; rep(i,1,sz-1) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);
	rep(i,0,n) rep(k,0,i) (tr[i][1]+=fac[i]*_fac[i-k]%mod*fac[n-k-1]%mod)%=mod;
	rep(i,0,n) rep(j,0,n) tr[i][j]=ksm(tr[i][1],j);
}
 
ll dp[sz][44][44];
 
int main()
{
	file();
	read(n); init();
	dp[0][0][n+1]=mod-1;
	ll ans=0;
	auto Go=[&](int s,int i,int j,ll w,int tp)
	{
		int c=cnt[j]-s/pre[j]%(cnt[j]+1);
		rep(l,tp,c) (dp[s+l*pre[j]][i][j+1]+=w*tr[i][l*j]%mod*_fac[l]%mod)%=mod;
	};
	rep(s,0,m-1) rep(i,0,tot[s]) rep(j,1,n+1) if (dp[s][i][j])
	{
		ll w=dp[s][i][j];
		if (j!=n+1) { Go(s,i,j,w,0); continue; }
		w=w*(mod-1)%mod;
		if (s==m-1) { (ans+=w)%=mod; break; }
		rep(k,1,n) Go(s,tot[s],k,w,1);
	}
	rep(i,1,n) ans=ans*fac[cnt[i]]%mod*((cnt[i]&1)?mod-1:1)%mod;
	cout<<ans;
	return 0;
}