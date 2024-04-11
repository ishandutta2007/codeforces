#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,d,fc[100069],ifc[100069],pwk;

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

inline long long cb(long long x,long long y)
{
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&d);
	fc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	ifc[n]=pw(fc[n],dv-2);
	for(i=n;i;i--)
	{
		ifc[i-1]=ifc[i]*i%dv;
	}
	for(i=0;i<=min(d,n);i++)
	{
		z=(z+cb(n,i))%dv;
	}
	printf("%lld\n",z);
}