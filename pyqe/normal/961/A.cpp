#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,fq[100069];

int main()
{
	long long i,k,z=inf;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=1;i<=n;i++)
	{
		z=min(z,fq[i]);
	}
	printf("%lld\n",z);
}