#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,as[200069];
pair<long long,long long> a[200069];

bool cmp(long long x,long long y)
{
	return mp(a[x].fr,-a[x].sc)<mp(a[y].fr,-a[y].sc);
}

int main()
{
	long long i,k,l,mx=-1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
		as[i]=i;
	}
	sort(as+1,as+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		l=a[as[i]].sc;
		if(l<=mx)
		{
			printf("%lld\n",as[i]);
			return 0;
		}
		mx=max(mx,l);
	}
	for(i=2;i<n;i++)
	{
		if(a[as[i+1]].fr-a[as[i-1]].sc<=1)
		{
			printf("%lld\n",as[i]);
			return 0;
		}
	}
	printf("-1\n");
}