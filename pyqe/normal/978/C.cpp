#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,k,sm=0;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1,rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		for(;i<=n&&sm+a[i]<k;i++)
		{
			sm+=a[i];
		}
		printf("%lld %lld\n",i,k-sm);
	}
}