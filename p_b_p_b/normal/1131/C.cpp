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
	#define sz 233
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
ll a[sz];
ll Ans[sz];
ll cur[sz];
bool vis[sz];

bool judge(ll w)
{
	int p=1,c=1;
	cur[1]=a[1];
	rep(i,2,n) vis[i]=0;vis[1]=1;
	while (233)
	{
		int pp=p;
		while (p<n&&a[p+1]-cur[c]<=w) ++p;
		if (p==pp) return 0;
		vis[p]=1;cur[++c]=a[p];
		if (p==n)
		{
			drep(i,n,1) if (!vis[i])
			{
				if (cur[c]-a[i]>w) return 0;
				cur[++c]=a[i];
			}
			if (cur[n]-cur[1]>w) return 0;
			rep(i,1,n) Ans[i]=cur[i];
			return 1;
		}
	}
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(a[i]);
	sort(a+1,a+n+1);
//	if (n&1)
//	{
//		for (int i=1;i<=n;i+=2) printf("%d ",a[i]);
//		for (int i=n-1;i>0;i-=2) printf("%d ",a[i]);
//		return 0;
//	}
	ll l=0,r=1e12;
	while (l<=r)
	{
		ll mid=(l+r)>>1;
		if (judge(mid)) r=mid-1;
		else l=mid+1;
	}
	rep(i,1,n) printf("%I64d ",Ans[i]);
}