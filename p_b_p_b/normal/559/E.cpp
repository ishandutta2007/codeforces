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
	#define sz 500 
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

int n;
pii a[sz];
int p[sz],c;
int P[sz],L[sz],R[sz];
int id(int x){return lower_bound(p+1,p+c+1,x)-p;}

int dp[sz][sz];

int main()
{
	file();
	read(n);
	rep(i,1,n) read(a[i].fir,a[i].sec);
	sort(a+1,a+n+1);
	rep(i,1,n) p[++c]=P[i]=a[i].fir,p[++c]=L[i]=a[i].fir-a[i].sec,p[++c]=R[i]=a[i].fir+a[i].sec;//,p[++c]=P[i]-1,p[++c]=L[i]-1;
	sort(p+1,p+c+1);c=unique(p+1,p+c+1)-p-1;
//	rep(i,1,c) printf("%d ",p[i]); puts("");
//	rep(i,1,n) P[i]=id(P[i]),L[i]=id(L[i]),R[i]=id(R[i]);
	rep(i,1,n)
	{
		rep(j,1,c) dp[i][j]=dp[i-1][j];
		rep(j,1,c) if (p[j]>=P[i]) chkmax(dp[i][j],dp[i-1][id(P[i])]+min(a[i].sec,p[j]-P[i]));
//		if (i==3) rep(i,1,c) cout<<dp[3][i]<<' ';puts("");
		int k=i;while (k&&P[k]>=L[i]) --k;
		int mx[2]={0,0};
		rep(j,k+1,i-1) if (!mx[0]||R[j]>R[mx[0]]) mx[1]=mx[0],mx[0]=j; else if (!mx[1]||R[j]>R[mx[1]]) mx[1]=j;
		int mn[2]={0,0};
		rep(j,k+1,i-1) if (!mn[0]||L[j]<L[mn[0]]) mn[1]=mn[0],mn[0]=j; else if (!mn[1]||L[j]<L[mn[1]]) mn[1]=j;
//		if (i==3) cout<<k<<'\n';
		rep(j,1,c)
		{
			rep(x,0,1) rep(y,0,1) if (mx[x]!=mn[y]||mx[x]==0)
			{
				int Mx=P[i],Mn=L[i];
				if (mx[x]) chkmax(Mx,R[mx[x]]);
				if (mn[y]) chkmin(Mn,L[mn[y]]);
				int s=id(Mn);
				if (p[j]<Mn) continue;
				chkmax(dp[i][j],dp[k][id(Mn)]+max(0,min(Mx-Mn,p[j]-Mn)));
//				if (i==6&&p[j]==12&&dp[k][id(Mn)]+max(0,min(Mx-Mn,p[j]-Mn))==16)
//					printf("%d %d %d %d %d\n",mx[x],mn[y],k,Mn,dp[k][id(Mn)]);
			}
		}
		rep(j,1,c) chkmax(dp[i][j],dp[i][j-1]);
	}
//	rep(i,1,c) cout<<p[i]<<' ';puts("");
//	rep(i,1,c) cout<<dp[3][i]<<' ';
//	cout<<dp[7][id(18)];
	cout<<dp[n][c];
	return 0;
}