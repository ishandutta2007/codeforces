#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
	using namespace std;
	#define pll pair<ll,ll>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
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

ll n,K;
map<ll,map<ll,ll>>dp;
map<ll,int>vis;

void DP(ll n)
{
	if (vis[n]) return;
	if (!n) return; 
	if (n==1) return dp[1][0]=1,void();
	vis[n]=1;
	--n;ll L=n/2,R=n-L;++n;
	dp[n][L]=1;
	DP(L),DP(R);
	for (auto x:dp[L]) dp[n][x.fir]+=x.sec;
	for (auto x:dp[R]) dp[n][x.fir]+=x.sec;
}
ll work(ll n,ll K)
{
	if (K==1) return (n-1)/2+1;
	--K;
	ll L=(n-1)/2,R=n-1-L;
	vector<pll>V1,V2;
	for (auto x:dp[L]) V1.push_back(x);
	for (auto x:dp[R]) V2.push_back(x);
	reverse(V1.begin(),V1.end()),reverse(V2.begin(),V2.end());
	int p=0,q=0;ll c1=0,c2=0;
	while (233)
	{
		pll cur;int flg;
		if (p==(int)V1.size()) flg=1,cur=V2[q++];
		else if (q==(int)V2.size()) flg=0,cur=V1[p++];
		else if (V1[p].fir>=V2[q].fir) flg=0,cur=V1[p++];
		else flg=1,cur=V2[q++];
		if (cur.sec<K) (flg?c2:c1)+=cur.sec,K-=cur.sec;
		else if (!flg) return work(L,c1+K);
		else return work(R,c2+K)+L+1;
	}
}

int main()
{
	file();
	read(n,K);
	if (K==1) return printf("1"),0;
	if (K==2) return printf("%lld",n),0;
	n-=2,K-=2;
	DP(n);
	ll ans=work(n,K)+1;
	printf("%lld\n",ans);
	return 0;
}