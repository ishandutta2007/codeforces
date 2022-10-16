#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069];

int main()
{
	long long i,lh,rh,md,zz,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",a+i,a+i);
	}
	for(lh=1,rh=m;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(md*(md-1)/2+(md/2-1)*(md%2==0)+1<=n)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	sort(a+1,a+m+1,greater<long long>());
	for(i=1;i<=zz;i++)
	{
		z+=a[i];
	}
	printf("%lld\n",z);
}