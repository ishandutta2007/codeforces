#include <bits/stdc++.h>

using namespace std;

long long n,a[2069];

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n*2;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n*2+1);
	if(a[1]==a[n*2])
	{
		printf("-1\n");
	}
	else
	{
		for(i=1;i<=n*2;i++)
		{
			printf("%lld%c",a[i]," \n"[i==n*2]);
		}
	}
}