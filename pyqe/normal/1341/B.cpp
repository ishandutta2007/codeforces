#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[200069],ps[200069],inf=1e18;

int main()
{
	long long t,rr,i;
	pair<long long,long long> z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1]+(i>1&&i<n&&a[i]>a[i-1]&&a[i]>a[i+1]);
		}
		z={-inf,-inf};
		for(i=1;i<=n-d+1;i++)
		{
			z=max(z,{ps[i+d-2]-ps[i]+1,-i});
		}
		printf("%lld %lld\n",z.fr,-z.sc);
	}
}