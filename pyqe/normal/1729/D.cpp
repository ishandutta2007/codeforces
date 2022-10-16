#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],as[100069];

int main()
{
	long long t,rr,i,ii,l,p,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			as[i]=a[1][i]-a[0][i];
		}
		sort(as+1,as+n+1);
		z=0;
		l=0;
		for(i=n;i;i--)
		{
			p=lower_bound(as+1,as+n+1,-as[i])-as;
			p=max(p,l+1);
			if(p>=i)
			{
				break;
			}
			z++;
			l=p;
		}
		printf("%lld\n",z);
	}
}