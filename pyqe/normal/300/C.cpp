#include <bits/stdc++.h>

using namespace std;

long long n,a[2],fc[1000069],ifc[1000069],pwk,dv=1e9+7;

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
	long long i,k,sm,z=0;
	bool bad;
	
	scanf("%lld%lld%lld",a,a+1,&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=0;i<=n;i++)
	{
		bad=0;
		for(sm=a[0]*i+a[1]*(n-i);sm;sm/=10)
		{
			k=sm%10;
			bad|=k!=a[0]&&k!=a[1];
		}
		z=(z+cb(n,i)*!bad)%dv;
	}
	printf("%lld\n",z);
}