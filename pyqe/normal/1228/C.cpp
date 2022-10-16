#include <bits/stdc++.h>

using namespace std;

long long n,m,pwk,dv=1e9+7,z=1;

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

void slv(long long x)
{
	long long k=0,kk=m;
	
	for(;kk>0;kk/=x)
	{
		k+=kk/x;
	}
	z=z*pw(x,k)%dv;
}

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&m);
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			for(;n%i==0;n/=i);
			slv(i);
		}
	}
	if(n>1)
	{
		slv(n);
	}
	printf("%lld\n",z);
}