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
	printf("%lld\n",a[(n+1)/2]);
}