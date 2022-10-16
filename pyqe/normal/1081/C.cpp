#include <bits/stdc++.h>

using namespace std;

long long n,m,d,fc[100069],pwk,dv=998244353;

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
	
	scanf("%lld%lld%lld",&n,&m,&d);
	fc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	printf("%lld\n",cb(n-1,d)*m%dv*pw(m-1,d)%dv);
}