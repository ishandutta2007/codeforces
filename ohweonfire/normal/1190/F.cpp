// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);


LL mult(LL x,LL y,LL mod)
{
	LL tmp=x*y-LL((long double)1.0*x/mod*y+1e-8)*mod;
	while(tmp<0)tmp+=mod;
	while(tmp>=mod)tmp-=mod;
	return tmp;/**/
}
LL power(LL x,LL y,LL mod)
{
	LL ret=1;x%=mod;
	do
	{
		if(y&1)ret=mult(ret,x,mod);
		x=mult(x,x,mod);
	}while(y>>=1);
	return ret;
}
namespace factor
{
	bool MillerRabin(LL n,int a)
	{
		LL d=n-1;int s=0;
		while(~d&1)
		{
			s++;
			d>>=1;
		}
		LL p=power(a,d,n);
		if(p==1)return true;
		for(int i=0;i<s;i++)
		{
			if(p==n-1)return true;
			p=mult(p,p,n);
		}
		return false;
	}
	bool isprime(LL n)
	{
		for(int i=2;i<30&&i<n;i++)if(!MillerRabin(n,i))return false;
		return true;
	}
	void rho(LL n,vector<LL>&ret)
	{
		if(n==1)return;
		if(isprime(n))
		{
			ret.pb(n);
			return;
		}
		if(n==4)
		{
			ret.pb(2);
			ret.pb(2);
			return;
		}
		static mt19937_64 rnd(443);
		while(true)
		{
			LL x=2,y=2,d=1;int k=rnd()%(n-3)+2;
			while(d==1)
			{
				x=(mult(x,x,n)+k)%n;
				y=(mult(y,y,n)+k)%n;
				y=(mult(y,y,n)+k)%n;
				d=__gcd(n,abs(x-y));
			}
			if(d!=n)
			{
				rho(d,ret);rho(n/d,ret);
				break;
			}
		}
	}
}

int n,k;
LL m,p,phi,q,ord;//m=q^k
vector<LL>chk;

void getphi()
{
	vector<LL> fac;factor::rho(m,fac);
	q=fac[0];k=(int)fac.size();
	phi=m/q*(q-1);
}

bool chk_proot(LL val)
{
	if(val%q==0)return false;
	for(auto v:chk)if(power(val,phi/v,m)==1)return false;
	return true;
}

void get_ord()
{
	ord=phi;
	for(auto v:chk)while(ord%v==0&&power(p,ord/v,m)==1)ord/=v;
}

void solve_p2()
{
	LL rt=5;
	if(p%4==1)
	{
		for(int i=0;i<n&&i<m/4;i++)printf("%lld ",i*4ll+3);
		if(n>m/4)
		{
			n-=m/4;
			LL cur=1;
			while(n--)
			{
				if(cur%(m/4/ord)==0)cur++;
				printf("%lld ",power(rt,cur,m));
				cur++;
			}
		}
	}
	else
	{
		if(ord==1)
		{
			for(int i=0;i<n;i++)printf("%lld ",i*2ll+3);
			return;
		}
		LL cur=1;
		for(int i=0;i<n&&i<m/4-ord/2;i++)
		{
			if(cur%(m/2/ord)==0)cur++;
			printf("%lld ",power(rt,cur,m));
			cur++;
		}
		cur=1;
		if(n>m/4-ord/2)
		{
			n-=m/4-ord/2;
			while(n--)
			{
				if(cur%(m/2/ord)==m/4/ord)cur++;
				printf("%lld ",m-power(rt,cur,m));
				cur++;
			}
		}
	}
}

int main()
{
	get3(n,m,p);
	
	getphi();
	factor::rho(phi,chk);
	sort(chk.begin(),chk.end());
	chk.erase(unique(chk.begin(),chk.end()),chk.end());
	
	if(p%q==0)
	{
		if(phi<=n)puts("-1");
		else
		{
			LL cur=2;
			while(n--)
			{
				if(cur%q==0)cur++;
				printf("%lld ",cur);
				cur++;
			}
		}
		return 0;
	}
	get_ord();
	if(phi-ord<n)
	{
		puts("-1");
		return 0;
	}
	
	if(q==2&&k>2)
	{
		solve_p2();
		return 0;
	}
	LL rt=2;while(!chk_proot(rt))rt++;
	LL cur=1;
	while(n--)
	{
		if(cur%(phi/ord)==0)cur++;
		printf("%lld ",power(rt,cur,m));
		cur++;
	}
	return 0;
}