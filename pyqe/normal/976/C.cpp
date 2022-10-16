#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<pair<long long,long long>,long long> a[300069];

int main()
{
	long long i,k,l,pz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={{k,-l},i};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		l=-a[i].fr.sc;
		pz=a[i].sc;
		if(i-1&&l<=-a[i-1].fr.sc)
		{
			printf("%lld %lld\n",pz,a[i-1].sc);
			return 0;
		}
	}
	printf("-1 -1\n");
}