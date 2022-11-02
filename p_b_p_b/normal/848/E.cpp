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
	#define sz 2005000
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

int n;

ll dp[4][4],tmp[4][4];
ll g[sz],f[sz][2];
void DP()
{
	static int to[4];
	rep(i,1,n-1)
	{
		rep(k,0,3) rep(s,0,3)
		{
			ll w=tmp[k][s];
			if (!w) continue;
			
			rep(p,0,3) to[p]=0;
			if (s==0) to[1]++;
			else if (s==1) to[3]++;
			else if (s==2) to[0]++,to[3]++;
			else to[2]++;
			rep(t,0,3) if ((t&k)==k) rep(p,0,3) (dp[t][p]+=w*to[p]%mod)%=mod;
			
			if (k!=3) continue;
			if (!(s>>1&1)) continue;
			(dp[0][(s^2)<<1|1]+=w)%=mod; (f[i+1][s&1]+=w)%=mod;
		}
		rep(k,0,3) rep(s,0,3) tmp[k][s]=dp[k][s],dp[k][s]=0;
	}
	memcpy(dp,tmp,sizeof(dp));
	g[0]=g[2]=1;rep(i,2,n/2) g[i*2]=(g[(i-1)*2]+g[(i-2)*2])%mod;
}

int main()
{
	file();
	read(n);
	ll ans=0;
	memset(dp,0,sizeof(dp)),memset(tmp,0,sizeof(tmp)),memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	tmp[0][3]=1;
	DP();f[1][1]=1;
	rep(i,1,n-1)
	{
		ll w=0;
		(w+=f[n-i][1]*g[i]%mod)%=mod;
		(w+=f[n-i][0]*g[i-1]%mod)%=mod;
		(ans+=w*(i+1)%mod*i%mod*i%mod)%=mod;
	}
	memset(dp,0,sizeof(dp)),memset(tmp,0,sizeof(tmp)),memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	rep(i,0,3) dp[i][3]=1;
	DP();f[1][0]=1;
	rep(i,1,n-1)
	{
		ll w=0;
		(w+=f[n-i][1]*g[i-1]%mod)%=mod;
		(w+=f[n-i][0]*(i==1?0ll:g[i-2])%mod)%=mod;
		(ans+=w*(i+1)%mod*i%mod*i%mod)%=mod;
	}
	cout<<ans;
	return 0;
}