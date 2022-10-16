#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	printf("%lld\n",(n*n+1)/2);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c","C."[(i+j)%2]);
		}
		printf("\n");
	}
}