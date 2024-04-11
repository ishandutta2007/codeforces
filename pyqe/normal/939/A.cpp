#include <bits/stdc++.h>

using namespace std;

long long n,pr[100069];

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pr+i);
	}
	for(i=1;i<=n;i++)
	{
		if(pr[pr[pr[i]]]==i)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}