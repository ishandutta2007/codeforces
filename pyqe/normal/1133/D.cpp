#include <bits/stdc++.h>

using namespace std;

long long n,a[2][200069];
map<pair<long long,long long>,long long> fq;

int main()
{
	long long i,ii,gd,c=0,z=0;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		gd=__gcd(abs(a[0][i]),abs(a[1][i]));
		if(gd)
		{
			for(ii=0;ii<2;ii++)
			{
				a[ii][i]/=gd;
			}
		}
		if(a[0][i]<0||(!a[0][i]&&a[1][i]<0))
		{
			for(ii=0;ii<2;ii++)
			{
				a[ii][i]*=-1;
			}
		}
		if(a[0][i])
		{
			fq[{a[0][i],a[1][i]}]++;
			z=max(z,fq[{a[0][i],a[1][i]}]);
		}
		else if(!a[1][i])
		{
			c++;
		}
	}
	printf("%lld\n",z+c);
}