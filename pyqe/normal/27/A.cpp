#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> vtd;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		vtd[k]=1;
	}
	for(i=1;vtd[i];i++);
	printf("%lld\n",i);
}