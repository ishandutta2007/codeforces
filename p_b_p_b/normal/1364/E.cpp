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
		#ifndef ONLINE_JUDGE
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
int ans[sz];
int p[sz],vis[sz],cc;
int vvis[sz][sz];
int query(int x,int y){if (x>y) swap(x,y);if (vvis[x][y]) return vvis[x][y];int z;printf("? %d %d\n",x,y);fflush(stdout);read(z);return vvis[x][y]=z;}
int Query(int x,int c)
{
	static int vis[sz];
	rep(i,1,n) vis[i]=0; vis[x]=1;
	int res=(1<<12)-1;
	rep(_,1,min(c,n-1))
	{
		int y;
		for (;vis[y=rnd(1,n)];);
		res&=query(x,y);
		vis[y]=1;
	}
	return res;
}

int main()
{
//	file();
	read(n);
	int a,b;
	while (233)
	{
		int x;
		for (;vis[x=rnd(1,n)];);
		ans[x]=Query(x,11-(cc>10)-(cc>18));vis[x]=1;p[++cc]=x;
		int flg=0;
		rep(i,1,cc-1) if (!(ans[x]&ans[p[i]])) { flg=1; a=x,b=p[i]; }
		if (flg) break;
	}
	rep(i,1,n) if (i!=a&&i!=b) ans[i]=((~ans[a])&query(a,i))|((~ans[b])&query(b,i));
	printf("! "); rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}