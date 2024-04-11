#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,nn[2],a[2][100069];
bitset<100069> kd;

int main()
{
	long long t,rr,i,ii,k,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			kd[i]=k;
		}
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		z=0;
		mn=inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			nn[kd[i]]++;
			a[kd[i]][nn[kd[i]]]=k;
			z+=k;
			mn=min(mn,k);
		}
		for(ii=0;ii<2;ii++)
		{
			sort(a[ii]+1,a[ii]+nn[ii]+1,greater<long long>());
			for(i=1;i<=min(nn[0],nn[1]);i++)
			{
				z+=a[ii][i];
			}
		}
		if(nn[0]==nn[1])
		{
			z-=mn;
		}
		printf("%lld\n",z);
	}
}