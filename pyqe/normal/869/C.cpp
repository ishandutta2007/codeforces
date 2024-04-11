#include <bits/stdc++.h>

using namespace std;

long long n[3],fc[100069],ifc[100069],pwk,dv=998244353;

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
	long long i,j,sm,z=1;
	
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=100000;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=0;i<3;i++)
	{
		scanf("%lld",n+i);
	}
	for(i=0;i<3;i++)
	{
		sm=0;
		for(j=0;j<=min(n[i],n[(i+1)%3]);j++)
		{
			sm=(sm+cb(n[i],j)*fc[n[(i+1)%3]]%dv*ifc[n[(i+1)%3]-j])%dv;
		}
		z=z*sm%dv;
	}
	printf("%lld\n",z);
}