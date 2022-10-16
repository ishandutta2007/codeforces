#include <bits/stdc++.h>

using namespace std;

long long n,d;

long long tri(long long x)
{
	return x*(x+1)/2;
}

long long val(long long x)
{
	if(x<0)
	{
		return 0;
	}
	return x*x;
}

long long val2(long long x)
{
	if(x<0)
	{
		return 0;
	}
	return tri(x);
}

int main()
{
	long long i,y,x,sm,lh,rh,md,zz;
	
	scanf("%lld%lld%lld%lld",&n,&y,&x,&d);
	for(lh=0,rh=n*2;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=tri(md)*4+1;
		for(i=0;i<4;i++)
		{
			sm-=val(md-(y-1))-val2(md-(y+x-1));
			y=(n+1-y);
			swap(y,x);
		}
		if(sm>=d)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}