#include <bits/stdc++.h>

using namespace std;

const long long ma=10;
long long n,d,nn,ttl,a[10],p10[10],sq[169],zs;

int main()
{
	long long t,rr,i,j;
	
	p10[0]=1;
	for(i=1;i<ma;i++)
	{
		p10[i]=p10[i-1]*10;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&d,&n);
		ttl=0;
		for(nn=0;d;d/=10,nn++)
		{
			a[nn]=d%10;
			ttl+=a[nn];
		}
		for(;ttl<n;ttl+=9)
		{
			for(i=1;!a[i];i++);
			a[i]--;
			a[i-1]+=10;
		}
		for(i=1;i<=n;i++)
		{
			sq[i]=0;
		}
		zs=0;
		for(i=0;i<nn;i++)
		{
			for(j=0;j<a[i];j++)
			{
				zs=min(zs+1,n);
				sq[zs]+=p10[i];
			}
		}
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}