#include <bits/stdc++.h>

using namespace std;

long long n,d,ub=1e5;
bitset<100069> vtd;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	d=min(d,ub);
	for(i=1;i<=d;i++)
	{
		if(vtd[n%i])
		{
			printf("No\n");
			return 0;
		}
		vtd[n%i]=1;
	}
	printf("Yes\n");
}