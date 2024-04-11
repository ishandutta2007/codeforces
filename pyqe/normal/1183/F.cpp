#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],d[3],p,z,mx;

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a,a+n,greater<long long>());
		mx=0;
		p=0;
		z=0;
		for(i=0;i<n&&p<3;i++)
		{
			for(j=0;j<p;j++)
			{
				if(d[j]%a[i]==0)
				{
					j=-1;
					break;
				}
			}
			if(j==-1)
			{
				continue;
			}
			d[p]=a[i];
			z+=a[i];
			p++;
		}
		mx=max(mx,z);
		p=0;
		z=0;
		for(i=0;i<n&&p<3;i++)
		{
			for(j=0;j<p;j++)
			{
				if(d[j]%a[i]==0)
				{
					j=-1;
					break;
				}
			}
			if(j==-1||a[i]==a[0])
			{
				continue;
			}
			d[p]=a[i];
			z+=a[i];
			p++;
		}
		mx=max(mx,z);
		printf("%lld\n",mx);
	}
}