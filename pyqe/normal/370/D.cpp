#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[2069][2069],tmp[2069][2069],mn[3],mx[3],inf=1e18;

void mir()
{
	long long i,j;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			tmp[j][i]=a[i][j];
		}
	}
	swap(n,m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[i][j]=tmp[i][j];
		}
	}
}

long long chk(long long x)
{
	if(x<1||x+d>m||x>mn[1]||x+d<mx[1])
	{
		return -1;
	}
	else
	{
		return x;
	}
}

int main()
{
	long long i,j,ii,z=-1;
	bool bad=0;
	char ch;
	
	for(i=0;i<3;i++)
	{
		mn[i]=inf;
		mx[i]=-inf;
	}
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='w';
			if(a[i][j])
			{
				for(ii=0;ii<2;ii++)
				{
					mn[ii]=min(mn[ii],i);
					mx[ii]=max(mx[ii],i);
					swap(i,j);
				}
			}
		}
	}
	if(mx[1]-mn[1]>mx[0]-mn[0])
	{
		bad=1;
		mir();
		swap(mn[0],mn[1]);
		swap(mx[0],mx[1]);
	}
	d=mx[0]-mn[0];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i>mn[0]&&i<mx[0]&&a[i][j])
			{
				if(j>mn[1]&&j<mx[1])
				{
					printf("-1\n");
					return 0;
				}
				mn[2]=min(mn[2],j);
				mx[2]=max(mx[2],j);
			}
		}
	}
	if(mn[2]<mx[2]&&mx[2]-mn[2]!=d)
	{
		printf("-1\n");
		return 0;
	}
	if(mn[2]==mn[1])
	{
		z=chk(mn[1]);
	}
	if(z==-1&&mx[2]==mx[1])
	{
		z=chk(mx[1]-d);
	}
	if(mn[2]==inf)
	{
		z=chk(max(mx[1]-d,1ll));
	}
	if(z==-1)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[i][j]+=2*((i==mn[0]||i==mx[0]||j==z||j==z+d)&&i>=mn[0]&&i<=mx[0]&&j>=z&&j<=z+d&&!a[i][j]);
		}
	}
	if(bad)
	{
		mir();
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%c",".w+"[a[i][j]]);
		}
		printf("\n");
	}
}