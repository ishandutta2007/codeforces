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

int n=2,m=2;
struct hh{int x1,y1,x2,y2;}ans[sz];int s;
ll T;
int p[sz],cc;

void update()
{
	if (n!=4) ans[++s]=(hh){n-4,m+1,n-3,m+1};
	ans[++s]=(hh){n-2,m+2,n-1,m+2};
	ans[++s]=(hh){n-2,m,n-2,m+1};
	ans[++s]=(hh){n-1,m,n-1,m+1};
	if (m!=4) ans[++s]=(hh){n+1,m-4,n+1,m-3};
	ans[++s]=(hh){n+2,m-2,n+2,m-1};
	ans[++s]=(hh){n,m-2,n+1,m-2};
	ans[++s]=(hh){n,m-1,n+1,m-1}; 
}
void work(int x)
{
	ans[++s]=(hh){n-3,m-1,n-2,m-1};
	if (x<3) ans[++s]=(hh){n-1,m-3,n-1,m-2}; else x-=3;
	if (x<2) ans[++s]=(hh){n-3,m,n-2,m};
	if (x<1) ans[++s]=(hh){n,m-3,n,m-2};
}

int main()
{
	file();
	ans[++s]=(hh){1,2,2,2},ans[++s]=(hh){2,1,2,2};
	read(T);
	while (T) p[++cc]=T%6,T/=6;reverse(p+1,p+cc+1);
	rep(i,1,cc) n+=2,m+=2,(i==cc?void():update()),work(p[i]);
	printf("%d %d\n%d\n",n,m,s);
	rep(i,1,s) printf("%d %d %d %d\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2);
	return 0;
}