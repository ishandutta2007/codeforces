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

const int mod=998244353;
const int maxn=1000111;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%mod;
		x=(LL)x*x%mod;
		y>>=1;
	}
	return ret;
}
int n,fac[maxn],invf[maxn];


int main()
{
	fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=(LL)i*fac[i-1]%mod;
	invf[0]=1;for(int i=1;i<maxn;i++)invf[i]=qpow(fac[i],mod-2);
	
	get1(n);
	
	int ans=1;
	for(int i=0;i<=n;i++)
	{
		ans=(ans+(LL)fac[n]*invf[i]%mod*(fac[i]+mod-1))%mod;
	}
	printendl(ans);
	return 0;
}