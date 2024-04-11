#include <bits/stdc++.h>

using namespace std;

long long n,m,zs;
bitset<1069> a[1069];
array<long long,4> sq[1000069];

int main()
{
	long long t,rr,i,j;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch-'0';
			}
		}
		if(a[1][1])
		{
			printf("-1\n");
			continue;
		}
		zs=0;
		for(i=n;i;i--)
		{
			for(j=m;j;j--)
			{
				if(a[i][j])
				{
					zs++;
					if(i>1)
					{
						sq[zs]={i-1,j,i,j};
					}
					else
					{
						sq[zs]={i,j-1,i,j};
					}
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			for(j=0;j<4;j++)
			{
				printf("%lld%c",sq[i][j]," \n"[j==3]);
			}
		}
	}
}