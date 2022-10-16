#include <bits/stdc++.h>

using namespace std;

long long n,a[300069];
bitset<300069> spc;

int main()
{
	long long t,rr,i,u,z,mx;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			spc[i]=i>1&&i<n&&((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]));
			z+=spc[i];
		}
		spc[n+1]=0;
		mx=0;
		for(i=1;i<=n;i++)
		{
			for(u=-1;u<=1;u+=2)
			{
				if(i+u&&i+u<=n)
				{
					bad=i-u>1&&i-u<n&&((a[i-u]>a[i-u*2]&&a[i-u]>a[i+u])||(a[i-u]<a[i-u*2]&&a[i-u]<a[i+u]));
					mx=max(mx,(long long)spc[i]+spc[i+u]+(spc[i-u]&&!bad)-(!spc[i-u]&&bad));
				}
			}
		}
		printf("%lld\n",z-mx);
	}
}