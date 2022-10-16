#include <bits/stdc++.h>

using namespace std;

long long n,d,nn[2],a[200069],as[2][200069],ps[2][200069],inf=1e18;

int main()
{
	long long t,rr,i,j,ii,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			nn[k-1]++;
			as[k-1][nn[k-1]]=a[i];
		}
		for(ii=0;ii<2;ii++)
		{
			sort(as[ii]+1,as[ii]+nn[ii]+1,greater<long long>());
			for(i=1;i<=nn[ii];i++)
			{
				ps[ii][i]=ps[ii][i-1]+as[ii][i];
			}
		}
		z=inf;
		for(j=nn[1]+1,i=0;i<=nn[0];i++)
		{
			for(;j&&ps[0][i]+ps[1][j-1]>=d;j--);
			if(j<=nn[1])
			{
				z=min(z,i+j*2);
			}
		}
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}