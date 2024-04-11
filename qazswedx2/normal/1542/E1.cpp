#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mod;
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
		ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2; 
	}
	return ans;
}
int n,q[1005],f[100005],g[100005],ans;
int main()
{
	scanf("%d%d",&n,&mod);
	f[0]=1%mod;
	int mx=0;
	for(int i=1;i<n;i++)
	{
		for(int j=mx;j>=0;j--)
			f[j+i]=submod(f[j+i]-f[j]);
		for(int j=1;j<=mx+i;j++)
			f[j]=addmod(f[j]+f[j-1]);
		mx+=(i-1);
		for(int j=1;j<=i;j++)
			g[j]=g[j-1]+(i-j+1);
		int nw=0;
		for(int j=0;j<=mx;j++)
			for(int k=j+2;k<=mx;k++)
			{
			//	printf("nw=%d,j=%d,k=%d,f=%d,%d,g=%d\n",nw,j,k,f[j],f[k],g[min(i,k-j-1)]);
				nw=(nw+1ll*f[j]*f[k]%mod*g[min(i,k-j-1)])%mod;
			}
		for(int j=i+2;j<=n;j++)
			nw=1ll*nw*j%mod;
		ans=addmod(ans+nw);
	}
	printf("%d\n",ans);
	return 0;
}