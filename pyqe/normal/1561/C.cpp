#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[100069];

int main()
{
	long long t,rr,i,j,k,l,sz,mx,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&sz);
			mx=0;
			for(j=0;j<sz;j++)
			{
				scanf("%lld",&k);
				mx=max(mx,k+1-j);
			}
			a[i]={mx,sz};
		}
		sort(a+1,a+n+1);
		sm=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			k=a[i].fr;
			l=a[i].sc;
			z+=max(k-sm,0ll);
			sm=max(sm,k);
			sm+=l;
		}
		printf("%lld\n",z);
	}
}