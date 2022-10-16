#include <bits/stdc++.h>

using namespace std;

long long n,dg[100069];

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		dg[k]++;
		dg[l]++;
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]==2)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}