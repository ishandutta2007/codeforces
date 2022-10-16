#include <bits/stdc++.h>

using namespace std;

long long n[2],d[2],nn=0,a[2][69],as[3669],lb,rb,inf=1e18;

int main()
{
	long long i,j,ii,z=-inf;
	
	scanf("%lld%lld%lld%lld",d,d+1,&lb,&rb);
	for(ii=0;ii<2;ii++)
	{
		n[ii]++;
		a[ii][n[ii]]=1;
		for(;a[ii][n[ii]]<=rb/d[ii];)
		{
			n[ii]++;
			a[ii][n[ii]]=a[ii][n[ii]-1]*d[ii];
		}
	}
	for(i=1;i<=n[0];i++)
	{
		for(j=1;j<=n[1];j++)
		{
			nn++;
			as[nn]=a[0][i]+a[1][j];
		}
	}
	sort(as+1,as+nn+1);
	as[nn+1]=inf*3;
	for(i=1;i<=nn+1;i++)
	{
		z=max(z,max(min(as[i]-1,rb)-max(as[i-1],lb-1),0ll));
	}
	printf("%lld\n",z);
}