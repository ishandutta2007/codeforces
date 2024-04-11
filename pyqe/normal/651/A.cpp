#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,k,d,z;
	
	scanf("%lld%lld",&a,&b);
	d=abs(a-b);
	k=a+b;
	if(a==1&&b==1)
	{
		z=0;
	}
	else if(d%3==0)
	{
		z=k-3;
	}
	else
	{
		z=k-2;
	}
	printf("%lld\n",z);
}