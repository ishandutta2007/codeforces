#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<269> a[269];

int main()
{
	long long i,j,ii,jj,k,c=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			a[i][j]=k;
			if(i-1&&j-1)
			{
				c+=a[i][j]^a[i-1][j]^a[i][j-1]^a[i-1][j-1];
			}
		}
	}
	for(i=n;i&&c;i--)
	{
		for(j=m;j&&c;j--)
		{
			a[i][j]=!a[i][j];
			for(ii=i==1;ii<=(i<n);ii++)
			{
				for(jj=j==1;jj<=(j<m);jj++)
				{
					c+=(a[i+ii][j+jj]^a[i+ii-1][j+jj]^a[i+ii][j+jj-1]^a[i+ii-1][j+jj-1])*2-1;
				}
			}
		}
	}
	if(!c)
	{
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld",(long long)a[i][1]);
		}
		printf("\n");
		for(i=1;i<=m;i++)
		{
			printf("%lld",(long long)a[1][i]^a[1][1]);
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
}