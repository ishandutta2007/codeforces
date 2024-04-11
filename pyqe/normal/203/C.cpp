#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[2],zs=0;
pair<long long,long long> as[100069];

int main()
{
	long long i,ii,k,w;
	
	scanf("%lld%lld",&n,&d);
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",a+ii);
	}
	for(i=1;i<=n;i++)
	{
		w=0;
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&k);
			w+=k*a[ii];
		}
		as[i]={w,i};
	}
	sort(as+1,as+n+1);
	for(zs=0;zs<n&&d>=as[zs+1].fr;zs++,d-=as[zs].fr);
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",as[i].sc," \n"[i==zs]);
	}
}