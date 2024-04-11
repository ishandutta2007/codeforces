#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],ps[100069],sq[100069];

int main()
{
	long long t,rr,i,j,k,sm;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,greater<long long>());
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i];
	}
	for(i=1;i<=100000;i++)
	{
		sm=0;
		k=1;
		for(j=0;sm<n;j++)
		{
			sq[i]+=(ps[min(sm+k,n)]-ps[sm])*j;
			sm+=k;
			k*=i;
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld%c",sq[k]," \n"[rr==t-1]);
	}
}