#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069];

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ps[i]=ps[i-1]+k;
	}
	for(i=1;i<n;i++)
	{
		if(ps[i]!=ps[n]-ps[i])
		{
			printf("%lld\n",i);
			for(j=1;j<=i;j++)
			{
				printf("%lld%c",j," \n"[j==i]);
			}
			return 0;
		}
	}
	printf("-1\n");
}