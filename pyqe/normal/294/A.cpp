#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		a[k-1]+=l-1;
		a[k+1]+=a[k]-l;
		a[k]=0;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld\n",a[i]);
	}
}