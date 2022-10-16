#include <bits/stdc++.h>

using namespace std;

long long n,m,d,nn[2],a[2][100069],ps[2][100069],inf=1e18;

int main()
{
	long long i,ii,k,e,z=-inf;
	
	scanf("%lld%lld%lld",&n,&d,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		e=k>m;
		nn[e]++;
		a[e][nn[e]]=k;
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii]+1,a[ii]+nn[ii]+1,greater<long long>());
		for(i=1;i<=nn[ii];i++)
		{
			ps[ii][i]=ps[ii][i-1]+a[ii][i];
		}
	}
	for(i=0;i*(d+1)-d<=n;i++)
	{
		z=max(z,ps[1][i]+ps[0][min(n-(i*(d+1)-d),nn[0])]);
	}
	printf("%lld\n",z);
}