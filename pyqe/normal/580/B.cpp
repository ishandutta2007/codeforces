#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ps[100069],inf=1e18;
pair<long long,long long> a[100069];

int main()
{
	long long i,j,k,l,z=-inf;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i].sc;
	}
	for(j=0,i=1;i<=n;i++)
	{
		for(;a[j+1].fr<=a[i].fr-d;j++);
		z=max(z,ps[i]-ps[j]);
	}
	printf("%lld\n",z);
}