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

const int mod=1e9+7;
int power(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}
inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}
#define getcode(i,j) (((i)>>(j))&1)
namespace bin_conv
{
	int bits[1<<17];
	void fmt(int *a,int n,bool f=0)
	{
		if(f){for(int i=0;i<(1<<n);i++)if((bits[i]&1)&&a[i])a[i]=mod-a[i];}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<(1<<n);j++)if(getcode(j,i))
				add(a[j],a[j^(1<<i)]);
		}
		if(f){for(int i=0;i<(1<<n);i++)if((bits[i]&1)&&a[i])a[i]=mod-a[i];}
	}
	int _a[1<<17],_b[1<<17];
	void or_conv(int *a,int *b,int *c,int n)
	{
		for(int i=0;i<(1<<n);i++)
		{
			_a[i]=a[i];
			_b[i]=b[i];
		}
		fmt(_a,n);fmt(_b,n);
		for(int i=0;i<(1<<n);i++)c[i]=1ll*_a[i]*_b[i]%mod;
		fmt(c,n,1);
	}
	void and_conv(int *a,int *b,int *c,int n)
	{
		for(int i=0;i<(1<<n);i++)
		{
			_a[i]=a[i];
			_b[i]=b[i];
		}
		reverse(_a,_a+(1<<n));reverse(_b,_b+(1<<n));
		fmt(_a,n);fmt(_b,n);
		for(int i=0;i<(1<<n);i++)c[i]=1ll*_a[i]*_b[i]%mod;
		fmt(c,n,1);
		reverse(c,c+(1<<n));
	}
	
	int ta[18][1<<17],tb[18][1<<17];
	void sub_conv(int *a,int *b,int *c,int n)
	{
		memset(ta,0,sizeof(ta));memset(tb,0,sizeof(tb));
		for(int i=0;i<(1<<n);i++)
		{
			ta[bits[i]][i]=a[i];
			tb[bits[i]][i]=b[i];
			c[i]=0;
		}
		for(int i=0;i<=n;i++)fmt(ta[i],n);
		for(int i=0;i<=n;i++)fmt(tb[i],n);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				int*t1=ta[j],*t2=tb[i-j];
				for(int k=0;k<(1<<n);k++)_a[k]=1ll*t1[k]*t2[k]%mod;
				fmt(_a,n,1);
				for(int k=0;k<(1<<n);k++)if(bits[k]==i)add(c[k],_a[k]);
			}
		}
	}
	
	void fwt(int *a,int n,bool f=0)
	{
		int sz=(1<<n);
		for(int k=1;k<sz;k<<=1)
		{
			for(int i=0;i<sz;i+=(k<<1))for(int j=0;j<k;j++)
			{
				int u=a[i+j],v=a[i+j+k];
				a[i+j]=u+v;if(a[i+j]>=mod)a[i+j]-=mod;
				a[i+j+k]=u-v;if(a[i+j+k]<0)a[i+j+k]+=mod;
			}
		}
		if(f)
		{
			int rev=power(sz,mod-2);
			for(int i=0;i<sz;i++)a[i]=1ll*a[i]*rev%mod;
		}
	}
	void xor_conv(int *a,int *b,int *c,int n)
	{
		for(int i=0;i<(1<<n);i++)
		{
			_a[i]=a[i];
			_b[i]=b[i];
		}
		fwt(_a,n);fwt(_b,n);
		for(int i=0;i<(1<<n);i++)c[i]=1ll*_a[i]*_b[i]%mod;
		fwt(c,n,1);
	}
	void prework()
	{
		for(int i=0;i<(1<<17);i++)bits[i]=__builtin_popcount(i);
	}
};

int cnt[1<<17],n,ca[1<<17],cb[1<<17],f[1<<17];
int main()
{
	bin_conv::prework();
	get1(n);for(int i=0,x;i<n;i++){get1(x);cnt[x]++;}
	
	f[1]=1;
	for(int i=2;i<(1<<17);i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=mod)f[i]-=mod;
	}
	bin_conv::sub_conv(cnt,cnt,ca,17);
	bin_conv::xor_conv(cnt,cnt,cb,17);
	for(int i=0;i<(1<<17);i++)
	{
		cnt[i]=1ll*cnt[i]*f[i]%mod;
		ca[i]=1ll*ca[i]*f[i]%mod;
		cb[i]=1ll*cb[i]*f[i]%mod;
	}
	bin_conv::and_conv(cnt,ca,cnt,17);
	bin_conv::and_conv(cnt,cb,cnt,17);
	int ans=0;for(int i=0;i<17;i++)add(ans,cnt[1<<i]);
	printf("%d\n",ans);
	return 0;
}