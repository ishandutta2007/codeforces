#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k%2==1)
		{
			printf("First\n");
			return 0;
		}
	}
	printf("Second\n");
}