#include <bits/stdc++.h>

using namespace std;

long long n,sq[1069];

int main()
{
	long long i,ii,k,sm;
	
	scanf("%lld",&n);
	printf("? 1 3\n");
	fflush(stdout);
	scanf("%lld",&sm);
	for(ii=0;ii<2;ii++)
	{
		printf("? %lld %lld\n",2-ii,3-ii);
		fflush(stdout);
		scanf("%lld",&k);
		sq[1+2*ii]=sm-k;
	}
	sq[2]=sm-sq[1]-sq[3];
	for(i=4;i<=n;i++)
	{
		printf("? %lld %lld\n",i-1,i);
		fflush(stdout);
		scanf("%lld",&k);
		sq[i]=k-sq[i-1];
	}
	printf("!");
	for(i=1;i<=n;i++)
	{
		printf(" %lld",sq[i]);
	}
	printf("\n");
	fflush(stdout);
}