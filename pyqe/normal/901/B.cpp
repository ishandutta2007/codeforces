#include <bits/stdc++.h>

using namespace std;

long long n,sq[3][169];

int main()
{
	long long i,j,ii,u;
	
	scanf("%lld",&n);
	sq[1][0]=1;
	for(i=1;i<=n;i++)
	{
		u=1;
		for(j=1;j<=i-2;j++)
		{
			if(sq[0][j]&&sq[0][j]==sq[1][j-1])
			{
				u=-1;
				break;
			}
		}
		for(j=0;j<=i;j++)
		{
			sq[2][j]=sq[0][j]*u;
			if(j)
			{
				sq[2][j]+=sq[1][j-1];
			}
		}
		for(j=0;j<=i;j++)
		{
			sq[0][j]=sq[1][j];
			sq[1][j]=sq[2][j];
		}
	}
	for(ii=0;ii<2;ii++)
	{
		printf("%lld\n",n-ii);
		for(i=0;i<=n-ii;i++)
		{
			printf("%lld%c",sq[!ii][i]," \n"[i==n-ii]);
		}
	}
}