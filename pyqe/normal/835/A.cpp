#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,v[2],t[2],ii,z[2];
	
	scanf("%lld%lld%lld%lld%lld",&n,v,v+1,t,t+1);
	for(ii=0;ii<2;ii++)
	{
		z[ii]=t[ii]*2+v[ii]*n;
	}
	if(z[0]<z[1])
	{
		printf("First\n");
	}
	else if(z[1]<z[0])
	{
		printf("Second\n");
	}
	else
	{
		printf("Friendship\n");
	}
}