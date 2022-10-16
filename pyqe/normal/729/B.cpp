#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[2][1069],mn[2][1069],mx[2][1069];

int main()
{
	long long i,j,ii,k,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			mn[ii][i]=1e18;
			mx[ii][i]=-1e18;
		}
		swap(n,m);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			if(k)
			{
				for(ii=0;ii<2;ii++)
				{
					fq[ii][i]+=k;
					mn[ii][i]=min(mn[ii][i],j);
					mx[ii][i]=max(mx[ii][i],j);
					swap(i,j);
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		
		for(i=1;i<=n;i++)
		{
			z+=max(m-(mn[ii][i]-1)-fq[ii][i]+mx[ii][i]-fq[ii][i],0ll);
		}
		swap(n,m);
	}
	printf("%lld\n",z);
}