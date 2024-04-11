// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
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
	return tmp;
}
LL power(LL x,LL y,LL mod)
{
	LL ret=1;
	do
	{
		if(y&1)ret=mult(ret,x,mod);
		x=mult(x,x,mod);
	}while(y>>=1);
	return ret;
}

int n;LL x,pw[18],tpw[18],phi[18];

LL getlg(LL x)
{
	LL ret=0;
	for(int i=1;i<18;i++)
	{
		LL tmp=x%pw[i],p=power(2,ret,pw[i]);
		while(p!=tmp)
		{
			p=mult(p,tpw[i],pw[i]);
			ret+=phi[i-1];
		}
	}
	return ret;
}
int main()
{
	pw[0]=1;for(int i=1;i<18;i++)pw[i]=pw[i-1]*5;
	phi[0]=1;phi[1]=4;for(int i=2;i<18;i++)phi[i]=phi[i-1]*5;
	for(int i=1;i<18;i++)tpw[i]=power(2,phi[i-1],pw[i]);
	
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(x);x*=1000000;
		x=(x-1>>17)+1;if(x%5==0)x++;
		printf("%I64d\n",getlg(x)+17);
	}
	return 0;
}