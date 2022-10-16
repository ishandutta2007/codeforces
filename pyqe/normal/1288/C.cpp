#include <bits/stdc++.h>

using namespace std;

long long n,m,pwk,fc[100069],dv=1e9+7;

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

long long cb(long long x,long long y)
{
	return fc[x]*pw(fc[y]*fc[x-y]%dv,dv-2)%dv;
}

int main()
{
	long long i;
	
	fc[0]=1;
	for(i=1;i<=100000;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",cb(m*2+n-1,m*2));
}