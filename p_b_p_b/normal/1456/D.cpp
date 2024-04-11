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
	#define sz 5555
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
ll T[sz],X[sz];
ll tp[sz],mn[sz];

ll work(ll t,ll x1,ll x2){return t+abs(x1-x2);}
ll check(ll x1,ll x2,ll x3){if (x1>x2) swap(x1,x2); if (x3>=x1&&x3<=x2) return x2-x1; return x3<x1?x2-x3+x1-x3:x3-x1+x3-x2;}

int main()
{
	file();
	read(n); ++n; rep(i,2,n) read(T[i],X[i]); T[n+1]=9e9,X[n+1]=5e9;
	mn[1]=0; rep(i,2,n+1) mn[i]=1e10;
	rep(i,2,n+1)
	{
//		int t,x;
		ll &mn=::mn[i];
		if (tp[i-1]) chkmin(mn,work(T[i-2],X[i-2],X[i])); 
		chkmin(mn,work(::mn[i-1],X[i-1],X[i])); chkmax(mn,T[i-1]);
		int ok=0;
		drep(j,i-2,1)
		{
			if (j!=i-2&&work(T[j+1],X[j+1],X[j+2])>T[j+2]) break;
			if (j!=i-2) ok|=(check(X[j+1],X[j+2],X[i])<=T[j+2]-T[j+1]);
			ll w1=work(::mn[j],X[j],X[j+1]); if (tp[j]) chkmin(w1,work(T[j-1],X[j-1],X[j+1]));
			if (w1>T[j+1]) continue;
			if (ok) tp[i]=1;
			auto chk=[&](ll t,ll x){ ll w=work(t,x,X[i]); chkmax(w,T[j]); tp[i]|=work(w,X[i],X[j+1])<=T[j+1]; };
//			if (tp[j]) { ll w=work(T[j-1],X[j-1],X[i]); chkmax(w,T[j]); tp[i]|=work(w,X[i],X[j+1]) }
			if (tp[j]) chk(T[j-1],X[j-1]); chk(::mn[j],X[j]);
			chkmin(mn,work(T[i-1],X[i-1],X[i]));
		}
		if (mn>T[i]) mn=1e10;
	}
	if (mn[n+1]<8e9||tp[n+1]) puts("YES"); else puts("NO");
	return 0;
}