#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		d-=k+(i>1);
	}
	if(!d)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}