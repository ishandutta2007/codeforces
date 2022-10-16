#include <bits/stdc++.h>

using namespace std;

long long n,ls[200069];

int main()
{
	long long t,rr,i,k,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			ls[i]=0;
		}
		mn=1e18;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(ls[k])
			{
				mn=min(mn,i-ls[k]+1);
			}
			ls[k]=i;
		}
		if(mn==1000000000000000000)
		{
			mn=-1;
		}
		printf("%lld\n",mn);
	}
}