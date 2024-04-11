#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[200069];
map<long long,long long> fq[2];

int main()
{
	long long i,k,l,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		fq[0][k]++;
		fq[1][l]+=l!=k;
		a[i*2-1]=k;
		a[i*2]=l;
	}
	for(i=1;i<=n*2;i++)
	{
		if((fq[0][a[i]]+fq[1][a[i]])*2>=n)
		{
			z=min(z,max((n+1)/2-fq[0][a[i]],0ll));
		}
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}