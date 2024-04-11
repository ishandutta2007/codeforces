#include <bits/stdc++.h>

using namespace std;

long long n,pwk,dv=1e9+7;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,z=1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		z=z*i%dv;
	}
	printf("%lld\n",(z+dv-pw(2,n-1))%dv);
}