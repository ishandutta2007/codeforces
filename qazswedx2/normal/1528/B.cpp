#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
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
int n,f[1000005],g[1000005],a[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			a[j]++;
	f[0]=1;
	g[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=g[i-1];
		f[i]=addmod(f[i]+a[i]);
		g[i]=addmod(g[i-1]+f[i]);
	//	printf("i=%d,a=%d,f=%d,g=%d\n",i,a[i],f[i],g[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}