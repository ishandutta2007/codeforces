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
	#define mod 1000000007ll
	#define MOD 1000000006ll
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

ll n,c;
ll f[4];

ll work(ll w)
{
	ll S=sqrt(mod);
	unordered_map<ll,int>M;
	rep(i,0,S) M[ksm(5,S*i)%mod]=S*i;
	ll ret=-1;
	rep(i,0,S) if (M.count(ksm(5,mod-1-i)*w%mod)) ret=i+M[(ksm(5,mod-1-i)*w%mod)];
	return ret;
}

struct mat
{
	ll a[7][7];
	mat(){memset(a,0,sizeof(a));}
	inline mat operator * (const mat &x) const 
	{
		mat ret;
		rep(i,1,5)
			rep(k,1,5)
			 	rep(j,1,5)
			 		(ret.a[i][j]+=a[i][k]*x.a[k][j]%MOD)%=MOD;
		return ret;
	}
}A;

mat ksm(mat x,ll y)
{
	mat ret=x;--y;
	for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;
	return ret;
} 

int main()
{
	file();
	read(n,f[1],f[2],f[3],c);
	rep(i,1,3) f[i]=work(f[i]);
	ll x=work(c);
	A.a[1][1]=A.a[1][2]=A.a[1][3]=A.a[2][1]=A.a[3][2]=A.a[4][4]=A.a[5][4]=A.a[5][5]=1;
	A.a[1][4]=-4;A.a[1][5]=2;
	A=ksm(A,n-3);
	ll w=A.a[1][4]*x%MOD+A.a[1][5]*x%MOD*3%MOD;
	rep(i,1,3) (w+=A.a[1][i]*f[4-i]%MOD)%=MOD;
	cout<<ksm(5,w); 
	return 0;
}