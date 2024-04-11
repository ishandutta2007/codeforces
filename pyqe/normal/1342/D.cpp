#include <bits/stdc++.h>

using namespace std;

long long n,m,ub[200069],zs=0,inf=1e18;
multiset<long long> ms;
multiset<long long>::iterator it;
vector<long long> sq[200069];

int main()
{
	long long i,j,k,sz,c=inf;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		ms.insert(k);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",ub+i);
		ub[i]*=-1;
	}
	for(;!ms.empty();)
	{
		for(;1;c=0,zs++)
		{
			for(;1;c=0,zs++)
			{
				k=lower_bound(ub+1,ub+m+1,-c)-ub-1;
				if(k)
				{
					break;
				}
			}
			it=ms.upper_bound(k);
			if(it!=ms.begin())
			{
				it--;
				break;
			}
		}
		sq[zs].push_back(*it);
		ms.erase(it);
		c++;
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		sz=sq[i].size();
		printf("%lld",sz);
		for(j=0;j<sz;j++)
		{
			printf(" %lld",sq[i][j]);
		}
		printf("\n");
	}
}