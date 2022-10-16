#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		z=upper_bound(a+1,a+n+1,k)-a-1;
		printf("%lld%c",z," \n"[rr==t-1]);
	}
}