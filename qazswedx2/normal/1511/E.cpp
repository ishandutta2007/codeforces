#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,m,pw[1000005],ipw[1000005],f[1000005],inv2,pn=1e6;
int a[1000005];
int main()
{
	pw[0]=ipw[0]=1;
	inv2=fpow(2,mod-2);
	for(int i=1;i<=pn;i++)
	{
		pw[i]=2*pw[i-1]%mod;
		ipw[i]=1ll*inv2*ipw[i-1]%mod;
	}
	for(int i=3;i<=pn;i+=2)
		f[i]=addmod(f[i-2]+ipw[i]);
	for(int i=2;i<=pn;i+=2)
		f[i]=addmod(f[i-1]+ipw[i]);
	scanf("%d%d",&n,&m);
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch;
			scanf(" %c",&ch);
			a[(i-1)*m+j]=(ch=='o');
			sum+=(ch=='o');
		}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int ct=0;
		for(int j=1;j<=m;j++)
		{
			if(a[(i-1)*m+j]==0) ct=0;
			else
			{
				ct++;
				ans=addmod(ans+f[ct]);
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		int ct=0;
		for(int i=1;i<=n;i++)
		{
			if(a[(i-1)*m+j]==0) ct=0;
			else
			{
				ct++;
				ans=addmod(ans+f[ct]);
			}
		}
	}
	ans=1ll*ans*pw[sum]%mod;
	printf("%d\n",ans);
	return 0;
}