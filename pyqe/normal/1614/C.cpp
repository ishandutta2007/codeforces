#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,m,pwk;

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
	long long t,rr,i,k,l,w,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		sm=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			sm|=w;
		}
		printf("%lld\n",sm*pw(2,n-1)%dv);
	}
}