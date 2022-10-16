#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,mx=-1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k>mx+1)
		{
			printf("%lld\n",i);
			return 0;
		}
		mx=max(mx,k);
	}
	printf("-1\n");
}