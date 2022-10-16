#include <bits/stdc++.h>

using namespace std;

long long n,pst[200069];

int main()
{
	long long i,j,k,mx=0;
	bool bad;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pst[k]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(pst[i]==n)
		{
			bad=0;
			for(j=i-1;j;j--)
			{
				if(pst[j]!=pst[j+1]-1)
				{
					bad=1;
					break;
				}
			}
			for(j=i+1;j<=n;j++)
			{
				if(pst[j]>=j-i)
				{
					bad=1;
					break;
				}
			}
			if(!bad)
			{
				printf("%lld\n",n-i);
				return 0;
			}
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		mx=max(mx,pst[i]-i+1);
	}
	printf("%lld\n",mx+n);
}