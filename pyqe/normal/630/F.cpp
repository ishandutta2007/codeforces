#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,k,w,sm,gd,z=0;
	
	scanf("%lld",&n);
	for(i=5;i<=7;i++)
	{
		w=1;
		for(j=1;j<=i;j++)
		{
			w*=j;
		}
		sm=1;
		for(j=n;j>n-i;j--)
		{
			k=j;
			gd=__gcd(k,w);
			k/=gd;
			w/=gd;
			sm*=k;
		}
		z+=sm;
	}
	printf("%lld\n",z);
}