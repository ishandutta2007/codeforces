#include <bits/stdc++.h>

using namespace std;

long long n,fc[300069],ifc[300069],a[300069],pwk,dv=998244353;

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
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,u,z=0;
	
	scanf("%lld",&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n*2;i++)
	{
		scanf("%lld",a+i);
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	sort(a+1,a+n*2+1);
	for(i=1;i<=n*2;i++)
	{
		u=(i>n)*2-1;
		z=(z+dv+a[i]*u)%dv;
	}
	printf("%lld\n",z*cb(n*2,n)%dv);
}