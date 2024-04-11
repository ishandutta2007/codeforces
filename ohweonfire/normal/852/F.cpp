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

int power(int x,int y,int mod)
{
	x%=mod;
	int ret=1;
	while(y)
	{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}

int q,a,m,n,f[1000222],invf[1000222],ans[1000222];

int check(int x)
{
//	printf("check %d\n",x);
	int ret=q;
	for(int i=2;i*i<=x;i++)if(x%i==0)
	{
		if(power(a,i,q)==1)ret=min(ret,i);
		while(x%i==0)x/=i;
	}
	if(power(a,x,q)==1)ret=min(ret,x);
	return ret;
}
int c(int x,int y,int mod){if(x<y)return 0;return 1ll*f[x]*invf[y]%mod*invf[x-y]%mod;}
int main()
{
	get2(n,m);
	get2(a,q);
	int tmp=q,mod=q;
	for(int i=2;i*i<=tmp;i++)
	{
		if(tmp%i)continue;
		mod=min(mod,check(i-1));
		if(tmp%(i*i)==0)mod=min(mod,check(i));
		while(tmp%i==0)tmp/=i;
	}
	if(tmp>1)mod=min(mod,check(tmp-1));if(a==1)mod=1;
	
	f[0]=1;for(int i=1;i<mod;i++)f[i]=1ll*f[i-1]*i%mod;
	invf[mod-1]=power(f[mod-1],mod-2,mod);
	for(int i=mod-2;i>=0;i--)invf[i]=1ll*invf[i+1]*(i+1)%mod;
	ans[0]=1;
	for(int i=1;i<n;i++)
	{
		ans[i]=ans[i-1]+c(m,i,mod);
		if(ans[i]>=mod)ans[i]-=mod;
	}
	reverse(ans,ans+n);
//	for(int i=0;i<n;i++)printf("%d ",ans[i]);puts("");
	for(int i=0;i<n;i++)printf("%d ",power(a,ans[i],q));
	return 0;
}