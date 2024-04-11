#include <bits/stdc++.h>

using namespace std;

long long n,pwk,dv;

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
	long long i;
	
	scanf("%lld%lld",&n,&dv);
	printf("%lld\n",(pw(3,n)+dv-1)%dv);
}