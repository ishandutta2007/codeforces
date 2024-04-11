#include <bits/stdc++.h>

using namespace std;

long long n,d,a[569];

int main()
{
	long long t,rr,i,j,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[j]<a[j-1])
				{
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				break;
			}
			if(a[i]>d)
			{
				z++;
				swap(a[i],d);
			}
		}
		for(i=2;i<=n;i++)
		{
			if(a[i]<a[i-1])
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}