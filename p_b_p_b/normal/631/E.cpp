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
	#define sz 220020 
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
		#ifndef ONLINE_JUDGE
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
ll s[sz],sum[sz];
ll ans;

int st[sz],top;
db K1(int i,int j){return 1.0*(sum[j-1]-sum[i-1])/(j-i);}
db K2(int i,int j){return 1.0*(sum[j]-sum[i])/(j-i);}

ll calc(int i,int j,int type){if (type) return sum[i-1]-sum[j-1]-s[i]*(i-j); return s[i]*(j-i)-sum[j]+sum[i];}
ll calc(int p,int type)
{
	int l=1,r=top; 
	while (l<=r)
	{
		if (r-l<=3)
		{
			ll ret=0;
			rep(i,l,r) chkmax(ret,calc(p,st[i],type));
			return ret;
		}
		int mid=(l+r)>>1;
		if (calc(p,st[mid],type)>calc(p,st[mid+1],type)) r=mid;
		else l=mid;
	}
	assert(0);
	return -1;
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(s[i]),ans+=s[i]*i,sum[i]=sum[i-1]+s[i];
	st[top=1]=1;
	ll mx=0;
	rep(i,2,n)
	{
		chkmax(mx,calc(i,1));
		while (top>1&&K1(st[top],st[top-1])>K1(st[top-1],i)) --top;
		st[++top]=i;  
	}
	st[top=1]=n;
	drep(i,n-1,1)
	{
		chkmax(mx,calc(i,0));
		while (top>1&&K2(st[top],st[top-1])<K2(st[top-1],i)) --top;
		st[++top]=i;
	}
	cout<<ans+mx;
	return 0;
}