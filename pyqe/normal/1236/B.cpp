#include <bits/stdc++.h>

using namespace std;

long long pwk,dv=1e9+7;

long long pw(long long x,long long y)
{
	if(y==0)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2==1)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long n,m;
	
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",pw((pw(2,m)+dv-1)%dv,n));
}