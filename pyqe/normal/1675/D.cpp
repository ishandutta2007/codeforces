#include <bits/stdc++.h>

using namespace std;

long long n,pr[200069],dg[200069],zs;
vector<long long> sq[200069];
bitset<200069> vtd;

int main()
{
	long long t,rr,i,j,sz,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			dg[i]=0;
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",pr+i);
			dg[pr[i]]+=pr[i]!=i;
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(!dg[i])
			{
				zs++;
				sq[zs].clear();
				for(p=i;!vtd[p];p=pr[p])
				{
					vtd[p]=1;
					sq[zs].push_back(p);
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			sz=sq[i].size();
			printf("%lld\n",sz);
			for(j=sz-1;j>=0;j--)
			{
				printf("%lld%c",sq[i][j]," \n"[!j]);
			}
		}
	}
}