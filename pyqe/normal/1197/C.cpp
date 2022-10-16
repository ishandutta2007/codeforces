#include <bits/stdc++.h>

using namespace std;

long long n,d,as[300069];

int main()
{
	long long i,k,l=0,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(l)
		{
			as[i-1]=k-l;
		}
		l=k;
	}
	sort(as+1,as+n);
	for(i=1;i<=n-d;i++)
	{
		z+=as[i];
	}
	printf("%lld\n",z);
}