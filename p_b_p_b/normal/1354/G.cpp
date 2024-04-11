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
	#define sz 2333
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

int n,K;
int vis[sz];
int cmp(vector<int>a,vector<int>b)
{
	if (a[0]==b[0]) return 0;
	printf("? %d %d\n",(int)a.size(),(int)b.size());
	for (auto x:a) printf("%d ",x); puts("");
	for (auto x:b) printf("%d ",x); puts("");
	fflush(stdout);
	static char s[233];
	cin>>s;
	return s[0]=='F';
}

void work()
{
	read(n,K);
	rep(i,1,n) vis[i]=0;
	int x=rnd(1,n); vis[x]=1;
	rep(i,1,min(23,n-1))
	{
		int y; do y=rnd(1,n); while (vis[y]);
		vis[y]=1;
		if (cmp({y},{x})) x=y;
	}
	if (cmp({x},{1})) return printf("! 1\n"),fflush(stdout),void();
	int k=1,l=-1,r=-1;
	while (k+k<=n) { vector<int>a,b; rep(i,1,k+k) (i<=k?a:b).push_back(i); if (cmp(a,b)) { l=k+1,r=k+k; break; } k+=k; }
	if (l==-1) l=k+1,r=n;
	while (l<r)
	{
		int mid=(l+r)>>1;
		vector<int>a,b;
		rep(i,1,mid-l+1) a.push_back(i);
		rep(i,l,mid) b.push_back(i);
		if (cmp(a,b)) r=mid;
		else l=mid+1;
	}
	printf("! %d\n",l),fflush(stdout);
}

int main()
{
//	file();
	int T;read(T);
	while (T--) work();
	return 0;
}