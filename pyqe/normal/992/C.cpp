#include <bits/stdc++.h>

using namespace std;

long long n,d,pwk,dv=1e9+7;

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
	
	scanf("%lld%lld",&n,&d);
	printf("%lld\n",(n%dv*pw(2,d+1)+dv-(pw(2,d)+dv-1)%dv)%dv*!!n);
}