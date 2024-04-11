#include <bits/stdc++.h>

using namespace std;

long long n,mx[2];

int main()
{
	long long i,ii,k;
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			mx[ii]=max(mx[ii],k);
		}
	}
	printf("%lld %lld\n",mx[0],mx[1]);
}