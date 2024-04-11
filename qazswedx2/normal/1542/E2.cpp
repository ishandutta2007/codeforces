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
int n,f[1000005],g[1000005],ans;
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
		int nw=0,v0=0,v1=0,v2=0;
		for(int j=mx-2;j>=0;j--)
		{
		/*	for(int k=j+2;k<=mx;k++)
			{
			//	printf("nw=%d,j=%d,k=%d,f=%d,%d,g=%d\n",nw,j,k,f[j],f[k],g[min(i,k-j-1)]);
				nw=(nw+1ll*f[j]*f[k]%mod*g[min(i,k-j-1)])%mod;
			}*/
			v1=submod(v1-v0);
			v1=addmod(v1+1ll*f[j+2]*i%mod);
			v0=addmod(v0+f[j+2]);
			if(j+i+2<=mx) v0=submod(v0-f[j+i+2]);
			v2=addmod(v2+v1);
			nw=addmod(nw+1ll*v2*f[j]%mod);
		//	printf("i=%d,j=%d,v0=%d,v1=%d,v2=%d\n",i,j,v0,v1,v2);
		}
		for(int j=i+2;j<=n;j++)
			nw=1ll*nw*j%mod;
		ans=addmod(ans+nw);
	}
	printf("%d\n",ans);
	return 0;
}