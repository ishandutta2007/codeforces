#include <bits/stdc++.h>

using namespace std;

long long n,dv=1e9+7;

int main()
{
	long long k,l,z;
	
	scanf("%lld%lld%lld",&k,&l,&n);
	k=(k+dv)%dv;
	l=(l+dv)%dv;
	if(n%6==1)
	{
		z=k;
	}
	else if(n%6==2)
	{
		z=l;
	}
	else if(n%6==3)
	{
		z=(l+dv-k)%dv;
	}
	else if(n%6==4)
	{
		z=(dv-k)%dv;
	}
	else if(n%6==5)
	{
		z=(dv-l)%dv;
	}
	else
	{
		z=(k+dv-l)%dv;
	}
	printf("%lld\n",z);
}