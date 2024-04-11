#include <bits/stdc++.h>

using namespace std;

long long n,d,dg[100069];

int main()
{
	long long i,k,l,c=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		dg[k]++;
		dg[l]++;
	}
	for(i=1;i<=n;i++)
	{
		c+=dg[i]==1;
	}
	printf("%.18lf\n",(double)d*2/c);
}