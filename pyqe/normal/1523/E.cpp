#include <bits/stdc++.h>

using namespace std;

const long long ma=1e5,dv=1e9+7;
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

long long cb2(long long x,long long y)
{
	return fc[x]*ifc[x-y]%dv;
}

int main()
{
	long long t,rr,i,w,z;
	
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
		scanf("%lld%lld",&n,&d);
		z=0;
		for(i=1;i<=(n-1)/d+1;i++)
		{
			w=cb2(n-(d-1)*(i-1),i);
			z=(z+w*((n-i)*(i+1)%dv*fc[n-i-1]%dv+dv-i*fc[n-i]*(i>1)%dv))%dv;
		}
		printf("%lld\n",z*ifc[n]%dv);
	}
}