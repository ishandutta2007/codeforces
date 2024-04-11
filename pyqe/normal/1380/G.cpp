#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],ps[300069],pwk,dv=998244353;

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
	long long i,j,dn,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i];
	}
	dn=pw(n,dv-2);
	for(i=1;i<=n;i++)
	{
		z=0;
		for(j=n-i;j>0;j-=i)
		{
			z=(z+ps[j])%dv;
		}
		z=z*dn%dv;
		printf("%lld%c",z," \n"[i==n]);
	}
}