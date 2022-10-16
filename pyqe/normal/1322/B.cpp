#include <bits/stdc++.h>

using namespace std;

long long n,nn[2],a[400069],rx[2][400069],dv;

int main()
{
	long long i,j,ii,u,p[3],sm,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<25;i++)
	{
		dv=1<<i+1;
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		for(j=1;j<=n;j++)
		{
			u=a[j]>>i&1;
			nn[u]++;
			rx[u][nn[u]]=a[j];
		}
		n=0;
		for(ii=0;ii<2;ii++)
		{
			for(j=1;j<=nn[ii];j++)
			{
				n++;
				a[n]=rx[ii][j];
			}
		}
		sm=0;
		for(ii=0;ii<3;ii++)
		{
			p[ii]=0;
		}
		for(j=n;j;j--)
		{
			for(ii=0;ii<3;ii++)
			{
				for(;p[ii]<j-1&&a[j]%dv+a[p[ii]+1]%dv<dv/2*(ii+1);p[ii]++);
				p[ii]=min(p[ii],j-1);
			}
			sm^=(j-1-p[2]+p[1]-p[0])&1;
		}
		z|=sm<<i;
	}
	printf("%lld\n",z);
}