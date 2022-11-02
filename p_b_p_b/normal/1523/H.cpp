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
	#define sz 20202
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

const int M=30;
int n,Q;
int a[sz],r[sz];

pii st[sz][25]; int lg2[sz];
void init()
{
	rep(i,1,n) st[i][0]=MP(r[i],i);
	rep(i,1,20) rep(j,1,n-(1<<i)+1) st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	rep(i,2,n) lg2[i]=lg2[i>>1]+1;
}
int query(int l,int r){int len=lg2[r-l+1];pii p=max(st[l][len],st[r-(1<<len)+1][len]);return p.sec;}

int jmp[sz][25][M+2];

int main()
{
	file();
	read(n,Q);
	rep(i,1,n) read(a[i]),r[i]=min(n,i+a[i]);
	init();
	rep(i,1,n) rep(k,0,M) jmp[i][0][k]=min(n,i+a[i]+k);
	rep(j,1,20) rep(i,1,n) rep(k,0,M) rep(x,0,k) { int t=jmp[i][j-1][x]; t=query(i,t); chkmax(jmp[i][j][k],jmp[t][j-1][k-x]); }
	while (Q--)
	{
		int l,r,K; read(l,r,K);
		if (l==r) { puts("0"); continue; } if (l+a[l]+K>=r) { puts("1"); continue; }
		static int dp[M+2],tmp[M+2]; rep(i,0,M) dp[i]=l;
		int ans=0;
		drep(j,20,0)
		{
			rep(i,0,M) tmp[i]=dp[i];
			rep(i,0,M) { int t=query(l,dp[i]); rep(x,0,M-i) chkmax(tmp[i+x],jmp[t][j][x]); }
			int flg=0; rep(i,0,K) flg|=(tmp[i]>=r);
			if (flg) continue;
			rep(i,0,M) dp[i]=tmp[i]; ans+=1<<j;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}