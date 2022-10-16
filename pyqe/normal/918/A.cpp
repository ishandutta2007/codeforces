#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k=1,l=1;
	bool bad;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		bad=0;
		for(;k==i;)
		{
			swap(k,l);
			k+=l;
			bad=1;
		}
		printf("%c","oO"[bad]);
	}
	printf("\n");
}