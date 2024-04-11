#include <iostream>
#include <stdio.h>
long long inverz(long long s,long long k)
{
	long long u;
	if(k==0) return 1;
	if(k%2==0) 
	{
		u=inverz(s,k/2);
		return (u*u)%1000003;
	}
	else
	{
		u=inverz(s,k/2);
		return (u*u*s)%1000003;
	}
}
int main(int argc, char** argv) 
{
	long long n,k,r=1;
	scanf("%I64d%I64d",&n,&k);
	for(int i=0;i<k;i++) 
	{
		r=(((r*(n+k-i))%1000003)*inverz(i+1,1000001))%1000003;
	}
	r--;
	printf("%I64d",r);
	return 0;
}