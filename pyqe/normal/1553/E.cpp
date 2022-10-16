#include <bits/stdc++.h>

using namespace std;

long long n,m,a[300069],fq[300069],pr[300069],sq[300069],zs;
bitset<300069> vtd;

int main()
{
	long long t,rr,i,j,c,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			fq[(i+n-a[i])%n]++;
		}
		zs=0;
		for(i=0;i<n;i++)
		{
			if(fq[i]>=n-m*2)
			{
				for(j=1;j<=n;j++)
				{
					pr[j]=(a[j]+i-1)%n+1;
					vtd[j]=0;
				}
				c=n;
				for(j=1;j<=n;j++)
				{
					c-=!vtd[j];
					for(p=j;!vtd[p];vtd[p]=1,p=pr[p]);
				}
				if(c<=m)
				{
					zs++;
					sq[zs]=i;
				}
			}
		}
		printf("%lld",zs);
		for(i=1;i<=zs;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
	}
}