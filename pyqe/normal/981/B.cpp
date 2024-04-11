#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n=0;
pair<long long,long long> a[200069];

int main()
{
	long long i,ii,k,l,sz,z=0;
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",&sz);
		for(i=1;i<=sz;i++)
		{
			scanf("%lld%lld",&k,&l);
			a[n+i]={k,l};
		}
		n+=sz;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(i==n||a[i].fr!=a[i+1].fr)
		{
			z+=a[i].sc;
		}
	}
	printf("%lld\n",z);
}