#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,ii,u;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	printf("1 1\n%lld\n",-a[1]);
	a[1]=0;
	for(ii=0;ii<2;ii++)
	{
		u=ii*2-1;
		printf("%lld %lld\n",min(ii+1,n),n);
		for(i=min(ii+1,n);i<=n;i++)
		{
			printf("%lld%c",a[i]*(n-ii)*u," \n"[i==n]);
		}
	}
}