#include <bits/stdc++.h>

using namespace std;

long long m[2],k[2],n,rm,mn,mx;

int main()
{
	long long it;
	
	scanf("%lld%lld%lld%lld%lld",m,m+1,k,k+1,&n);
	rm=n-(k[0]-1)*m[0]-(k[1]-1)*m[1];
	mn=min(max((long long)0,rm),m[0]+m[1]);
	if(k[1]<k[0])
	{
		it=1;
	}
	else
	{
		it=0;
	}
	if(n>m[it]*k[it])
	{
		n-=m[it]*k[it];
		mx=m[it]+n/k[!it];
	}
	else
	{
		mx=n/k[it];
	}
	printf("%lld %lld\n",mn,mx);
}