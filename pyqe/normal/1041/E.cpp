#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[100069];
bitset<100069> vtd;

int main()
{
	long long i,j,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(l<n)
		{
			printf("NO\n");
			return 0;
		}
		a[i]=k;
	}
	sort(a+1,a+n);
	for(j=1,i=1;i<=n-1;i++)
	{
		if(a[i]>a[i-1])
		{
			sq[i]=a[i];
		}
		else
		{
			for(;vtd[j];j++);
			if(j>a[i])
			{
				printf("NO\n");
				return 0;
			}
			sq[i]=j;
		}
		vtd[sq[i]]=1;
	}
	sq[n]=n;
	printf("YES\n");
	for(i=1;i<=n-1;i++)
	{
		printf("%lld %lld\n",sq[i],sq[i+1]);
	}
}