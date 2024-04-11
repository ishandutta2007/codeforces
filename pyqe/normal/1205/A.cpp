#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	if(n%2==0)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld ",i*2-i%2);
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",i*2-(i+1)%2," \n"[i==n]);
		}
	}
}