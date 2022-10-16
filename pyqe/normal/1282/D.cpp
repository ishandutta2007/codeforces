#include <bits/stdc++.h>

using namespace std;

long long n=0,fq[2],a[100069];
bitset<100069> sq;

int main()
{
	long long i,j,ii,k,z,c,mx=-1e18;
	
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<300;i++)
		{
			printf("%c",ii+'a');
		}
		printf("\n");
		fflush(stdout);
		scanf("%lld",fq+ii);
		if(fq[ii]==0)
		{
			return 0;
		}
		fq[ii]=300-fq[ii];
		n+=fq[ii];
	}
	z=fq[1];
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c",(j==i)+'a');
		}
		printf("\n");
		fflush(stdout);
		scanf("%lld",a+i);
		if(a[i]==0)
		{
			return 0;
		}
		if(a[i]==fq[1]-1)
		{
			sq[i]=1;
			z--;
		}
	}
	sq[n-1]=z;
	for(i=0;i<n;i++)
	{
		printf("%c",sq[i]+'a');
	}
	printf("\n");
	fflush(stdout);
	scanf("%lld",&k);
}