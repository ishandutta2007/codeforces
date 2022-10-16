#include <bits/stdc++.h>

using namespace std;

long long n,zs[2];
vector<long long> sq[2];

int main()
{
	long long t,rr,i,j,ii,k,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mx=0;
		for(i=1;i<=n;i*=2)
		{
			for(ii=0;ii<2;ii++)
			{
				sq[ii].clear();
				zs[ii]=0;
			}
			for(j=1;j<=n;j++)
			{
				k=j/i%2;
				sq[k].push_back(j);
				zs[k]++;
			}
			printf("%lld %lld",zs[0],zs[1]);
			for(ii=0;ii<2;ii++)
			{
				for(j=0;j<zs[ii];j++)
				{
					printf(" %lld",sq[ii][j]);
				}
			}
			printf("\n");
			fflush(stdout);
			scanf("%lld",&k);
			mx=max(mx,k);
		}
		printf("-1 %lld\n",mx);
		fflush(stdout);
	}
}