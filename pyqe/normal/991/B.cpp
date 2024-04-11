#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,sm=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
	}
	sort(a+1,a+n+1);
	for(i=0;sm*2<n*9;)
	{
		i++;
		sm+=5-a[i];
	}
	printf("%lld\n",i);
}