#include <bits/stdc++.h>

using namespace std;

long long n,m,pwk,dv=1e9+7;

long long pw(long long x,long long y)
{
	if(!y||x==1)
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
	
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",m*pw(m,m-2)%dv*pw(n-m,n-m)%dv);
}