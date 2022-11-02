#include<bits/stdc++.h>
clock_t __t=clock();
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
	#define sz 23333
	typedef long long ll;
	typedef unsigned int uint;
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
		cout<<(clock()-__t)/1000.0<<'\n';
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

int n,q,p;
uint inv[sz];

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (!b) return x=1,y=0,void();
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
uint Inv(int a){ll x,y;exgcd(a,1ll<<32,x,y);return uint(x);}

struct hh
{
	uint w;int k;
	hh(uint x=0,int y=0){w=x,k=y;}
	const hh operator * (const hh &x) const {return hh(w*x.w,k+x.k);}
	const hh operator / (const hh &x) const {return hh(w*inv[x.w],k-x.k);}
	const uint val() const {return k>=32?0:w<<k;}
};
hh trans(int x){int k=0;while (x%2==0&&x) ++k,x>>=1;return hh(x,k);}
hh S[sz],T[sz],C[sz];

int main()
{
	file();
	rep(i,1,sz-1) if (i&1) inv[i]=Inv(i);
	read(n,p,q);chkmin(p,n-1);
	uint ans=0;
	rep(i,0,p+1) S[i]=trans(i),T[i]=trans(n-i);
	C[0]=hh(1,0);rep(i,1,p) C[i]=C[i-1]*T[i-1]/S[i];
	rep(i,1,q)
	{
		uint cur=0;hh x=hh(1,0),z=trans(i);
		rep(l,0,p)
		{
			cur+=(x*C[l]).val();
			x=x*z;
			if (x.k>31) break;
		}
		ans^=cur*i;
	}
	cout<<ans;
	return 0;
}