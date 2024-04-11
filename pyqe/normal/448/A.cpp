#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a=0,b=0,k,z,n,i;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",&k);
		a+=k;
	}
	for(i=0;i<3;i++)
	{
		scanf("%lld",&k);
		b+=k;
	}
	scanf("%lld",&n);
	if(a>0)
	{
		a=(a-1)/5+1;
	}
	if(b>0)
	{
		b=(b-1)/10+1;
	}
	z=a+b;
	if(z<=n)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}