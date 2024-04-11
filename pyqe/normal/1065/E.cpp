#include <bits/stdc++.h>

using namespace std;

long long ln,n,d,pwk,dv=998244353;

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
	long long i,k,l=0,w,z=1,iv=pw(2,dv-2);
	
	scanf("%lld%lld%lld",&ln,&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		w=pw(d,k-l);
		z=z*((w*w%dv+dv-w)*iv%dv+w)%dv;
		l=k;
	}
	z=z*pw(d,ln-k*2)%dv;
	printf("%lld\n",z);
}