#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],dv=1e9+7;

int main()
{
	long long i,k,z=1;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]=d-a[i];
	}
	for(i=1;i<=n+1;i++)
	{
		k=a[i]-a[i-1];
		if(abs(k)>1||a[i]<0)
		{
			printf("0\n");
			return 0;
		}
		if(k==-1)
		{
			z=z*a[i-1]%dv;
		}
		else if(!k&&a[i])
		{
			z=z*(a[i]+1)%dv;
		}
	}
	printf("%lld\n",z);
}