#include <bits/stdc++.h>

using namespace std;

int n,nn[201],ma=200,a[200001],vl[201][200001],ps[200001],inf=1e9;

int main()
{
	int t,rr,i,j,r,z;
	
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d",&n);
		for(i=1;i<=ma;i++)
		{
			nn[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			nn[a[i]]++;
			vl[a[i]][nn[a[i]]]=i;
		}
		z=-inf;
		for(i=1;i<=ma;i++)
		{
			for(j=1;j<=n;j++)
			{
				ps[j]=ps[j-1]+(a[j]==i);
			}
			for(j=1;j<=ma;j++)
			{
				z=max(z,nn[j]);
				for(r=1;r<nn[j]+1-r;r++)
				{
					z=max(z,r*2+ps[vl[j][nn[j]+1-r]-1]-ps[vl[j][r]]);
				}
			}
		}
		printf("%d\n",z);
	}
}