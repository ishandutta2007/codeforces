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
	#define sz 333
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

int ans[10][sz][10]=
{
	{{2},{3,1,2,3},{3,1,2,3}},
	{{4},{3,1,2,3},{3,1,2,4},{3,1,3,4},{3,2,3,4}},
	{{6},{3,5,4,2},{3,3,1,5},{4,4,5,2,3},{4,4,3,2,1},{3,4,2,1},{3,3,1,5}},
	{{9},{4,1,5,2,4},{4,1,6,3,4},{4,2,6,3,5},{3,1,2,6},{3,2,3,4},{3,1,5,3},{3,1,2,3},{3,4,5,6},{3,4,5,6}}
};
int L[sz][2],R[sz][2];
int Ans[sz*sz][10],cnt;
void addcir(int s,int l){ rep(i,1,ans[s][0][0]) { assert(ans[s][i][0]); ++cnt; rep(j,0,ans[s][i][0]) Ans[cnt][j]=ans[s][i][j]+(!!j)*l; } }
void solve(int l,int r)
{
	int s=r-l+1;
	if (s<=6) return addcir(s-3,l);
	int x,y,c;
	if (s&1)
	{
		x=3,y=(s-3)>>1,c=1;
		++l;
		L[1][0]=l,L[1][1]=l+1; L[2][0]=l,L[2][1]=l+2; L[3][0]=l+1,L[3][1]=l+2;
		rep(i,1,y) rep(k,0,1) R[i][k]=l+3+2*(i-1)+k;
		--l;
		addcir(0,l);
	}
	else
	{
		x=2,y=(s-4)>>1,c=2;
		++l;
		rep(i,1,x) rep(k,0,1) L[i][k]=l+2*(i-1)+k;
		rep(i,1,y) rep(k,0,1) R[i][k]=l+4+2*(i-1)+k;
		--l;
		addcir(1,l);
	}
	rep(i,1,x) rep(j,1,y) rep(k,1,c) ++cnt,Ans[cnt][0]=4,Ans[cnt][1]=L[i][0],Ans[cnt][2]=R[j][0],Ans[cnt][3]=L[i][1],Ans[cnt][4]=R[j][1];
	solve(l+((s&1)?3:4),r);
}

int main()
{
	file();
	read(n);
	solve(0,n-1);
	printf("%d\n",cnt);
	rep(i,1,cnt) { rep(j,0,Ans[i][0]) printf("%d ",Ans[i][j]); puts(""); }
	return 0;
}