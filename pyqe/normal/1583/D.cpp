#include <bits/stdc++.h>

using namespace std;

long long n,pr[169],sq[169];
bitset<169> vtd;

void dfs(long long x)
{
	vtd[x]=1;
	if(!vtd[pr[x]])
	{
		dfs(pr[x]);
	}
	sq[x]=sq[pr[x]]-1;
}

int main()
{
	long long i,j,ii,k;
	
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			printf("?");
			for(j=1;j<=n;j++)
			{
				printf(" %lld",1ll+(j==i^ii));
			}
			printf("\n");
			fflush(stdout);
			scanf("%lld",&k);
			if(k<i&&k)
			{
				if(!ii)
				{
					pr[i]=k;
				}
				else
				{
					pr[k]=i;
				}
			}
		}
	}
	vtd[0]=1;
	sq[0]=n+1;
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	printf("!");
	for(i=1;i<=n;i++)
	{
		printf(" %lld",sq[i]);
	}
	printf("\n");
	fflush(stdout);
}