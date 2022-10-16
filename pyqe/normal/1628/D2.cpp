#include <bits/stdc++.h>

using namespace std;

const long long ma=1e6,dv=1e9+7;
long long n,m,d,fc[1000069],ifc[1000069],pwk;

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
	long long t,rr,i,z;
	
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=ma;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		z=0;
		for(i=1;i<=m;i++)
		{
			z=(z+i*cb(n,m-i))%dv;
		}
		z=z*pw(pw(2,n-1),dv-2)%dv*d%dv;
		printf("%lld\n",z);
	}
}