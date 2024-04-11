#include <bits/stdc++.h>

using namespace std;

long long n,m,d,fc[100069],ifc[100069],pwk,dv=1e9+7;

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
	if(x<y||y<0)
	{
		return 0;
	}
	return fc[x]*ifc[x-y]%dv;
}

int main()
{
	long long i,lh,rh,md,c[2]={0,0};
	
	scanf("%lld%lld%lld",&n,&m,&d);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(lh=0,rh=n;lh<rh;)
	{
		md=(lh+rh)/2;
		if(md<=d)
		{
			c[0]++;
			lh=md+1;
		}
		else
		{
			c[1]++;
			rh=md;
		}
	}
	printf("%lld\n",cb(m-1,c[0]-1)*cb(n-m,c[1])%dv*fc[n-c[0]-c[1]]%dv);
}