// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

LL mul(LL a,LL b,LL mod)
{
	if(b<0)
	{
		a=-a;
		b=-b;
	}
	a=(a%mod+mod)%mod;
	LL ret=0;
	while(b)
	{
		if(b&1)ret=(ret+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return ret;
}
void ext_gcd(LL m,LL n,LL&a,LL&b)
{
	if(n==0)
	{
		a=1;b=0;
		return;
	}
	LL aa,bb;
	ext_gcd(n,m%n,aa,bb);
	a=-bb;b=-aa-bb*(m/n);
}
LL n,M,a[10111],lcm=1;
int k;
int main()
{
	get3(n,M,k);
	for(int i=1;i<=k;i++)
	{
		get1(a[i]);
		lcm/=__gcd(lcm,a[i]);
		if(n/lcm<a[i])
		{
			puts("NO");
			return 0;
		}
		lcm*=a[i];
	}
	LL m=1,p=0,aa,bb,gcd;
	for(int i=1;i<=k;i++)
	{
		gcd=__gcd(m,a[i]);
		ext_gcd(m,a[i],aa,bb);
		if((p+i-1)%gcd)
		{
			puts("NO");
			return 0;
		}
		aa=(aa%a[i]+a[i])%a[i];
		aa=(a[i]-aa*(p+i-1)/gcd%a[i])%a[i];
		p=mul(aa,m,m/gcd*a[i])+p;
		m*=a[i]/gcd;
		p%=m;
	}
	if(p==0)p=m;
	if(p+k-1>M)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		if(__gcd(p+i-1,lcm)!=a[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}