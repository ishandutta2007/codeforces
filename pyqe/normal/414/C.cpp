#include <bits/stdc++.h>

using namespace std;

long long n,a[1<<20],d[21][2],tmp[1<<20];
bitset<21> rv;

int main()
{
	long long t,rr,i,j,r,ii,k,p,c,z;
	
	scanf("%lld",&n);
	for(i=0;i<1<<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<1<<n;j+=1<<i)
		{
			for(ii=0;ii<2;ii++)
			{
				c=0;
				for(p=0,r=0;r<1<<i-1;r++)
				{
					for(;p<1<<i-1&&a[j+p+(!ii<<i-1)]<a[j+r+(ii<<i-1)];p++)
					{
						tmp[c]=a[j+p+(!ii<<i-1)];
						c++;
					}
					d[i][ii]+=p;
					tmp[c]=a[j+r+(ii<<i-1)];
					c++;
				}
			}
			for(r=0;r<1<<i;r++)
			{
				a[j+r]=tmp[r];
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		z=0;
		for(i=1;i<=n;i++)
		{
			if(i<=k)
			{
				rv[i]=!rv[i];
			}
			z+=d[i][rv[i]];
		}
		printf("%lld\n",z);
	}
}