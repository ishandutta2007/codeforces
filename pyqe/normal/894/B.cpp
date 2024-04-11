#include <bits/stdc++.h>

using namespace std;

long long n,m,d,pwk,dv=1e9+7;

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
	long long z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	if(d==-1&&n%2!=m%2)
	{
		z=0;
	}
	else
	{
		z=pw(pw(2,n-1),m-1);
	}
	printf("%lld\n",z);
}