#include <bits/stdc++.h>

using namespace std;

long long n,ky[9]={1,2,4,5,3,8,9,6,7},sq[1069][1069];

int main()
{
	long long i,j,y,x,c;
	
	scanf("%lld",&n);
	if(n<3)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			sq[i][j]=n*n-9+ky[(i-1)*3+j-1];
		}
	}
	c=n*n-9;
	for(i=4;i<=n;i++)
	{
		for(j=1;j<=i*2-1;j++)
		{
			y=i;
			x=j;
			if(j>i)
			{
				y-=j-i;
				x-=j-i;
			}
			if(i%2)
			{
				swap(y,x);
			}
			sq[y][x]=c;
			c--;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%lld%c",sq[i][j]," \n"[j==n]);
		}
	}
}