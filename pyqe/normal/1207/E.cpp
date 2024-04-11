#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,z=0,k;
	
	printf("?");
	for(i=1;i<=100;i++)
	{
		printf(" %lld",i);
	}
	printf("\n");
	fflush(stdout);
	scanf("%lld",&k);
	z+=k/128*128;
	printf("?");
	for(i=128;i<=12800;i+=128)
	{
		printf(" %lld",i);
	}
	printf("\n");
	fflush(stdout);
	scanf("%lld",&k);
	z+=k%128;
	printf("! %lld\n",z);
}