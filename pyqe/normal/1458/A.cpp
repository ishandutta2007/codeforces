#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],inf=1e18;

int main()
{
	long long t,rr,i,k,mn=inf,gd=0;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		mn=min(mn,a[i]);
	}
	for(i=1;i<=n;i++)
	{
		gd=__gcd(gd,a[i]-mn);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld%c",__gcd(mn+k,gd)," \n"[rr==t-1]);
	}
}