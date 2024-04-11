#include <bits/stdc++.h>

using namespace std;

long long n,m,a[569][569],sq[569][2];

int main()
{
	long long i,j,r,ii,k;
	bool bad;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(r=0;r<10;r++)
	{
		bad=1;
		k=1;
		for(i=1;i<=n;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				sq[i][ii]=-1;
			}
			for(j=1;j<=m;j++)
			{
				sq[i][(a[i][j]>>r)%2]=j;
			}
			for(ii=0;ii<2;ii++)
			{
				if(sq[i][ii]==-1)
				{
					k^=!ii;
				}
			}
			if(sq[i][0]!=-1&&sq[i][1]!=-1)
			{
				bad=0;
			}
		}
		if(!k||!bad)
		{
			printf("TAK\n");
			if(!k)
			{
				bad=1;
			}
			for(i=1;i<=n;i++)
			{
				for(ii=0;ii<2;ii++)
				{
					if(sq[i][ii]==-1)
					{
						printf("%lld",sq[i][!ii]);
					}
				}
				if(sq[i][0]!=-1&&sq[i][1]!=-1)
				{
					printf("%lld",sq[i][!bad]);
					bad=1;
				}
				printf("%c"," \n"[i==n]);
			}
			return 0;
		}
	}
	printf("NIE\n");
}