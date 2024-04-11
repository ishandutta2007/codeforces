#include <bits/stdc++.h>

using namespace std;

long long n,m,d,ma=2e5,fc[200069],ifc[200069],a[200069],pwk,dv=1e9+7;

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
	if(x<y)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long t,rr,i,j,z;
	
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
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		z=0;
		for(j=1,i=1;i<=n;i++)
		{
			for(;a[j]<a[i]-d;j++);
			z=(z+cb(i-j,m-1))%dv;
		}
		printf("%lld\n",z);
	}
}