#include <bits/stdc++.h>

using namespace std;

long long n,pwk,dv=998244353;

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
	long long i,k,l=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		z=(z+(k-l)*(n+1-i)%dv*pw(2,n-i))%dv;
		l=k;
	}
	printf("%lld\n",z);
}