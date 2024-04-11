#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dv;

int main()
{
	long long i,j,z=1;
	
	scanf("%lld%lld",&n,&dv);
	if(n>dv)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=1;j<i;j++)
		{
			z=z*abs(a[i]-a[j])%dv;
		}
	}
	printf("%lld\n",z);
}