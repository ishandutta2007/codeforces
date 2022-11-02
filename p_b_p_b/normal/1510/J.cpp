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
	#define sz 101010
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

int n,m;
char mp[sz];
int a[sz],pos[sz],w[sz];
vector<int>V[sz];

void check(int len)
{
	if (len<0||len>n) return;
	rep(i,1,m) V[i].clear();
	rep(i,1,m)
	{
		int l=len-(n-a[i]); w[i]=l; if (l<0) return; if (mp[1]=='_'&&(i==1||i==m)) ++l;// if (a[i]<=3) continue;
		if (l==2) return;
		int c=(l-1)/2;
		if (l%2==1) rep(k,1,c) V[i].push_back(1);
		else { rep(k,1,c-1) V[i].push_back(1); V[i].push_back(2); }
	}
	static int S[sz],K,vis[sz],pre[sz],suf[sz]; K=0;
	rep(i,0,m)
	{
		for (auto x:V[i]) S[++K]=x;
		if (mp[1]=='_'&&(i==0||i==m)) continue;
		if (pos[i+1]-pos[i]-w[i]>0) S[++K]=pos[i+1]-pos[i]-w[i];
	}
	rep(i,1,K) if (S[i]<0) return;
	pre[1]=S[1]; rep(i,2,K) pre[i]=pre[i-1]+1+S[i];
	suf[K]=S[K]; drep(i,K-1,1) suf[i]=suf[i+1]+1+S[i]; suf[K+1]=0;
	rep(i,0,n+1) vis[i]=0;
	rep(i,0,K) ++vis[pre[i]+1],--vis[n-suf[i+1]+1];
	rep(i,1,n) vis[i]+=vis[i-1];
	rep(i,1,n) if ((!!vis[i])!=(mp[i]=='_')) return;
//	puts("OK");
	printf("%d\n",K);
	rep(i,1,K) printf("%d ",S[i]);
	exit(0);
}

int main()
{
	file();
	cin>>(mp+1); n=strlen(mp+1);
	int mx=0,cc=0;
	for (int l=1,r;l<=n;l=r+1)
	{
		if (mp[l]=='#') r=l,++cc;
		else
		{
			for (r=l;r<=n&&mp[r]!='#';++r); --r;
			chkmax(mx,l+n-r);
			a[++m]=r-l+1; pos[m]=l-1;
		}
	}
	if (mp[1]!=mp[n]) return puts("-1"),0;
	pos[m+1]=n,pos[0]=0;
//	if (cc==n||!cc) return puts("OK"),0;
	if (cc==n) return printf("1\n%d\n",n),0;
	if (!cc) return puts("0"),0;
	rep(i,mx-2,mx+3) check(i);
	puts("-1");
	return 0;
}