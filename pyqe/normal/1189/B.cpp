#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	if(a[n]<a[n-1]+a[n-2])
	{
		printf("YES\n");
		swap(a[n-1],a[n]);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
	else
	{
		printf("NO\n");
	}
}