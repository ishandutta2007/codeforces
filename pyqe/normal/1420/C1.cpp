#include <bits/stdc++.h>

using namespace std;

long long n,a[300069];

int main()
{
	long long tt,rrr,t,rr,i,sm;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		a[n+1]=0;
		sm=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])
			{
				sm+=a[i];
			}
			else if(a[i]<a[i-1]&&a[i]<a[i+1])
			{
				sm-=a[i];
			}
		}
		printf("%lld\n",sm);
	}
}