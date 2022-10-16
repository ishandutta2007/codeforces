#include <bits/stdc++.h>

using namespace std;

long long n[3],nn[3],fz[3][100069],inf=1e18;

int main()
{
	long long i,ii,p[2]={0,0},z=inf;
	
	scanf("%lld%lld",n,n+1);
	n[2]=n[0]+n[1];
	for(ii=0;ii<3;ii++)
	{
		for(i=1;i*i<=n[ii];i++)
		{
			if(n[ii]%i==0)
			{
				nn[ii]++;
				fz[ii][nn[ii]]=i;
			}
		}
		for(i--,i-=i*i==n[ii];i;i--)
		{
			if(n[ii]%i==0)
			{
				nn[ii]++;
				fz[ii][nn[ii]]=n[ii]/i;
			}
		}
	}
	for(i=1;i<=nn[2];i++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(;p[ii]<nn[ii]&&fz[ii][p[ii]+1]<=fz[2][i];p[ii]++);
			if(p[ii]&&n[ii]/fz[ii][p[ii]]<=n[2]/fz[2][i])
			{
				z=min(z,(fz[2][i]+n[2]/fz[2][i])*2);
			}
		}
	}
	printf("%lld\n",z);
}