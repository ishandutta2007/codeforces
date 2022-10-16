#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,sk[200069];

int main()
{
	long long i,k,mx=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(!nn||sk[nn]>k)
		{
			nn++;
			sk[nn]=k;
		}
		else if(sk[nn]==k)
		{
			nn--;
		}
		else
		{
			printf("NO\n");
			return 0;
		}
		mx=max(mx,k);
	}
	if(nn<=1&&(!nn||sk[nn]==mx))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}