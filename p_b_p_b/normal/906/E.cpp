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
	#define sz 1010101
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
char a[sz],b[sz],s[sz];

struct hh{int fr,w;hh(int F=0,int W=1e9){fr=F,w=W;}const bool operator < (const hh &x) const {return w<x.w;}}dp[sz],g[sz];

struct hhh{int s,delta,size;int ed(){return s+(size-1)*delta;}}P[2][sz];
int C[2];

void ins1(hhh *a,int &n,int p)
{
	if (!n) a[++n]=(hhh){p,(int)1e9,1};
	else if (p-a[n].ed()==a[n].delta) ++a[n].size;
	else a[n+1]=(hhh){p,p-a[n].ed(),1},++n;
}
void ins2(hhh *a,int &n,hhh x){if (a[n].delta==x.delta) a[n].size+=x.size; else a[++n]=x;}
void Trans(hhh *a,int n,hhh *b,int &m,char c)
{
	m=0;
	rep(i,1,n) if (s[a[i].s-1]==c) { ins1(b,m,a[i].s-1); if (a[i].size>1) ins2(b,m,(hhh){a[i].s+a[i].delta-1,a[i].delta,a[i].size-1}); }
//	printf("%d %d\n",n,m);
}

int main()
{
	file();
	cin>>(a+1)>>(b+1);n=strlen(a+1);
	rep(i,1,n) s[i*2-1]=a[i]; rep(i,1,n) s[i*2]=b[i];
	dp[0]=hh(0,0);
	for (int i=1,p=0,q=1;i<=n*2;i++,p^=1,q^=1)
	{
		Trans(P[p],C[p],P[q],C[q],s[i]);
		if (i!=1&&s[i]==s[i-1]) ins1(P[q],C[q],i-1);
		if (i&1) continue;
		if (s[i]==s[i-1]) dp[i]=(hh){i-2,dp[i-2].w};
		rep(j,1,C[q])
		{
			hhh cur=P[q][j];hh ret;
			if (cur.size==1) ret=(hh){cur.s-1,dp[cur.s-1].w+1};
			else ret=min(g[cur.s-cur.delta],(hh){cur.delta*(cur.size-1)+cur.s-1,dp[cur.delta*(cur.size-1)+cur.s-1].w+1});
			dp[i]=min(dp[i],ret);
			int pos=cur.s-cur.delta;
			if (pos>=0) g[pos]=ret;
		}
	}
	if (dp[n*2].w>n) return puts("-1"),0;
	cout<<dp[n*2].w<<'\n';
	for (int i=n*2;i;i=dp[i].fr) if (dp[i].fr!=i-2||s[i-1]!=s[i])printf("%d %d\n",(dp[i].fr>>1)+1,i>>1);
	return 0;
}