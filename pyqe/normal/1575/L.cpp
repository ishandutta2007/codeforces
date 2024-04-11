#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,lis[200069];
pair<long long,long long> a[200069];

int main()
{
	long long i,k,p,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		k=i-k;
		a[i]={i-k,-k};
		lis[i]=inf;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=-a[i].sc;
		if(a[i].fr>0&&k>=0)
		{
			p=upper_bound(lis+1,lis+n+1,k)-lis;
			z=max(z,p);
			lis[p]=k;
		}
	}
	printf("%lld\n",z);
}