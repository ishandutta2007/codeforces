#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],fq[1000069],ps[1000069];

int main()
{
	long long i,j,k,l,ft,z;
	bool bad;
	
	scanf("%lld",&n);
	z=n*n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&m);
		bad=0;
		l=1e18;
		for(j=0;j<m;j++)
		{
			scanf("%lld",&k);
			k++;
			if(k>l)
			{
				bad=1;
			}
			if(!j)
			{
				ft=k;
			}
			l=k;
		}
		if(bad)
		{
			ft=1e6+2;
			l=0;
		}
		fq[ft]++;
		a[i]=l;
	}
	for(i=1;i<=1000001;i++)
	{
		ps[i]=ps[i-1]+fq[i];
	}
	for(i=1;i<=n;i++)
	{
		z-=ps[a[i]];
	}
	printf("%lld\n",z);
}