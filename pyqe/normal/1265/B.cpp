#include <bits/stdc++.h>

using namespace std;

long long n,pst[200069];

int main()
{
	long long t,rr,i,k,mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			pst[k]=i;
		}
		mn=1e18;
		mx=-1e18;
		for(i=1;i<=n;i++)
		{
			mn=min(mn,pst[i]);
			mx=max(mx,pst[i]);
			if(mx-mn+1==i)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
}