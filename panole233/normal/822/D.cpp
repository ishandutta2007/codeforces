#include<cstdio>
#include<cmath>
#include<cstring>

const long long mod=1e9+7;

int l,r;
long long f[5000001],ans,t,p[5000001],x,sum;
bool b[5000001];

int main()
{
	scanf("%I64d%d%d",&t,&l,&r);
	memset(b,1,sizeof(b));
	f[1]=0; f[2]=1;
	for (int i=2; i<=5000000; i++)
		if (b[i])
			for (int j=i<<1; j<=5000000; j+=i) b[j]=0;
	p[0]=0;
	for (long long i=2; i<=5000000; i++) 
		if (b[i]) f[i]=i*(i-1)>>1;
	for (long long i=2; i<=5000000; i++)
		for (int j=2; j<=i&&i*j<=5000000; j++) 
			if (f[i*j]>f[i]+f[j]*i||f[i*j]==0) f[i*j]=f[i]+f[j]*i;
	for (int i=2; i<=5000000; i++) f[i]%=mod;
	sum=1; ans=f[l];
	for (int i=l+1; i<=r; i++)
		sum=(sum*t)%mod,ans=(ans+sum*f[i]%mod)%mod;
	printf("%I64d",ans);
	return 0;
}