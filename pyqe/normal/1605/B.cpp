#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],as[100069],sq[100069],zs;

int main()
{
	long long t,rr,i;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
			as[i]=a[i];
		}
		sort(as+1,as+n+1);
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=as[i])
			{
				zs++;
				sq[zs]=i;
			}
		}
		if(!zs)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n%lld",zs);
			for(i=1;i<=zs;i++)
			{
				printf(" %lld",sq[i]);
			}
			printf("\n");
		}
	}
}