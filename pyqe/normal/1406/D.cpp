#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e15,a[100069];

int main()
{
	long long t,rr,i,ii,k,l,w,sm=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i-1;i--)
	{
		a[i]-=a[i-1];
		sm+=max(a[i],0ll);
	}
	scanf("%lld",&t);
	for(rr=0;rr<=t;rr++)
	{
		if(rr)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			l++;
			for(ii=0;ii<2;ii++)
			{
				if(k<=n)
				{
					if(k-1)
					{
						sm+=max(a[k]+w,0ll)-max(a[k],0ll);
					}
					a[k]+=w;
				}
				swap(k,l);
				w*=-1;
			}
		}
		printf("%lld\n",(a[1]+sm+ma*2+1)/2-ma);
	}
}