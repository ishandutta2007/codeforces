#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[100069][4],ps[4][100069],qq[4];

int main()
{
	long long i,j,r;
	
	scanf("%lld%lld%lld",&d,&n,&m);
	for(i=1;i<=d;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%lld",&a[i][j]);
		}
		for(j=0;j<2;j++)
		{
			if(a[i][j]>a[i][j+2])
			{
				swap(a[i][j],a[i][j+2]);
			}
		}
		for(j=0;j<4;j++)
		{
			ps[j][a[i][0]]++;
			for(r=0;r<4;r+=2)
			{
				a[i][r]=n+1-a[i][r];
			}
			for(r=0;r<3;r++)
			{
				swap(a[i][r],a[i][r+1]);
			}
			swap(n,m);
		}
	}
	for(i=0;i<4;i++)
	{
		scanf("%lld",qq+i);
		for(j=1;j<=n;j++)
		{
			ps[i][j]+=ps[i][j-1];
		}
		swap(n,m);
	}
	swap(qq[1],qq[2]);
	for(i=1;i<=d;i++)
	{
		for(j=0;j<4;j++)
		{
			if(ps[j][a[i][2]-1]-(a[i][0]<a[i][2])!=qq[j])
			{
				if(j%2)
				{
					swap(n,m);
				}
				break;
			}
			for(r=0;r<4;r+=2)
			{
				a[i][r]=n+1-a[i][r];
			}
			for(r=0;r<3;r++)
			{
				swap(a[i][r],a[i][r+1]);
			}
			swap(n,m);
		}
		if(j==4)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("-1\n");
}