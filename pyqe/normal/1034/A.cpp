#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],fq[15000069];
bitset<15000000> vtd;

int main()
{
	long long i,j,gd=0,mn=1e18,c,cc=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		gd=__gcd(gd,a[i]);
	}
	for(i=0;i<n;i++)
	{
		a[i]/=gd;
		fq[a[i]]++;
	}
	for(i=2;i<=15000000;i++)
	{
		if(!vtd[i])
		{
			c=0;
			for(j=i;j<=15000000;j+=i)
			{
				cc++;
				c+=fq[j];
				vtd[j]=1;
			}
			mn=min(mn,n-c);
		}
	}
	if(mn==n)
	{
		mn=-1;
	}
	printf("%lld\n",mn);
}