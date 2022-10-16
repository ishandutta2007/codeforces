#include <bits/stdc++.h>

using namespace std;

long long n,d,a[569];

int main()
{
	long long i,j,mx=0,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=d+1;i++)
	{
		printf("?");
		for(j=1;j<=d+1;j++)
		{
			if(j!=i)
			{
				printf(" %lld",j);
			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%lld%lld",a+i,a+i);
		mx=max(mx,a[i]);
	}
	for(i=1;i<=n;i++)
	{
		z+=a[i]==mx;
	}
	printf("! %lld\n",z);
}