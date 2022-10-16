#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	for(i=0;i<n-2;i++)
	{
		if(a[i]+a[i+1]>a[i+2])
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}