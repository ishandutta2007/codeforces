#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],fc[200069],ifc[200069],pwk,dv=1e9+7;

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
	bool bad;
	
	scanf("%lld",&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	if(n==1)
	{
		printf("%lld\n",a[1]);
		return 0;
	}
	if(n%2)
	{
		n--;
		for(i=1;i<=n;i++)
		{
			u=(i%2)*2-1;
			a[i]=(a[i]+dv+a[i+1]*u)%dv;
		}
	}
	bad=n%4==0;
	for(i=1;i<=n;i++)
	{
		u=(!bad||i%2)*2-1;
		z=(z+dv+a[i]*cb(n/2-1,(i-1)/2)%dv*u)%dv;
	}
	printf("%lld\n",z);
}