#include <bits/stdc++.h>

using namespace std;

long long a[5][5];

int main()
{
	long long i,j;
	
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			printf("%lld",(a[i-1][j]+a[i][j-1]+a[i][j]+a[i+1][j]+a[i][j+1]+1)%2);
		}
		printf("\n");
	}
}