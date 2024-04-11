#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;

long long lcm(long long x,long long y)
{
	return x*y/__gcd(x,y);
}

int main()
{
	long long i,j,k,lm,z=-1e18;
	
	scanf("%lld",&n);
	for(i=0;i<4;i++)
	{
		lm=1;
		for(j=0;j<3;j++)
		{
			k=n-j-(j>=i);
			if(k>0)
			{
				lm=lcm(lm,k);
			}
		}
		z=max(z,lm);
	}
	printf("%lld\n",z);
}