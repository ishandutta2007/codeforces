#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	if(d<n*2)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for(i=0;i<n-1;i++)
		{
			printf("2 ");
		}
		printf("%lld\n1\n",d-n*2+2);
	}
}