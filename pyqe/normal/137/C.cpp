#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,sk[100069];
pair<long long,long long> a[100069];

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		for(;nn&&a[sk[nn]].fr>=k&&a[sk[nn]].sc<=l;nn--);
		if(!nn||l>a[sk[nn]].sc)
		{
			nn++;
			sk[nn]=i;
		}
	}
	printf("%lld\n",n-nn);
}