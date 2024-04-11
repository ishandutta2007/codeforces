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
int n,f[200005],g[200005];
int main()
{
	scanf("%d",&n);
	f[0]=g[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=g[i-1];
		g[i]=f[i];
		if(i>=2) g[i]=addmod(g[i]+g[i-2]);
	}
	int ans=1ll*f[n]*fpow(fpow(2,mod-2),n)%mod;
	printf("%d",ans);
	return 0;
}