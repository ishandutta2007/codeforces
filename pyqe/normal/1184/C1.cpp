#include <bits/stdc++.h>

using namespace std;

long long n,a[1069][2],mn[2],mx[2];

int main()
{
	long long i,j,ii;
	
	scanf("%lld",&n);
	n=n*4+1;
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			mn[ii]=1e18;
			mx[ii]=-1e18;
		}
		for(j=1;j<=n;j++)
		{
			if(j!=i)
			{
				for(ii=0;ii<2;ii++)
				{
					mn[ii]=min(mn[ii],a[j][ii]);
					mx[ii]=max(mx[ii],a[j][ii]);
				}
			}
		}
		for(j=1;j<=n;j++)
		{
			if(j!=i)
			{
				if(a[j][0]>mn[0]&&a[j][0]<mx[0]&&a[j][1]>mn[1]&&a[j][1]<mx[1])
				{
					j=-1;
					break;
				}
			}
		}
		if(j!=-1&&mx[0]-mn[0]==mx[1]-mn[1])
		{
			break;
		}
	}
	printf("%lld %lld\n",a[i][0],a[i][1]);
}