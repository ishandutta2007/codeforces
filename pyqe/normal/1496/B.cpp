#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i,k,p,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n&&a[i]==i-1;i++);
		if(i<=n)
		{
			k=(a[n]+i)/2;
			p=lower_bound(a+1,a+n+1,k)-a;
			z=n+(d&&(p>n||a[p]!=k));
		}
		else
		{
			z=n+d;
		}
		printf("%lld\n",z);
	}
}