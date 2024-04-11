#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long cr,lb,rb,z;
	
	scanf("%lld%lld%lld%lld",&n,&cr,&lb,&rb);
	if(lb==1&&rb==n)
	{
		z=0;
	}
	else if(lb==1)
	{
		z=abs(cr-rb)+1;
	}
	else if(rb==n)
	{
		z=abs(cr-lb)+1;
	}
	else
	{
		z=min(abs(cr-lb),abs(cr-rb))+1+rb-lb+1;
	}
	printf("%lld\n",z);
}