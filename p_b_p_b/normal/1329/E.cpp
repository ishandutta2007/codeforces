#include<bits/stdc++.h>
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
	#define sz 404040
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

ll n,K; int m,T;
ll a[sz]; pll b[sz]; ll suf[sz];
ll ddiv(ll x,ll y){assert(x>0);return (x-1)/y+1;}

void work()
{
	read(n,m,K);
	ll x=0,y;
	rep(i,1,m) read(y),a[i]=y-x,x=y; a[++m]=n-x;
	ll mn=1e18,mx=0; rep(i,1,m) chkmin(mn,a[i]),chkmax(mx,a[i]);
	K+=m;
	ll L=-1,R=1e18;
	for (ll l=1,r=mn,mid;(mid=(l+r)>>1,l<=r);) if ([&](){ll res=0;rep(i,1,m) res+=a[i]/mid;return res;}()>=K) L=mid,l=mid+1; else r=mid-1;
	for (ll l=1,r=mx,mid;(mid=(l+r)>>1,l<=r);) if ([&](){ll res=0;rep(i,1,m) res+=ddiv(a[i],mid);return res;}()<=K) R=mid,r=mid-1; else l=mid+1;
	assert(L<=R&&L!=-1&&R<1e18);
	T=0; rep(i,1,m) { ll t1=ddiv(a[i],R),t2=a[i]/L; if (t1<=t2) continue; b[++T]=MP(a[i]/t1,ddiv(a[i],t2)); }
	sort(b+1,b+T+1); reverse(b+1,b+T+1);
	suf[T+1]=R; drep(i,T,1) suf[i]=max(suf[i+1],b[i].sec);
	ll ans=1e18;
	rep(i,0,T) chkmin(ans,suf[i+1]-(i?b[i].fir:L));
	printf("%lld\n",ans);
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}