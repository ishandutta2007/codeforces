#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069];

int main()
{
	long long i,k,l,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		z+=min(a[k],a[l]);
	}
	printf("%lld\n",z);
}