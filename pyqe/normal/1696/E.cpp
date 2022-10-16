#include <bits/stdc++.h>

using namespace std;

const long long ma=4e5,dv=1e9+7;
long long n,fc[400069],ifc[400069],pwk;

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
	if(x<y||y<0)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,k,z=0;
	
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=ma;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		scanf("%lld",&k);
		z=(z+cb(k+i,i+1))%dv;
	}
	printf("%lld\n",z);
}