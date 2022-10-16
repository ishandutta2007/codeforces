#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,pwk;

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
	scanf("%lld",&n);
	printf("%lld\n",(pw(3,n*3)+dv-pw(7,n))%dv);
}