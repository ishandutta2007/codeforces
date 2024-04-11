#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n==1)
		{
			printf("-1\n");
		}
		else
		{
			printf("2");
			for(i=0;i<n-1;i++)
			{
				printf("9");
			}
			printf("\n");
		}
	}
}