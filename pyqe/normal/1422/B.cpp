#include <bits/stdc++.h>

using namespace std;

long long n,m,nn[1069][1069],a[1069][1069][5];

int main()
{
	long long t,rr,i,j,r,k,y,x,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&k);
				nn[i][j]=0;
				y=min(i,n+1-i);
				x=min(j,m+1-j);
				nn[y][x]++;
				a[y][x][nn[y][x]]=k;
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				sort(a[i][j]+1,a[i][j]+nn[i][j]+1);
				for(r=1;r<=nn[i][j];r++)
				{
					z+=abs(a[i][j][r]-a[i][j][(nn[i][j]+1)/2]);
				}
			}
		}
		printf("%lld\n",z);
	}
}