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
	long long k;
	
	scanf("%lld",&n);
	k=pw(2,n);
	printf("%lld\n",k*(k+1)%dv*pw(2,dv-2)%dv);
}