#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069];
vector<long long> vl[2500069];
vector<pair<long long,long long>> sq[2500069];

int main()
{
	long long i,j,r,k,sz,p,p2;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		vl[a[i]].push_back(i);
		sz=vl[a[i]].size();
		if(sz>=4)
		{
			printf("YES\n");
			for(j=0;j<4;j++)
			{
				printf("%lld%c",vl[a[i]][j]," \n"[j==3]);
			}
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i!=j&&a[i]<=a[j])
			{
				k=a[j]-a[i];
				sz=sq[k].size();
				for(r=0;r<sz;r++)
				{
					p=sq[k][r].fr;
					p2=sq[k][r].sc;
					if(i!=p&&i!=p2&&j!=p&&j!=p2)
					{
						printf("YES\n%lld %lld %lld %lld\n",i,p2,j,p);
						return 0;
					}
				}
				sq[k].push_back({i,j});
			}
		}
	}
	printf("NO\n");
}