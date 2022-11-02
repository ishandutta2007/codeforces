// update 
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
	#define sz 2010101
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

int n,T,m[2];
int x[2][sz],X[sz],K;
int dp[2][sz],fr[2][sz];
map<int,int>vis[2];

int ans1[sz],c1;
int ans2[sz],c2;

int main()
{
	file();
	read(n,m[0],m[1],T);
	rep(i,1,m[0]) read(x[0][i]),vis[0][x[0][i]]=1,X[++K]=x[0][i],X[++K]=x[0][i]+1;
	rep(i,1,m[1]) read(x[1][i]),vis[1][x[1][i]]=1,X[++K]=x[1][i],X[++K]=x[1][i]+1;
	X[++K]=n+1; X[++K]=0;
	sort(X+1,X+K+1); K=unique(X+1,X+K+1)-X-1;
	fr[1][1]=1<<1|0;
	rep(i,2,K)
	{
		rep(k,0,1) dp[k][i]=-1e9;
		rep(k,0,1) 
		{
			int w=dp[k][i-1]+X[i]-X[i-1]-1;
			if (!vis[k][X[i]]) dp[k][i]=w+1,fr[k][i]=(i-1)<<1|k;
			else if (w>=T) dp[k][i]=w-T+1,fr[k][i]=(i-1)<<1|k;
		}
		rep(k,0,1) if (!vis[k][X[i]]&&chkmax(dp[k][i],min(dp[k^1][i],T))) fr[k][i]=i<<1|(k^1); 
	}
	if (dp[0][K]<0&&dp[1][K]<0) return puts("No"),0;
	int x=0,y=K; if (dp[x][y]<0) x^=1;
	while (x!=0||y!=1)
	{
		if ((fr[x][y]&1)!=x) ans1[++c1]=X[y];
		if (vis[x][X[y]]) ans2[++c2]=(X[y]-dp[x][y])<<1|x;
		int p=fr[x][y]; x=p&1,y=p>>1;
	}
	puts("Yes");
	printf("%d\n",c1);
	drep(i,c1,1) printf("%d%c",ans1[i]," \n"[i==1]);
	printf("%d\n",c2);
	drep(i,c2,1) printf("%d %d\n",ans2[i]>>1,(ans2[i]&1)+1);
	return 0;
}