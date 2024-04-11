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
	#define sz 1010
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

int n;
int p[sz],q[sz];
int vis[sz];

char ans[sz][sz];
int workR(int id,int r)
{
	if (r==-1) return 0;
	int flg=0;
	rep(k,1,n) if (p[k]>k&&r>=p[k]) flg=k;
	if (!flg) return 0;
	int l=0;drep(i,n,1) if (p[i]) l=i;
	ans[id][flg]=ans[id][p[flg]]=ans[id][r]=ans[id][l]='/';
	int i=flg,j=p[flg];
	if (p[j]) p[r]=p[j],q[p[j]]=r,p[j]=0;
	q[p[i]]=0,p[i]=0;
	if (i!=l&&p[l]) q[p[l]]=i,p[i]=p[l],p[l]=0;
	vis[j]=1;
	return 1; 
}
int workL(int id,int l)
{
	if (l==-1) return 0;
	int flg=0;
	rep(k,1,n) if (p[k]<k&&l<=p[k]) flg=k;
	if (!flg) return 0;
	int r=0;rep(i,1,n) if (p[i]) r=i; 
	ans[id][flg]=ans[id][p[flg]]=ans[id][r]=ans[id][l]='\\';
	int j=flg,i=p[flg];
	q[p[j]]=0,p[j]=0;
	if (p[i]) p[l]=p[i],q[p[i]]=l,p[i]=0;
	if (j!=r&&p[r]) q[p[r]]=j,p[j]=p[r],p[r]=0;
	vis[i]=1;
	return 1; 
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(p[i]),q[p[i]]=i;
	rep(i,1,n) rep(j,1,n) ans[i][j]='.';
	int flg=1;rep(i,1,n) flg&=(p[i]==i);
	if (flg) { cout<<n<<'\n'; rep(i,1,n) cout<<(ans[i]+1)<<'\n'; return 0; }
	cout<<n-1<<'\n';
	q[p[n]]=0,p[n]=0;
	drep(i,n,1)
	{
		int flg=0;
		rep(j,1,n) if (p[j]==j) flg=j;
		if (flg) { p[flg]=q[flg]=0; vis[flg]=1; continue; }
		rep(j,1,n) if (p[j]) flg=1;
		if (!flg) break;
		int l=-1,r=-1;
		rep(i,1,n) if (!vis[i]&&!p[i]) r=i; 
		drep(i,n,1) if (!vis[i]&&!p[i]) l=i; 
		workR(i,r)||workL(i,l);
	}
	rep(i,1,n) cout<<(ans[i]+1)<<'\n';
	return 0;
}