#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[1069],aa[1069];

int main()
{
	long long t,rr,i,ii,k,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+m+1);
		mn=1e18;
		for(ii=0;ii<2;ii++)
		{
			k=d;
			for(i=1;i<=m;i++)
			{
				if(a[i]==k)
				{
					k++;
				}
				aa[m+1-i]=n+1-a[i];
			}
			if(k<=n)
			{
				mn=min(mn,k-d);
			}
			d=n+1-d;
			for(i=1;i<=m;i++)
			{
				a[i]=aa[i];
			}
		}
		printf("%lld\n",mn);
	}
}