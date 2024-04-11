#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[100069],as[100069],inf=1e18;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		nn=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(!k)
			{
				nn++;
				as[nn]=a[i];
				a[i]=-inf;
			}
		}
		sort(as+1,as+nn+1);
		for(i=1;i<=n;i++)
		{
			if(a[i]==-inf)
			{
				a[i]=as[nn];
				nn--;
			}
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
}