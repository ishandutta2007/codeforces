#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<min(n,m);i++)
		{
			printf("01");
		}
		for(i=0;i<n-m;i++)
		{
			printf("0");
		}
		for(i=0;i<m-n;i++)
		{
			printf("1");
		}
		printf("\n");
	}
}