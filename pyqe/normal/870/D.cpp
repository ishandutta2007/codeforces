#include <bits/stdc++.h>

using namespace std;

long long n,a[2][5069],sq[2][5069];

int main()
{
	long long i,j,ii,z=0,e;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		printf("? 0 %lld\n",i);
		fflush(stdout);
		scanf("%lld",&a[1][i]);
	}
	for(i=0;i<n;i++)
	{
		printf("? %lld %lld\n",i,i);
		fflush(stdout);
		scanf("%lld",&a[0][i]);
		a[0][i]^=a[1][i];
	}
	for(i=0;i<n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(j=0;j<n;j++)
			{
				sq[ii][j]=a[ii][j]^i;
			}
		}
		for(j=0;j<n;j++)
		{
			if(sq[0][sq[1][j]]!=j)
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			z++;
			e=i;
		}
	}
	printf("!\n%lld\n",z);
	for(i=0;i<n;i++)
	{
		printf("%lld%c",a[0][i]^e," \n"[i==n-1]);
	}
	fflush(stdout);
}