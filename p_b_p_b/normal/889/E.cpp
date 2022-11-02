#include<bits/stdc++.h>
clock_t __t=clock();
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
	#define sz 222222
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
		cout<<(clock()-__t)/1000.0<<'\n';
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	ll mul(ll x,ll y){ull s=1.0*x/mod*y;ll res=1ull*x*y-s*mod;return (res%mod+mod)%mod;}
}
using namespace my_std;

int n;
ll a[sz];
map<ll,ll>dp;

int main()
{
	file();
	read(n);
	rep(i,1,n) read(a[i]);
	dp[-1]=2e18,dp[a[1]-1]=0; ll lst=a[1];
	auto add=[&](ll p,ll w)
	{
		auto it=dp.lower_bound(p); if (it!=dp.end()&&it->sec>=w) return;
		while (prev(it)->sec<=w) dp.erase(prev(it));
		dp[p]=w; 
	};
	rep(i,2,n) if (a[i]<lst)
	{
		vector<pll>V; ll mx=0;
		for (auto it=dp.end();it!=dp.begin();dp.erase(prev(it))) { V.push_back(*prev(it)); if (V.back().fir<a[i]) break; }
		rep(k,0,(int)V.size()-2)
		{
			ll l=V[k+1].fir+1,r=V[k].fir,w=V[k].sec;
			add(r%a[i],w+(i-1)*(r-r%a[i]));
			if (l<=r-r%a[i]-1) l=r-r%a[i]-1,chkmax(mx,w+(i-1)*(l-a[i]+1));
		}
		add(a[i]-1,mx); lst=a[i];
//		ll l=-2;
//		for (auto p:dp) printf("(%lld,%lld,%lld) ",l+1,p.fir,p.sec),l=p.fir; puts("");
	}
	ll ans=0; for (auto p:dp) if (p.fir!=-1) chkmax(ans,p.sec+n*p.fir);
	cout<<ans;
	return 0;
}