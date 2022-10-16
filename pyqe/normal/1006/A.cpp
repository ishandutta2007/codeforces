#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		scanf("%lld",&k);
		printf("%lld",k-(k+1)%2);
	}
	printf("\n");
}