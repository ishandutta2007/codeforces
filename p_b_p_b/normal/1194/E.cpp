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
	#define sz 5050
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

int N,n,m;
struct hh1{int y,x1,x2;const bool operator < (const hh1 &x) const {return y<x.y;}}a[sz];
struct hh2{int x,y1,y2;const bool operator < (const hh2 &x) const {return y2>x.y2;}}b[sz];
#define MX 10101

int tr[MX];
void add(int x,int w){while (x<MX) tr[x]+=w,x+=(x&(-x));}
ll query(int x){ll ret=0;while (x) ret+=tr[x],x-=(x&(-x));return ret;}

int main()
{
	file();
	read(N);
	rep(i,1,N)
	{
		int x1,y1,x2,y2;read(x1,y1,x2,y2);x1+=5e3+1,x2+=5e3+1,y1+=5e3+1,y2+=5e3+1;
		if (x1==x2) b[++m]=(hh2){x1,min(y1,y2),max(y1,y2)};
		else a[++n]=(hh1){y1,min(x1,x2),max(x1,x2)};
	}
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	ll ans=0;
	rep(i,1,n)
	{
		rep(j,1,m) if (b[j].y1<=a[i].y) add(b[j].x,1);
		int r=m;
		rep(j,i+1,n) if (a[i].y!=a[j].y)
		{
			int L=max(a[i].x1,a[j].x1),R=min(a[i].x2,a[j].x2);
			if (L>=R) continue;
			while (r&&b[r].y2<a[j].y)
			{
				if (b[r].y1<=a[i].y) add(b[r].x,-1);
				--r;
			}
			if (!r) break;
			ll cur=query(R)-query(L-1);
			ans+=cur*(cur-1)/2;
		}
		rep(j,0,MX) tr[j]=0; 
	}
	cout<<ans;
	return 0;
}