#include <bits/stdc++.h>

using namespace std;

long long n,d,ub[100069],sq[100069];

int main()
{
	long long i,w;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",sq+i,ub+i);
		d-=sq[i];
	}
	if(d<0)
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		w=min(d,ub[i]-sq[i]);
		d-=w;
		sq[i]+=w;
	}
	if(d)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}