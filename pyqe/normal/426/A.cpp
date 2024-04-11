#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k,mx=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		d-=k;
		mx=max(mx,k);
	}
	d+=mx;
	if(d>=0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}