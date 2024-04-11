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
	#define sz 233
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

struct Point
{
	ll x,y;
	Point(ll X=0,ll Y=0){x=X,y=Y;}
	const Point operator + (const Point &a) const {return Point(x+a.x,y+a.y);}
	const Point operator - (const Point &a) const {return Point(x-a.x,y-a.y);} 
};
typedef Point Vector;
ll Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
ll Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
bool cmp1(const Point &a,const Point &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int dcmp(db x){return fabs(x)<1e-9?0:(x>0?1:-1);}
db ATAN2[sz][sz];
//bool cmp2(const Vector &a,const Vector &b){return dcmp(atan2(-1.0*a.x,1.0*a.y)-atan2(-1.0*b.x,1.0*b.y))<0;}

int n,K;
Point p[sz];
bitset<sz>L[sz][sz],b;
bool ok[sz][sz][sz];

ll dp[sz][sz];
struct hh{int i,j;const bool operator < (const hh &a) const {return dcmp(ATAN2[i][j]-ATAN2[a.i][a.j])<0;}}tr[sz*sz<<1];

void trans(int i,int x,int y)
{
	ll w=Cross(p[x]-p[i],p[y]-p[i]); if (w<0) w=-w;
	rep(k,1,K) chkmax(dp[y][k+1],dp[x][k]+w);
}

int main()
{
	file();
	read(n,K);
	int x,y;
	rep(i,1,n) read(x,y),p[i]=Point(x,y);
	sort(p+1,p+n+1,cmp1);
	rep(i,1,n) rep(j,1,n) if (i!=j) rep(k,1,n) if (k!=i&&k!=j&&Cross(p[k]-p[i],p[j]-p[i])<0) L[i][j][k]=1;
	rep(i,1,n) rep(j,i+1,n) rep(k,j+1,n)
	{
		b.reset();b=~b;
		b&=(L[i][j][k]?L[i][j]:L[j][i]);
		b&=(L[j][k][i]?L[j][k]:L[k][j]);
		b&=(L[k][i][j]?L[k][i]:L[i][k]);
		if (!b.count()) ok[i][j][k]=ok[i][k][j]=ok[j][i][k]=ok[j][k][i]=ok[k][i][j]=ok[k][j][i]=1;
	}
	rep(i,1,n) rep(j,1,n) if (i!=j) { Vector a=p[j]-p[i]; ATAN2[i][j]=atan2(-a.x,a.y); }
	ll ans=0;
	rep(i,1,n)
	{
		rep(j,1,n) rep(k,1,K+1) dp[j][k]=-1e18;
		dp[i][1]=0;
		int c=0;
		rep(j,i,n) rep(k,i,n) if (j!=k&&(j==i||k==i||ok[i][j][k])&&(j==i||k==i||(hh){j,k}<(hh){k,i})) tr[++c]=(hh){j,k};
		sort(tr+1,tr+c+1);
		rep(j,1,c) trans(i,tr[j].i,tr[j].j);
		if (tr[1].j==i&&p[tr[1].i].y>p[i].y) trans(i,tr[1].i,tr[1].j);
		chkmax(ans,dp[i][K+1]);
	}
	printf("%.2lf",ans*0.5);
	return 0;
}