#include <bits/stdc++.h>

using namespace std;

const long long ma=1e6;
long long n;
bitset<1000069> vtd;

int main()
{
	long long i,j,k,gd,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		vtd[k]=1;
	}
	for(i=1;i<=ma;i++)
	{
		gd=0;
		for(j=i;j<=ma;j+=i)
		{
			if(vtd[j])
			{
				gd=__gcd(gd,j);
			}
		}
		z+=!vtd[i]&&gd==i;
	}
	printf("%lld\n",z);
}