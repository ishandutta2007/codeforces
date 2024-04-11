#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<100069> a[69];

int main()
{
	long long i,j,k,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			a[i][k]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if((a[i]&a[j])==a[0])
			{
				printf("impossible\n");
				return 0;
			}
		}
	}
	printf("possible\n");
}