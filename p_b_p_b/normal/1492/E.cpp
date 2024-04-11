#include<bits/stdc++.h>
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
	#define sz 303030
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

int n,m;
vector<int>a[sz];
int ok[sz];
vector<int>c3[sz];

void check(vector<int>b)
{
	int t=0,t3=0;
	rep(i,1,m) ok[i]=0,c3[i].clear();
	rep(i,1,n)
	{
		int c=0;
		rep(j,1,m) c+=(a[i][j]!=b[j]);
		if (c<=1) continue;
		++t;
		rep(j,1,m) if (a[i][j]!=b[j])
		{
			++ok[j];
			if (c==3) c3[j].push_back(a[i][j]),++t3;
			else if (c>3) return;
		}
	}
	if (!t3)
	{
		puts("Yes");
		rep(i,1,m) printf("%d ",b[i]);
		exit(0);
	}
	rep(i,1,m) if (ok[i]==t)
	{
		int flg=1;
		if (!c3[i].size()) flg=1;
		else
		{
			for (auto x:c3[i]) if (x!=c3[i][0]) flg=0;
			if (!flg) continue;
			b[i]=c3[i][0];
		}
		puts("Yes");
		rep(j,1,m) printf("%d ",b[j]);
		exit(0);
	}
}

int main()
{
	file();
	read(n,m);
	rep(i,0,n) a[i].resize(m+1);
	rep(i,1,n) rep(j,1,m) read(a[i][j]);
	if (m==2)
	{
		puts("Yes");
		puts("1 1");
		return 0;
	}
	if (m==1) return puts("Yes\n1\n"),0;
	check(a[1]);
	if (n<m)
	{
		int tp=1;
		while (233)
		{
			int cnt=0;
			rep(i,1,n) cnt+=(a[i][tp]!=a[1][tp]);
			if (cnt) break;
			++tp;
		}
		rep(i,1,n)
		{
			rep(j,1,n) if (a[j][tp]!=a[i][tp])
			{
				rep(k,1,m) a[0][k]=a[j][k]; a[0][tp]=a[i][tp];
				check(a[0]);
				break;
			}
		}
		puts("No");
		return 0;
	}
	rep(i,1,m)
	{
		rep(j,2,n) if (a[j][i]!=a[1][i])
		{
			rep(k,1,m) a[0][k]=a[j][k]; a[0][i]=a[1][i];
			check(a[0]);
			break;
		}
	}
	puts("No");
	return 0;
}