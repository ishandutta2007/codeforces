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

map<int,int>dC;
int C3(int x){return x*(x-1)/2*(x-2)/3;}

#define hh pii
const hh operator - (const hh &y,const hh &x) {return hh(y.fir-x.fir,y.sec-x.sec);}
hh cur;

hh query(int x){printf("+ %d\n",x);fflush(stdout);hh p;read(p.fir,p.sec);swap(p,cur);return cur-p;}

int n;
hh q[sz][3];
int ans[sz];

int main()
{
//	file();
	read(n);
	read(cur.fir,cur.sec);
	rep(i,1,n+3) dC[C3(i+1)-C3(i)]=i;
	if (n&1)
	{
		q[3][1]=query(3);
		for (int i=n;i>3;i-=2) q[i][1]=query(i);
		q[4][1]=query(4);
		for (int i=5;i<=n;i+=2) q[i][2]=query(i),ans[i]=dC[q[i][2].fir]-1;
		q[2][1]=query(2);
	}
	else
	{
		q[2][1]=query(2);
		for (int i=n;i>=4;i-=2) q[i][1]=query(i);
		q[3][1]=query(3);
		for (int i=4;i<=n;i+=2) q[i][2]=query(i),ans[i]=dC[q[i][2].fir]-1;
	}
	for (int i=n;i>=6;i-=2)
	{
		hh x=q[i][2]-q[i][1];
		ans[i-1]=x.sec/2;
	}
	if (n%2==0)
	{
		ans[2]=q[4][2].sec-q[4][1].sec-1-ans[5];
		ans[3]=(q[4][2].sec-ans[5]*(ans[6]+1))/(ans[2]+1+ans[5])-1;
		ans[1]=(q[3][1].sec-(ans[4]+1)*ans[5])/(ans[2]+1)-ans[4]-1; 
	}
	else
	{
		ans[3]=q[5][2].sec-q[5][1].sec-1-ans[6];
		ans[4]=(q[5][1].sec-ans[6]*(ans[7]+1))/(ans[3]+1+ans[6]);
		ans[2]=(q[4][1].sec-(ans[5]+1)*(ans[3]+1+ans[6]))/(ans[3]+1);
		ans[1]=(q[2][1].sec-(ans[3]+1)*(ans[4]+1))/(ans[3]+1);
	}
	printf("! ");rep(i,1,n) printf("%d ",ans[i]);
	fflush(stdout);
	return 0;
}