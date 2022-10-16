#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,d,pwk;

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
	long long t,rr,i,ml,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		ml=1;
		z=0;
		for(i=d-1;i+1;i--)
		{
			z=(z+ml*(n%2==0)*pw(2,i*n))%dv;
			ml=ml*(pw(2,n-1)+dv-(n%2==0)+n%2)%dv;
		}
		z=(z+ml)%dv;
		printf("%lld\n",z);
	}
}