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
	#define sz 55
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

ll fac[sz],_fac[sz];
void init(){_fac[0]=fac[0]=1;rep(i,1,sz-1) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);}
ll CC(int n,int m){return n>=m&&m>=0?fac[n]*_fac[m]%mod*_fac[n-m]%mod:0;}

int n,T;
vector<int>A,B,C;
ll dp1[sz][sz*sz],dp2[sz][sz*sz],dp3[sz][sz*sz],dp4[sz][sz*sz];
int m1,m2,m3;
void work(vector<int>a,ll f[sz][sz*sz],int &m)
{
	static ll dp[sz*sz][sz];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1; int n=a.size();
	for (auto x:a)
	{
		m+=x;
		drep(j,m,x) drep(i,n,1) (dp[j][i]+=dp[j-x][i-1])%=mod;
	}
	f[0][0]=1;
	rep(j,1,m) rep(i,1,n) rep(k,1,i) (f[k][j]+=dp[j][i]*fac[i]%mod*(((i-k)&1)?mod-1:1)%mod*CC(i-1,i-k)%mod*_fac[k]%mod)%=mod;
}

int main()
{
	file();
	init();
	read(n,T);
	int x,y;
	rep(i,1,n) read(x,y),(y==1?A:(y==2?B:C)).push_back(x);
	if (A.size()>B.size()) swap(A,B); if (A.size()>C.size()) swap(A,C); if (B.size()>C.size()) swap(B,C);
	work(A,dp1,m1),work(B,dp2,m2),work(C,dp3,m3);
	int n1=A.size(),n2=B.size();
	rep(i,0,n1) rep(j,0,n2) rep(x,0,m1) rep(y,0,m2) (dp4[i+j][x+y]+=dp1[i][x]*dp2[j][y]%mod)%=mod;
	ll ans=0;
	rep(i,0,n1+n2) rep(j,0,(int)C.size()) rep(k,0,T) (ans+=fac[i+j]*dp4[i][k]%mod*dp3[j][T-k]%mod)%=mod;
	cout<<ans;
	return 0;
}