#include <bits/stdc++.h>

using namespace std;

long long n,m,d,sq[2][200069],zs=0;

int main()
{
	long long i,ii;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	zs=n+m;
	for(ii=0;ii<2;ii++)
	{
		sq[ii][zs]=1;
	}
	m--;
	if(d)
	{
		if(d>zs-2||!m)
		{
			printf("No\n");
			return 0;
		}
		sq[0][d+1]=1;
		sq[1][1]=1;
		m--;
	}
	for(i=1;i<=zs;i++)
	{
		if(m&&!sq[0][i]&&!sq[1][i])
		{
			for(ii=0;ii<2;ii++)
			{
				sq[ii][i]=1;
			}
			m--;
		}
	}
	if(m)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(ii=0;ii<2;ii++)
	{
		for(i=zs;i;i--)
		{
			printf("%lld",sq[ii][i]);
		}
		printf("\n");
	}
}