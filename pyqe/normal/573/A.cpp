#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=2;j<=3;j++)
		{
			for(;k%j==0;k/=j);
		}
		if(i&&k!=l)
		{
			printf("No\n");
			return 0;
		}
		l=k;
	}
	printf("Yes\n");
}