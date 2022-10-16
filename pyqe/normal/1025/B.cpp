#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,a[150069][2],ex[100069];

void chk(long long x)
{
	long long i;
	
	for(i=1;i<=nn;i++)
	{
		if(x%ex[i]==0)
		{
			return;
		}
	}
	nn++;
	ex[nn]=x;
}

int main()
{
	long long i,j,ii;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=2;i*i<=a[1][ii];i++)
		{
			if(a[1][ii]%i==0)
			{
				chk(i);
			}
		}
		for(i--;i;i--)
		{
			if(a[1][ii]%i==0)
			{
				chk(a[1][ii]/i);
			}
		}
	}
	for(i=1;i<=nn;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[j][0]%ex[i]&&a[j][1]%ex[i])
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			printf("%lld\n",ex[i]);
			return 0;
		}
	}
	printf("-1\n");
}