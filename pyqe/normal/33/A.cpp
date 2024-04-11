#include <bits/stdc++.h>

using namespace std;

long long n,m,d,mn[1069];

int main()
{
	long long i,k,l,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		mn[i]=1e18;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		mn[k]=min(mn[k],l);
	}
	for(i=1;i<=m;i++)
	{
		z+=mn[i];
	}
	printf("%lld\n",min(z,d));
}