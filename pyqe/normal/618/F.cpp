#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[2000069],fq[2000069],sq[2][1000069],zs[2];

int main()
{
	long long i,ii,u,p;
	
	scanf("%lld",&n);
	for(i=1;i<=n*2;i++)
	{
		scanf("%lld",a+i);
		u=(i<=n)*2-1;
		a[i]*=u;
	}
	for(p=1;fq[p]<2;p+=a[p])
	{
		if(fq[p])
		{
			zs[p>n]++;
			sq[p>n][zs[p>n]]=(p-1)%n+1;
		}
		fq[p]++;
	}
	for(ii=0;ii<2;ii++)
	{
		printf("%lld\n",zs[ii]);
		for(i=1;i<=zs[ii];i++)
		{
			printf("%lld%c",sq[ii][i]," \n"[i==zs[ii]]);
		}
	}
}