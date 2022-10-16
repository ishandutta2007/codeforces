#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,zs=0;
bitset<1069> a[1069],vtd[1069];
vector<pair<long long,long long>> sq;

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			a[i][j]=k;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				if(a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
				{
					sq.push_back({i,j});
					zs++;
					vtd[i][j]=1;
				}
				else if(!vtd[i-1][j]&&!vtd[i][j-1]&&!vtd[i-1][j-1])
				{
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}