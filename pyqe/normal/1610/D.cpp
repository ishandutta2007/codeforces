#include <bits/stdc++.h>

using namespace std;

const long long mm=30,dv=1e9+7;
long long n,fq[mm],pwk;

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
	long long i,k,c,sm=0,z;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(c=0;k%2==0;k/=2,c++);
		fq[c]++;
	}
	z=(pw(2,n)+dv-1)%dv;
	for(i=mm-1;i;i--)
	{
		if(fq[i])
		{
			z=(z+dv-pw(2,fq[i]+sm-1))%dv;
		}
		sm+=fq[i];
	}
	printf("%lld\n",z);
}