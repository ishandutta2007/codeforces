#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],pst[100069],sq[100069];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		printf("XOR 1 %lld\n",i);
		fflush(stdout);
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		if(pst[a[i]])
		{
			printf("OR %lld %lld\n",pst[a[i]],i);
			fflush(stdout);
			scanf("%lld",&k);
			sq[1]=k^a[i];
			i=-1;
			break;
		}
		pst[a[i]]=i;
	}
	if(i!=-1)
	{
		printf("OR 1 %lld\n",pst[n>>1]);
		fflush(stdout);
		scanf("%lld",&k);
		sq[1]=k%(n>>1);
		printf("OR 1 %lld\n",pst[1]);
		fflush(stdout);
		scanf("%lld",&k);
		sq[1]|=k&n>>1;
	}
	for(i=2;i<=n;i++)
	{
		sq[i]=sq[1]^a[i];
	}
	printf("!");
	for(i=1;i<=n;i++)
	{
		printf(" %lld",sq[i]);
	}
	printf("\n");
	fflush(stdout);
}