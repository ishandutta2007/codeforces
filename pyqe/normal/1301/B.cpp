#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,mn,mx,mdf,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		a[n+1]=0;
		mn=1e18;
		mx=-1e18;
		mdf=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=-1&&(a[i-1]==-1||a[i+1]==-1))
			{
				mn=min(mn,a[i]);
				mx=max(mx,a[i]);
			}
			if(i<n&&a[i]!=-1&&a[i+1]!=-1)
			{
				mdf=max(mdf,abs(a[i]-a[i+1]));
			}
		}
		if(mn==1000000000000000000)
		{
			printf("%lld 0\n",mdf);
		}
		else
		{
			z=(mn+mx)/2;
			printf("%lld %lld\n",max(max(mx-z,z-mn),mdf),z);
		}
	}
}