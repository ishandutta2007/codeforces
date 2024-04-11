#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,r,n,k,c,z;
	
	scanf("%lld",&t);
	for(r=0;r<t;r++)
	{
		scanf("%lld",&n);
		k=n;
		c=1;
		while(k>0)
		{
			k/=2;
			c*=2;
		}
		c--;
		z=n*(n+1)/2-2*c;
		printf("%lld\n",z);
	}
}