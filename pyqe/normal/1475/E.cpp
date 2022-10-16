#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=1e5,fc[100069],ifc[100069],a[100069],pwk,dv=1e9+7;

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
	long long t,rr,i,lb,rb;
	
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
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		d=n+1-d;
		lb=lower_bound(a+1,a+n+1,a[d])-a;
		rb=upper_bound(a+1,a+n+1,a[d])-a;
		printf("%lld\n",cb(rb-lb,rb-d));
	}
}