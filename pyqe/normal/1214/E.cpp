#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],zs=0;
pair<long long,long long> ds[100069],sq[100069];

int main()
{
	long long i,k,pz,tg,mx;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&ds[i].fr);
		ds[i].sc=i;
	}
	sort(ds+1,ds+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		pz=ds[i].sc;
		a[i]=pz*2-1;
		if(i>1)
		{
			zs++;
			sq[zs]={a[i-1],a[i]};
		}
	}
	mx=n;
	for(i=1;i<=n;i++)
	{
		k=ds[i].fr;
		pz=ds[i].sc;
		tg=i+k-1;
		zs++;
		sq[zs]={a[tg],pz*2};
		if(tg==mx)
		{
			mx++;
			a[mx]=pz*2;
		}
	}
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}