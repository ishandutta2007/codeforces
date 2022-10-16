#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[1069][1069];
bool flp=0;

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&m);
	if(n==1&&m==1)
	{
		printf("0\n");
		return 0;
	}
	if(n>m)
	{
		swap(n,m);
		flp=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1)
			{
				k=1;
			}
			else
			{
				k=m+i;
			}
			k*=(j+1);
			if(flp)
			{
				swap(i,j);
			}
			sq[i][j]=k;
			if(flp)
			{
				swap(i,j);
			}
		}
	}
	if(flp)
	{
		swap(n,m);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%lld%c",sq[i][j]," \n"[j==m]);
		}
	}
}