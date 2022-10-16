#include <bits/stdc++.h>

using namespace std;

long long n,d,a[2069];

int main()
{
	long long i;
	
	scanf("%lld%lld%lld",&n,&d,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	printf("%lld\n",a[d+1]-a[d]);
}