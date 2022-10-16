#include <bits/stdc++.h>

using namespace std;

const long long ub=2e9;

inline long long val(long long x)
{
	long long lh,rh,md,zz;
	
	for(lh=1,rh=ub;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(md*md>=x)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	return zz;
}

inline long long val2(long long x)
{
	long long k=val(x+1)-1;
	
	return k*3-2+(k*k+k<=x)+(k*k+k*2<=x);
}

int main()
{
	long long t,rr,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=val2(l)-val2(k-1);
		printf("%lld\n",z);
	}
}