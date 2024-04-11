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

const ll MX1=1e9,MX2=1e18;
//const ll MX1=1e2,MX2=1e4;
ll lim1,lim2;

int is[sz],pri[sz],c;
int p[sz],cc;

int query(ll x){printf("? %lld\n",x);fflush(stdout);read(x);return x;}
ll calc(int p1,int p2)
{
	ll P1=1,P2=1;
	while (P1*p1<=MX1) P1*=p1;
	while (P2*p2<=MX1) P2*=p2;
	ll q=query(P1*P2);
	int c1=0,c2=0;
	while (q%p1==0) ++c1,q/=p1;
	while (q%p2==0) ++c2,q/=p2;
	return (c1+1)*(c2+1);
}
ll getans()
{
	p[cc+1]=MX1+1;
	ll ans=1;
	rep(j,1,(cc+1)>>1) ans=ans*calc(p[j*2-1],p[j*2]);
	return ans;
}
void work()
{
	cc=0;
	ll cur=1;int lst=0;
	rep(i,1,c)
	{
		if (MX2/pri[i]>=cur) cur*=pri[i];
		else
		{
			ll q=query(cur);
			rep(j,lst+1,i) if (q%pri[j]==0) p[++cc]=pri[j];
			lst=i,cur=1;
			if (pri[i]>=lim2) return printf("! %lld\n",getans()*2),void();
			if (pri[i]>lim1)
			{
				if (!cc) return puts("! 8"),fflush(stdout),void();
				if (cc>=2) return printf("! %lld\n",getans()*2),void();
			}
		}
	}
} 

int main()
{
//	file();
	rep(i,2,sz-1) is[i]=1;
	rep(i,2,sz-1) if (is[i]) for (int j=i+i;j<sz;j+=i) is[j]=0;
	rep(i,2,sz-1) if (is[i]) pri[++c]=i;
	while (lim1*lim1*lim1*6<=MX1) ++lim1;
	while (lim2*lim2*lim2*2<=MX1) ++lim2;
	int T;read(T);
	while (T--) work();
	return 0;
}