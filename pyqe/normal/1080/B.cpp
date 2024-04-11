#include <bits/stdc++.h>

using namespace std;

long long k;

long long f(long long a)
{
	k=(a+1)/2;
	if(a%2==0)
	{
		return k;
	}
	else
	{
		return -k;
	}
}

int main()
{
	long long t,n,l,r,z;
	
	scanf("%lld",&t);
	for(n=0;n<t;n++)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",f(r)-f(l-1));
	}
}