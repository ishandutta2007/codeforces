#include <bits/stdc++.h>

using namespace std;

long long n,m;

long long val(long long ky,long long y,long long x)
{
	if(ky)
	{
		return y*x-val(0,y,x);
	}
	return y/2*2*(x/2*2)/2+x/2*(y%2)+y/2*(x%2);
}

long long val2(long long ky,long long y,long long x,long long y2,long long x2)
{
	if(y>y2||x>x2)
	{
		return 0;
	}
	return val(ky,y2,x2)-val(ky,y-1,x2)-val(ky,y2,x-1)+val(ky,y-1,x-1);
}

int main()
{
	long long t,rr,y,x,y2,x2,y3,x3,y4,x4,z,z2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&m,&n,&y,&x,&y2,&x2,&y3,&x3,&y4,&x4);
		z=val(1,n,m)+val2(0,y,x,y2,x2)-val2(1,y3,x3,y4,x4)-val2(0,max(y,y3),max(x,x3),min(y2,y4),min(x2,x4));
		z2=val(0,n,m)+val2(1,y3,x3,y4,x4)-val2(0,y,x,y2,x2)+val2(0,max(y,y3),max(x,x3),min(y2,y4),min(x2,x4));
		printf("%lld %lld\n",z,z2);
	}
}