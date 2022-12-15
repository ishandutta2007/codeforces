#include<cstdio>
#include<cstring>

const long long mod=998244353;

int n;
long long a,b,p,f[2001],ff[2001],g[2001][2001];

long long quickmi(long long a,int b)
{
	long long t=1;
	while (b)
	{
		if (b&1) t=t*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return t;
}

int main()
{
	scanf("%d%I64d%I64d",&n,&a,&b);
	p=a*quickmi(b,mod-2)%mod;
	g[0][0]=1;
	for (int i=0; i<=n; i++)
		for (int j=(i==0?1:0); j<=n; j++)
		{
			g[i][j]=0;
			if (i>0) g[i][j]=(g[i][j]+g[i-1][j]*quickmi(1ll-p,j))%mod;
			if (j>0) g[i][j]=(g[i][j]+g[i][j-1]*quickmi(p,i))%mod;
		}
	f[1]=1; ff[1]=0;
	for (int i=2; i<=n; i++)
	{
		f[i]=0;
		for (int j=1; j<i; j++) f[i]=(f[i]+f[j]*g[j][i-j])%mod;
		f[i]=(1-f[i])%mod; ff[i]=i*(i-1)/2;
		for (int j=1; j<i; j++)
			ff[i]=(ff[i]+f[j]*g[j][i-j]%mod*(ff[j]+ff[i-j]-(1ll*(i-j)*(i-j-1)/2)))%mod;
		ff[i]=ff[i]*quickmi(1ll-f[i],mod-2)%mod;
	}
	printf("%I64d\n",(ff[n]+mod)%mod);
	return 0;
}