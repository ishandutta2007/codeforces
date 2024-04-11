#include <bits/stdc++.h>

using namespace std;

long long n,d,fc[200069],ifc[200069],pwk,dv=998244353;

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
	long long i,z=0;
	
	scanf("%lld%lld",&n,&d);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	if(d<=n)
	{
		for(i=0;i<=n-d;i++)
		{
			z=(pw(i,n)*cb(n-d,i)+dv-z)%dv;
		}
		z=z*cb(n,n-d)%dv;
	}
	z=z*(1+!!d)%dv;
	printf("%lld\n",z);
}