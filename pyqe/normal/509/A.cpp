#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a[10][10],i,j,n;
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(i==0||j==0)
			{
				a[i][j]=1;
			}
			else
			{
				a[i][j]=a[i-1][j]+a[i][j-1];
			}
		}
	}
	scanf("%lld",&n);
	printf("%lld\n",a[n-1][n-1]);
}