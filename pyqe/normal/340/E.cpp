#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[100069],fc[100069],ifc[100069],pwk,dv=1e9+7;
bitset<100069> vtd;

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
	long long i,u=1,z=0;
	
	scanf("%lld",&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(a[i]!=-1)
		{
			vtd[a[i]]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		m+=!vtd[i];
		d+=!vtd[i]&&a[i]==-1;
	}
	for(i=0;i<=d;i++)
	{
		z=(z+cb(d,i)*fc[m-i]%dv*u)%dv;
		u=u*(dv-1)%dv;
	}
	printf("%lld\n",z);
}