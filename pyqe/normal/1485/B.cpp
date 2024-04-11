#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069];

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld%lld%lld",&n,&t,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",m+a[l]-a[k]+1-(l-k+1)*2);
	}
}