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
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,f[100005],g[100005],h[100005],fr[100005],infr[100005],pn=1e5;
int inv[100005],A[100005],B[100005],C[100005];
int main()
{
	scanf("%d%d",&n,&mod);
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	for(int i=1;i<=pn;i++)
		inv[i]=1ll*infr[i]*fr[i-1]%mod;
	g[1]=1;
	h[1]=1;
	for(int i=2;i<=n;i++)
	{
	//	f[i]=(f[i-1]+g[i-1])%mod;
		g[i]=1ll*f[i-1]*(i-1)%mod;
		h[i]=1ll*(f[i-1]+g[i-1])*(i-1)%mod;
	//	printf("i=%d,h=%d\n",i,h[i]);
		for(int j=1;j<i;j++)
		{
			f[i]=addmod(f[i]+1ll*h[j]*(f[i-j]+g[i-j])%mod);
		//	printf("i=%d,f=%d,h=%d,%d,%d\n",i,f[i],h[j],j,f[i-j]+g[i-j]);
			if(j>=2)
			{
				
				g[i]=addmod(g[i]+1ll*g[j]*f[i-j]%mod*(i-j)%mod);
				h[i]=addmod(h[i]+1ll*h[j]*(i-j)%mod*(f[i-j]+g[i-j])%mod);
			//	printf("i=%d,h=%d,%d,%d\n",i,h[j],j,f[i-j]+g[i-j]);
			}
		}
	//	f[i]=1ll*f[i]*inv[i]%mod;
		g[i]=1ll*g[i]*inv[i-1]%mod;
		h[i]=1ll*h[i]*inv[i-1]%mod;
	}
	for(int i=1;i<=n;i++)
	{
		A[i]=f[i];
		for(int j=1;j<i;j++)
		{
			A[i]=addmod(A[i]+1ll*g[j]%mod*h[i-j]%mod);
			A[i]=addmod(A[i]+1ll*g[j]%mod*f[i-j]%mod);
			A[i]=addmod(A[i]+1ll*A[j]*h[i-j]%mod);
		}
	}
	for(int i=1;i<=n;i++)
	{
		B[i]=1ll*A[i]*i%mod;
		for(int j=1;j<i;j++)
		{
			B[i]=addmod(B[i]+1ll*B[j]%mod*A[i-j]%mod*j%mod);
		//	printf("j=%d,B=%d,A=%d,%d\n",j,B[j],A[i-j],i-j);
		}
		B[i]=1ll*B[i]*inv[i]%mod;
	}
	for(int i=1;i<=n;i++)
		B[i]=submod(B[i]-f[i]);
	for(int i=1;i<=n;i++)
	{
		C[i]=1ll*B[i]*i%mod;
		for(int j=1;j<i;j++)
		{
			C[i]=addmod(C[i]+1ll*B[j]*j%mod*C[i-j]%mod);
		}
		C[i]=1ll*C[i]*inv[i]%mod;
	}
/*	for(int i=1;i<=n;i++)
		printf("%lld ",1ll*f[i]*fr[i]%mod);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%lld ",1ll*g[i]*fr[i]%mod);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%lld ",1ll*h[i]*fr[i]%mod);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%lld ",1ll*A[i]*fr[i]%mod);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%lld ",1ll*B[i]*fr[i]%mod);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%lld ",1ll*C[i]*fr[i]%mod);
	printf("\n");*/
	printf("%lld\n",1ll*C[n]*fr[n]%mod);
	return 0;
}