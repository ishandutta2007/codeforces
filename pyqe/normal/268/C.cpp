#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&m);
	k=min(n,m);
	printf("%lld\n",k+1);
	for(i=0;i<=k;i++)
	{
		printf("%lld %lld\n",i,k-i);
	}
}