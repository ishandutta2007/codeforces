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
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	template<typename T>inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	template<typename T>inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	void file()
	{
		#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
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
ll a,b;

ll solve(ll x,ll y)
{
	if (x==a&&y==b) return 0;
	ll ret=min(x,y)-max(a,b);
	if (a!=b) ++ret;
	a=x,b=y;
	return max(ret,0ll);
//	ll ret;
//	if (x==a)
//	{
//		 if (b<a&&y>=a) ret=1;
//		 else ret=0;
//	}
//	else if (y==b){
//		if (a<b&&x>=b) ret=1;
//		else ret=0;
//	}
//	else if (a==b)
//	{
//		ret=min(x,y)-a;
//	}
//	else if (x==y)
//	{
//		ret=x-max(a,b);
//		if (a!=b) ++ret;
//	}
//	else if (a>b)
//	{
//		if (x>y)
//		{
//			if (y>=b)
//		}
//	}
}

int main()
{
	file();
	read(n);
	ll x,y;
	ll ans=0;
	while (n--) read(x,y),ans+=solve(x,y);
	cout<<ans+1;
}