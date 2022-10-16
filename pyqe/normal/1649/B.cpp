#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			sm+=a[i];
		}
		sort(a+1,a+n+1,greater<long long>());
		sm-=a[1];
		printf("%lld\n",max(a[1]-sm,1ll)*!!a[1]);
	}
}