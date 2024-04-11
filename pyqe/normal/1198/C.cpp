#include <bits/stdc++.h>

using namespace std;

long long n,m,zs=0;
bitset<300069> vtd;
vector<long long> sq;

int main()
{
	long long t,rr,i,k,l,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n*3;i++)
		{
			vtd[i]=0;
		}
		sq.clear();
		zs=0;
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&k,&l);
			if(!vtd[k]&&!vtd[l])
			{
				sq.push_back(i);
				zs++;
				vtd[k]=1;
				vtd[l]=1;
			}
		}
		if(zs>=n)
		{
			printf("Matching\n");
			for(i=0;i<n;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==zs-1]);
			}
		}
		else
		{
			printf("IndSet\n");
			c=0;
			for(i=1;i<=n*3;i++)
			{
				if(!vtd[i])
				{
					c++;
					printf("%lld%c",i," \n"[c==n]);
					if(c==n)
					{
						break;
					}
				}
			}
		}
	}
}