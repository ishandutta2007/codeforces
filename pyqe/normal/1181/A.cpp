#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long x,y,z,d,xx,yy,k=0;
	
	scanf("%lld%lld%lld",&x,&y,&z);
	d=(x+y)/z;
	xx=x%z;
	yy=y%z;
	if(xx<yy)
	{
		swap(xx,yy);
	}
	if(z-xx<=yy)
	{
		k=z-xx;
	}
	printf("%lld %lld\n",d,k);
}