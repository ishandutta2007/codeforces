#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069];

int main()
{
	long long t,rr,i,ii,lh,rh;
	bool bad;
	
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
		lh=n+1;
		rh=0;
		bad=0;
		for(i=1;i<=n;i++)
		{
			if(a[1][i]>a[0][i])
			{
				lh=min(lh,i);
				rh=i;
			}
			else if(a[1][i]<a[0][i])
			{
				bad=1;
				break;
			}
		}
		for(i=lh;i<=rh;i++)
		{
			if(a[1][i]-a[0][i]!=a[1][lh]-a[0][lh])
			{
				bad=1;
				break;
			}
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}