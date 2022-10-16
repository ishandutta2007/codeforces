#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=100,a[169];

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		a[n+1]=0;
		if(d>n*ma)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i<d;i++)
		{
			for(j=1;j<=n&&a[j]>=a[j+1];j++);
			if(j<=n)
			{
				a[j]++;
			}
		}
		if(j>n)
		{
			j=-1;
		}
		printf("%lld\n",j);
	}
}