#include <bits/stdc++.h>

using namespace std;

long long n,d;
bitset<100069> vtd;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&d,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(vtd[k%d])
		{
			printf("%lld\n",i);
			return 0;
		}
		vtd[k%d]=1;
	}
	printf("-1\n");
}