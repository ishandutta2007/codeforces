#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,j,lh,rh,md,zz,y1,x1,y2,x2;
	string s;
	bool bad;
	
	scanf("%lld%lld",&n,&m);
	bool a[n+1][m+1],sq[n+1][m+1];
	long long ps[n+1][m+1],bn[n+1][m+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			a[i][j]=0;
			ps[i][j]=0;
			sq[i][j]=0;
			bn[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]=='X';
			ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+a[i][j];
		}
	}
	lh=0;
	rh=min(n,m);
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				y1=max(i-md,1ll);
				x1=max(j-md,1ll);
				y2=min(i+md,n);
				x2=min(j+md,m);
				if(ps[y2][x2]-ps[y1-1][x2]-ps[y2][x1-1]+ps[y1-1][x1-1]==(md*2+1)*(md*2+1))
				{
					sq[i][j]=1;
				}
				else
				{
					sq[i][j]=0;
				}
				bn[i][j]=bn[i-1][j]+bn[i][j-1]-bn[i-1][j-1]+sq[i][j];
			}
		}
		bad=0;
		for(i=1;!bad&&i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				y1=max(i-md,1ll);
				x1=max(j-md,1ll);
				y2=min(i+md,n);
				x2=min(j+md,m);
				if(a[i][j]&&bn[y2][x2]-bn[y1-1][x2]-bn[y2][x1-1]+bn[y1-1][x1-1]==0)
				{
					bad=1;
					break;
				}
			}
		}
		if(bad)
		{
			rh=md-1;
		}
		else
		{
			zz=md;
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			y1=max(i-zz,1ll);
			x1=max(j-zz,1ll);
			y2=min(i+zz,n);
			x2=min(j+zz,m);
			if(ps[y2][x2]-ps[y1-1][x2]-ps[y2][x1-1]+ps[y1-1][x1-1]==(zz*2+1)*(zz*2+1))
			{
				sq[i][j]=1;
			}
			else
			{
				sq[i][j]=0;
			}
			printf("%c",".X"[sq[i][j]]);
		}
		printf("\n");
	}
}