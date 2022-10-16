#include <bits/stdc++.h>

using namespace std;

long long a[3];

long long ln(long long x)
{
	long long c=0;
	
	for(;x;x/=10,c++);
	return c;
}

int main()
{
	long long t,rr,i,z[3];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",a+i);
		}
		for(z[2]=1;ln(z[2])<a[2];z[2]*=10);
		for(i=0;i<2;i++)
		{
			for(z[i]=z[2];ln(z[i])<a[i];z[i]*=i+2);
		}
		printf("%lld %lld\n",z[0],z[1]);
	}
}