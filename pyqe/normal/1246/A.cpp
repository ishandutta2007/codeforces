#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;n>0;n-=d,i++)
	{
		if(__builtin_popcount(n)<=i&&n>=i)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("-1\n");
}