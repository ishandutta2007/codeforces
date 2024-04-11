#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],as[100069];

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		as[i]=a[i];
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",as[(lower_bound(as+1,as+n+1,a[i])-as)%n+1]," \n"[i==n]);
	}
}