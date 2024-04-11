#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	l=0;
	for(i=1;i<=n+1;i++)
	{
		if(i<=n)
		{
			scanf("%lld",&k);
		}
		else
		{
			k=91;
		}
		if(k-l>15)
		{
			printf("%lld\n",l+15);
			return 0;
		}
		l=k;
	}
	printf("90\n");
}