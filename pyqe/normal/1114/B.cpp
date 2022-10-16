#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,pst[200069],sq[200069],zs=0;
pair<long long,long long> as[200069];

int main()
{
	long long i,z=0,c=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&as[i].fr);
		as[i].sc=i;
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		if(i<=m*d)
		{
			z+=as[i].fr;
		}
		pst[as[i].sc]=i;
	}
	for(i=1;i<=n&&zs<d-1;i++)
	{
		if(pst[i]<=m*d)
		{
			c++;
			if(c==m)
			{
				zs++;
				sq[zs]=i;
				c=0;
			}
		}
	}
	printf("%lld\n",z);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}